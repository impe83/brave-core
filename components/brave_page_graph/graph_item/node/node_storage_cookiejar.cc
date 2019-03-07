/* Copyright (c) 2019 The Brave Software Team. Distributed under the MPL2
 * license. This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "brave/components/brave_page_graph/graph_item/node/node_storage_cookiejar.h"
#include <string>
#include "brave/components/brave_page_graph/graph_item/node/node_storage.h"
#include "brave/components/brave_page_graph/graph_item/node.h"
#include "brave/components/brave_page_graph/types.h"

using ::std::string;

namespace brave_page_graph {

NodeStorageCookieJar::NodeStorageCookieJar(const PageGraphId id) :
    NodeStorage(id) {}

string NodeStorageCookieJar::ItemName() const {
  return "NodeStorageCookieJar#" + id_;
}

}  // brave_page_graph