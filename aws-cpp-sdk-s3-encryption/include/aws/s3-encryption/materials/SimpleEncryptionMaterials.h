/*
* Copyright 2010-2016 Amazon.com, Inc. or its affiliates. All Rights Reserved.
*
* Licensed under the Apache License, Version 2.0 (the "License").
* You may not use this file except in compliance with the License.
* A copy of the License is located at
*
*  http://aws.amazon.com/apache2.0
*
* or in the "license" file accompanying this file. This file is distributed
* on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
* express or implied. See the License for the specific language governing
* permissions and limitations under the License.
*/
#pragma once
#include <aws/s3-encryption/materials/EncryptionMaterials.h>

namespace Aws
{
    namespace S3Encryption
    {
        namespace Materials
        {
            static const char* SimpleEncryptionMaterials_Tag = "SimpleEncryptionMaterials";

            /*
            * Simple Encryption Materials is responsible for handling the encryption/decryption of
            * content encryption keys. This class will use a user provided symmetric
            * master key to encrypt/decrypt keys with AES Key Wrap.
            */
            class AWS_S3ENCRYPTION_API SimpleEncryptionMaterials : public EncryptionMaterials 
            {
            public:
                /*
                Initialize with symmetric key.
                */
                SimpleEncryptionMaterials(const Aws::Utils::CryptoBuffer& symmetricKey);

                /*
                * This will encrypt the cek within the Content Crypto material and KeyWrapAlgorithm within the Content Crypto Material.
                * This will occur in place and will directly manipulate the content crypto material passed to it.
                */
                void EncryptCEK(Aws::S3Encryption::ContentCryptoMaterial& contentCryptoMaterial) override;

                /*
                * This will decrypt the cek with the symmetric master key.
                * This will occur in place and will directly manipulate the content crypto material passed to it.
                */
                void DecryptCEK(Aws::S3Encryption::ContentCryptoMaterial& contentCryptoMaterial) override;

            private:
                Aws::Utils::CryptoBuffer m_symmetricMasterKey;
            };
        }//namespace Materials
    }//namespace S3Encryption
}//namespace Aws