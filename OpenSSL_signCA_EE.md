# How to generate one self-signed CA and sign EndEntity Certificate

## A ca.conf is very import for openssl to load configurations

```
[ ca ]
default_ca = myca

[ crl_ext ]
issuerAltName=issuer:copy
authorityKeyIdentifier=keyid:always

 [ myca ]
 dir = ./
 new_certs_dir = $dir
 unique_subject = no
 certificate = $dir/rootca.crt
 database = $dir/certindex
 private_key = $dir/rootca.key
 serial = $dir/certserial
 default_days = 730
 default_md = sha256
 policy = myca_policy
 crlnumber = $dir/crlnumber
 default_crl_days = 730

 [ myca_policy ]
 commonName = supplied
 stateOrProvinceName = optional
 countryName = optional
 emailAddress = optional
 organizationName = supplied
 organizationalUnitName = optional

 [ myca_extensions ]
 basicConstraints = critical,CA:TRUE, pathlen:1
 subjectKeyIdentifier = hash
 authorityKeyIdentifier = keyid:always,issuer
 keyUsage = critical,digitalSignature,keyEncipherment,cRLSign,keyCertSign
 extendedKeyUsage = serverAuth

[ req ]
# Options for the `req` tool (`man req`).
default_bits        = 2048
string_mask         = utf8only
distinguished_name  = req_distinguished_name

# SHA-1 is deprecated, so use SHA-2 instead.
default_md          = sha256

# Extension to add when the -x509 option is used.
x509_extensions     = v3_ca

[ req_distinguished_name ]
# See <https://en.wikipedia.org/wiki/Certificate_signing_request>.
#countryName                     = Country Name (2 letter code)
#stateOrProvinceName             = State or Province Name
#localityName                    = Locality Name
0.organizationName              = Organization Name
organizationalUnitName          = Organizational Unit Name
commonName                      = Common Name
#emailAddress                    = Email Address

[ v3_ca ]
# Extensions for a typical CA (`man x509v3_config`).
subjectKeyIdentifier = hash
authorityKeyIdentifier = keyid:always,issuer
basicConstraints = critical,CA:TRUE, pathlen:4
keyUsage = critical, digitalSignature, cRLSign, keyCertSign, nonRepudiation, keyEncipherment, dataEncipherment, keyAgreement
extendedKeyUsage = serverAuth

[user_cert]
basicConstraints = CA:FALSE
subjectKeyIdentifier = hash
authorityKeyIdentifier = keyid:always,issuer
keyUsage = critical, digitalSignature, cRLSign, keyCertSign, nonRepudiation, keyEncipherment, keyAgreement
extendedKeyUsage = critical, clientAuth, serverAuth

```

## Sign the root certificate

### Generate the root CA key pair
```
openssl genrsa -aes256 -out rootca.key 4096
```

You should provide the passpharse/passwd for this private.key

### Create a root certificate

```
openssl req -config ca.conf -key rootca.key -new -x509 -days 36500 -sha256 -extensions v3_ca -out rootca.crt
```

### provide database files

```
echo 1000 > certserial
echo 1000 > crlnumber
```

## sign the ee certificate

```
mkdir eeCert
cd eeCert/

openssl genrsa -out eeCert.key 2048
openssl req -new -sha256 -key eeCert/eeCert.key -out eeCert/eecert.csr

```

Sign the certificate
```
openssl ca -batch -config ca.conf -days 36500 -notext -in eeCert/eecert.csr -out eeCert/eecert.crt
```

## REFs
- https://raymii.org/s/tutorials/OpenSSL_command_line_Root_and_Intermediate_CA_including_OCSP_CRL%20and_revocation.html
- https://jamielinux.com/docs/openssl-certificate-authority/


## Note
verify certificate and key match
openssl x509 -noout -modulus -in server_cert.pem | openssl md5
openssl rsa -noout -modulus -in server_key.pem| openssl md5
