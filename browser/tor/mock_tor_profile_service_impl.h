/* Copyright (c) 2019 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef BRAVE_BROWSER_TOR_MOCK_TOR_PROFILE_SERVICE_IMPL_H_
#define BRAVE_BROWSER_TOR_MOCK_TOR_PROFILE_SERVICE_IMPL_H_

#include "brave/browser/tor/tor_profile_service.h"

class Profile;

namespace tor {

class MockTorProfileServiceImpl : public TorProfileService {
 public:
  explicit MockTorProfileServiceImpl(Profile* profile);
  ~MockTorProfileServiceImpl() override;

  // TorProfileService:
  void LaunchTor(const TorConfig&) override;
  void ReLaunchTor(const TorConfig&) override;
  void SetNewTorCircuit(const GURL& request_url, const base::Closure&) override;
  const TorConfig& GetTorConfig() override;
  int64_t GetTorPid() override;

  int SetProxy(net::ProxyResolutionService*,
               const GURL& request_url,
               bool new_circuit) override;

 private:
  Profile* profile_;  // NOT OWNED
  TorConfig config_;
  DISALLOW_COPY_AND_ASSIGN(MockTorProfileServiceImpl);
};

}  // namespace tor

#endif  // BRAVE_BROWSER_TOR_MOCK_TOR_PROFILE_SERVICE_IMPL_H_
