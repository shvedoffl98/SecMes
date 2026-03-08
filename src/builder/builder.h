#pragma once


#include <vector>


class MessageBuilderProvider
{
public:
    template <typename MSG_TYPE>
    static std::vector<std::byte> build(MSG_TYPE msg)
    {
        using ret_val_t = std::invoke_result_t<decltype(build<MSG_TYPE>), MSG_TYPE>;
        ret_val_t ret_val {};
        _build_header(msg, /*OUT*/ret_val);
        _build_parser(msg, /*OUT*/ret_val);
        return ret_val;
    }

    template <typename MSG_TYPE>
    static bool _build_header(MSG_TYPE msg, std::vector<std::byte>&);

    template <typename MSG_TYPE>
    static bool _build_payload(MSG_TYPE msg, std::vector<std::byte>&);
};
