// Copyright (C) 2022 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#pragma once

#include "elementwise_binary.cuh"

namespace ov {
namespace nvidia_gpu {
namespace kernel {

template <typename T>
struct AddOpImpl;

/**
 * Performs element-wise addition operation with two given tensors applying
 * broadcasting if needed.
 */
class Add {
public:
    Add(Type_t element_type, size_t out_num_elements, size_t max_threads_per_block);

    void operator()(cudaStream_t stream,
                    const void* in0,
                    const NumpyBroadcastMapper& in0_mapper,
                    const void* in1,
                    const NumpyBroadcastMapper& in1_mapper,
                    void* out) const;

private:
    ElementwiseBinary<AllElementTypesSwitch, AddOpImpl> impl_;
};

}  // namespace kernel
}  // namespace nvidia_gpu
}  // namespace ov
