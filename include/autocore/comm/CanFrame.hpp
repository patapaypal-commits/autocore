#pragma once
#include <cstdint>
#include <string>

namespace autocore::comm {

class CanFrame {
public:
    static constexpr uint8_t MAX_DATA_SIZE = 8;

    CanFrame() = default;
    CanFrame(uint32_t id, uint8_t dlc, const uint8_t* data);

    uint32_t id() const { return id_; }
    uint8_t  dlc() const { return dlc_; }
    const uint8_t* data() const { return data_; }

    std::string toString() const;

private:
    uint32_t id_  = 0;
    uint8_t  dlc_ = 0;
    uint8_t  data_[MAX_DATA_SIZE] = {0};
};

}