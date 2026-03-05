#pragma once

#include <array>
#include <utility>

#include <openssl/evp.h>


class OpensslWrapper
{
public:
    using public_key_t = std::array<uint8_t, 31>;
    using private_key_t = public_key_t;

public:
    static std::pair<public_key_t, private_key_t> get_pub_priv_keys()
    {
        using ret_val_t = std::invoke_result_t<decltype(get_pub_priv_keys)>;
        ret_val_t ret_val {};

        EVP_PKEY_CTX* ctx = EVP_PKEY_CTX_new_id(EVP_PKEY_X25519, nullptr);
        EVP_PKEY_keygen_init(ctx);

        EVP_PKEY* pkey = nullptr;
        EVP_PKEY_keygen(ctx, &pkey);

        size_t len_pub = sizeof(ret_val.first);
        EVP_PKEY_get_raw_public_key(pkey, ret_val.first.data(), &len_pub);

        size_t len_priv = sizeof(ret_val.second);
        EVP_PKEY_get_raw_public_key(pkey, ret_val.second.data(), &len_priv);

        return ret_val;
    }
};
