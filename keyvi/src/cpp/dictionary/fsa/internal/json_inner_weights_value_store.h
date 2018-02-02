/* * keyvi - A key value store.
 *
 * Copyright 2016 Narek Gharibyan<narekgharibyan@gmail.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */


/*
 *  json_inner_weight_value_store.h
 *
 *  Created on: November 21, 2016
 *      Author: Narek Gharibyan <narekgharibyan@gmail.com>
 */


#ifndef KEYVI_JSON_INNER_WEIGHTS_VALUE_STORE_H
#define KEYVI_JSON_INNER_WEIGHTS_VALUE_STORE_H

#include "dictionary/fsa/internal/json_value_store.h"


namespace keyvi {
namespace dictionary {
namespace fsa {
namespace internal {

class JsonInnerWeightsValueStore : public JsonValueStore {
public:
    static const bool inner_weight = true;

    using JsonValueStore::JsonValueStore;

    uint32_t GetWeightValue(const value_t &value) const {
        rapidjson::Document document;
        document.Parse(value.c_str());

        if (!document.HasMember("weight") || !document["weight"].IsInt()) {
            throw std::runtime_error("Json has no numeric field: weight");
        }

        return document["weight"].GetInt();
    }

    uint32_t GetMergeWeight(uint64_t fsa_value) {
        throw std::runtime_error("Json Completion Dictionaries merging is not supported");
    }

    static value_store_t GetValueStoreType() {
        return JSON_INNER_WEIGHTS_VALUE_STORE;
    }
};

class JsonInnerWeightsValueStoreReader : public JsonValueStoreReader {
public:
    using JsonValueStoreReader::JsonValueStoreReader;

    virtual value_store_t GetValueStoreType() const override {
        return JSON_INNER_WEIGHTS_VALUE_STORE;
    }
};

} /* namespace internal */
} /* namespace fsa */
} /* namespace dictionary */
} /* namespace keyvi */

#endif //KEYVI_JSON_INNER_WEIGHTS_VALUE_STORE_H
