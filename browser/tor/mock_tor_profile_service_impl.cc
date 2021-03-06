/* Copyright (c) 2019 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "brave/browser/tor/mock_tor_profile_service_impl.h"

#include <string>

#include "brave/browser/tor/tor_proxy_config_service.h"
#include "brave/common/tor/tor_test_constants.h"
#include "chrome/browser/profiles/profile.h"
#include "content/public/browser/browser_thread.h"
#include "content/public/browser/site_instance.h"

using content::BrowserThread;
using content::SiteInstance;
using tor::TorProxyConfigService;

namespace tor {

MockTorProfileServiceImpl::MockTorProfileServiceImpl(Profile* profile) :
    profile_(profile) {
  base::FilePath path(kTestTorPath);
  std::string proxy(kTestTorProxy);
  config_ = TorConfig(path, proxy);
}

MockTorProfileServiceImpl::~MockTorProfileServiceImpl() {}

void MockTorProfileServiceImpl::LaunchTor(const TorConfig& config) {}

void MockTorProfileServiceImpl::ReLaunchTor(const TorConfig& config) {
  config_ = config;
}


void MockTorProfileServiceImpl::SetNewTorCircuit(const GURL& request_url,
                                             const base::Closure& callback) {}

const TorConfig& MockTorProfileServiceImpl::GetTorConfig() {
  return config_;
}

int64_t MockTorProfileServiceImpl::GetTorPid() { return -1; }

int MockTorProfileServiceImpl::SetProxy(
    net::ProxyResolutionService* service, const GURL& request_url,
    bool new_circuit) {
  DCHECK_CURRENTLY_ON(BrowserThread::IO);
  GURL url = SiteInstance::GetSiteForURL(profile_, request_url);
  if (config_.empty()) {
    // No tor config => we absolutely cannot talk to the network.
    // This might mean that there was a problem trying to initialize
    // Tor.
    LOG(ERROR) << "Tor not configured -- blocking connection";
    return net::ERR_SOCKS_CONNECTION_FAILED;
  }
  TorProxyConfigService::TorSetProxy(service, config_.proxy_string(),
                                     url.host(), nullptr, new_circuit);
  return net::OK;
}

}  // namespace tor
