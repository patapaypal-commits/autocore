#include "autocore/comm/CanFrame.hpp"
#include <cstdio>
#include <cstring>

namespace autocore::comm {

CanFrame::CanFrame(uint32_t id, uint8_t dlc, const uint8_t* data)
    : id_(id), dlc_(dlc) {
    if (dlc_ > MAX_DATA_SIZE) {
        dlc_ = MAX_DATA_SIZE;
    }
    if (data != nullptr) {
        std::memcpy(data_, data, dlc_);
    }
}

std::string CanFrame::toString() const {
    char buffer[128];
    int offset = std::snprintf(buffer, sizeof(buffer),
                               "ID=0x%03X DLC=%u DATA=",
                               id_, dlc_);
    for (uint8_t i = 0; i < dlc_; ++i) {
        offset += std::snprintf(buffer + offset, sizeof(buffer) - offset,
                                "%02X ", data_[i]);
    }
    return std::string(buffer);
}

}