#pragma once

#include <cstddef>
#include <cstdint>
#include <array>
#include <vector>

struct __attribute__((packed)) protocol_header_t
{
    uint8_t magic {};
    uint8_t protocol_version {};
    uint8_t message_type {};
};


struct __attribute__((packed)) message_header_t
{
    std::uint64_t sender_id {};
    std::uint64_t receiver_id {};
    std::uint64_t message_number {};
    std::uint64_t message_count {};

    /**
     * Signature. Should be calculated based on all
     * packet's fields except for signature
    */
    std::array<uint8_t, 64> signature {};
};


struct __attribute__((packed)) message_payload_t
{
    std::vector<uint8_t> cores {};
};
