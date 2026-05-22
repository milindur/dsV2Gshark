/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2022 - 2023 chargebyte GmbH
 * Copyright (C) 2022 - 2023 Contributors to EVerest
 */

/*****************************************************
 *
 * @author
 * @version
 *
 * The Code is generated! Changes may be overwritten.
 *
 *****************************************************/

/**
  * @file iso20_ACDP_Decoder.c
  * @brief Description goes here
  *
  **/
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

#include "exi_basetypes.h"
#include "exi_types_decoder.h"
#include "exi_basetypes_decoder.h"
#include "exi_error_codes.h"
#include "exi_header.h"
#include "iso20_ACDP_Datatypes.h"
#include "iso20_ACDP_Decoder.h"




/* best-effort XML serializer: null/zero-sized buffers disable XML output; 
   non-NUL-terminated input buffers are reset to empty; 
   writes that do not fit are skipped while preserving NUL termination. */
static inline size_t xml_init(char* xmlOut, size_t xmlOut_size) {
    size_t pos = 0u;
    if (xmlOut == NULL || xmlOut_size == 0u) return 0u;
    while (pos < xmlOut_size && xmlOut[pos] != '\0') pos++;
    if (pos == xmlOut_size) { xmlOut[0] = '\0'; return 0u; }
    return pos;
}
static inline void xml_write(char* xmlOut, size_t xmlOut_size, size_t* pos, const char* str, size_t len) {
    size_t remaining;
    if (xmlOut == NULL || pos == NULL || str == NULL || xmlOut_size == 0u) return;
    if (*pos >= xmlOut_size) { *pos = xmlOut_size - 1u; xmlOut[*pos] = '\0'; return; }
    remaining = xmlOut_size - *pos - 1u;
    if (len > remaining) return;
    if (len > 0u) memcpy(xmlOut + *pos, str, len);
    *pos += len;
    xmlOut[*pos] = '\0';
}
static inline void xml_write_escaped(char* xmlOut, size_t xmlOut_size, size_t* pos, const char* str, size_t len, int is_attribute) {
    size_t i;
    if (str == NULL) return;
    for (i = 0u; i < len; i++) {
        switch (str[i]) {
        case '&': xml_write(xmlOut, xmlOut_size, pos, "&amp;", 5u); break;
        case '<': xml_write(xmlOut, xmlOut_size, pos, "&lt;", 4u); break;
        case '>': xml_write(xmlOut, xmlOut_size, pos, "&gt;", 4u); break;
        case '"': if (is_attribute) { xml_write(xmlOut, xmlOut_size, pos, "&quot;", 6u); } else { xml_write(xmlOut, xmlOut_size, pos, &str[i], 1u); } break;
        case '\'': if (is_attribute) { xml_write(xmlOut, xmlOut_size, pos, "&apos;", 6u); } else { xml_write(xmlOut, xmlOut_size, pos, &str[i], 1u); } break;
        default: xml_write(xmlOut, xmlOut_size, pos, &str[i], 1u); break;
        }
    }
}
static inline void xml_write_escaped_text(char* xmlOut, size_t xmlOut_size, size_t* pos, const char* str, size_t len) {
    xml_write_escaped(xmlOut, xmlOut_size, pos, str, len, 0);
}
static inline void xml_write_escaped_attr(char* xmlOut, size_t xmlOut_size, size_t* pos, const char* str, size_t len) {
    xml_write_escaped(xmlOut, xmlOut_size, pos, str, len, 1);
}
static int decode_iso20_acdp_TransformType(exi_bitstream_t* stream, struct iso20_acdp_TransformType* TransformType, char* xmlOut, size_t xmlOut_size, size_t* xmlOut_pos);
static int decode_iso20_acdp_DSAKeyValueType(exi_bitstream_t* stream, struct iso20_acdp_DSAKeyValueType* DSAKeyValueType, char* xmlOut, size_t xmlOut_size, size_t* xmlOut_pos);
static int decode_iso20_acdp_DigestMethodType(exi_bitstream_t* stream, struct iso20_acdp_DigestMethodType* DigestMethodType, char* xmlOut, size_t xmlOut_size, size_t* xmlOut_pos);
static int decode_iso20_acdp_RSAKeyValueType(exi_bitstream_t* stream, struct iso20_acdp_RSAKeyValueType* RSAKeyValueType, char* xmlOut, size_t xmlOut_size, size_t* xmlOut_pos);
static int decode_iso20_acdp_TransformsType(exi_bitstream_t* stream, struct iso20_acdp_TransformsType* TransformsType, char* xmlOut, size_t xmlOut_size, size_t* xmlOut_pos);
static int decode_iso20_acdp_X509IssuerSerialType(exi_bitstream_t* stream, struct iso20_acdp_X509IssuerSerialType* X509IssuerSerialType, char* xmlOut, size_t xmlOut_size, size_t* xmlOut_pos);
static int decode_iso20_acdp_CanonicalizationMethodType(exi_bitstream_t* stream, struct iso20_acdp_CanonicalizationMethodType* CanonicalizationMethodType, char* xmlOut, size_t xmlOut_size, size_t* xmlOut_pos);
static int decode_iso20_acdp_KeyValueType(exi_bitstream_t* stream, struct iso20_acdp_KeyValueType* KeyValueType, char* xmlOut, size_t xmlOut_size, size_t* xmlOut_pos);
static int decode_iso20_acdp_PGPDataType(exi_bitstream_t* stream, struct iso20_acdp_PGPDataType* PGPDataType, char* xmlOut, size_t xmlOut_size, size_t* xmlOut_pos);
static int decode_iso20_acdp_ReferenceType(exi_bitstream_t* stream, struct iso20_acdp_ReferenceType* ReferenceType, char* xmlOut, size_t xmlOut_size, size_t* xmlOut_pos);
static int decode_iso20_acdp_RetrievalMethodType(exi_bitstream_t* stream, struct iso20_acdp_RetrievalMethodType* RetrievalMethodType, char* xmlOut, size_t xmlOut_size, size_t* xmlOut_pos);
static int decode_iso20_acdp_SPKIDataType(exi_bitstream_t* stream, struct iso20_acdp_SPKIDataType* SPKIDataType, char* xmlOut, size_t xmlOut_size, size_t* xmlOut_pos);
static int decode_iso20_acdp_SignatureMethodType(exi_bitstream_t* stream, struct iso20_acdp_SignatureMethodType* SignatureMethodType, char* xmlOut, size_t xmlOut_size, size_t* xmlOut_pos);
static int decode_iso20_acdp_X509DataType(exi_bitstream_t* stream, struct iso20_acdp_X509DataType* X509DataType, char* xmlOut, size_t xmlOut_size, size_t* xmlOut_pos);
static int decode_iso20_acdp_KeyInfoType(exi_bitstream_t* stream, struct iso20_acdp_KeyInfoType* KeyInfoType, char* xmlOut, size_t xmlOut_size, size_t* xmlOut_pos);
static int decode_iso20_acdp_ObjectType(exi_bitstream_t* stream, struct iso20_acdp_ObjectType* ObjectType, char* xmlOut, size_t xmlOut_size, size_t* xmlOut_pos);
static int decode_iso20_acdp_SignatureValueType(exi_bitstream_t* stream, struct iso20_acdp_SignatureValueType* SignatureValueType, char* xmlOut, size_t xmlOut_size, size_t* xmlOut_pos);
static int decode_iso20_acdp_SignedInfoType(exi_bitstream_t* stream, struct iso20_acdp_SignedInfoType* SignedInfoType, char* xmlOut, size_t xmlOut_size, size_t* xmlOut_pos);
static int decode_iso20_acdp_RationalNumberType(exi_bitstream_t* stream, struct iso20_acdp_RationalNumberType* RationalNumberType, char* xmlOut, size_t xmlOut_size, size_t* xmlOut_pos);
static int decode_iso20_acdp_SignatureType(exi_bitstream_t* stream, struct iso20_acdp_SignatureType* SignatureType, char* xmlOut, size_t xmlOut_size, size_t* xmlOut_pos);
static int decode_iso20_acdp_EVTechnicalStatusType(exi_bitstream_t* stream, struct iso20_acdp_EVTechnicalStatusType* EVTechnicalStatusType, char* xmlOut, size_t xmlOut_size, size_t* xmlOut_pos);
static int decode_iso20_acdp_MessageHeaderType(exi_bitstream_t* stream, struct iso20_acdp_MessageHeaderType* MessageHeaderType, char* xmlOut, size_t xmlOut_size, size_t* xmlOut_pos);
static int decode_iso20_acdp_SignaturePropertyType(exi_bitstream_t* stream, struct iso20_acdp_SignaturePropertyType* SignaturePropertyType, char* xmlOut, size_t xmlOut_size, size_t* xmlOut_pos);
static int decode_iso20_acdp_ACDP_ConnectReqType(exi_bitstream_t* stream, struct iso20_acdp_ACDP_ConnectReqType* ACDP_ConnectReqType, char* xmlOut, size_t xmlOut_size, size_t* xmlOut_pos);
static int decode_iso20_acdp_ACDP_ConnectResType(exi_bitstream_t* stream, struct iso20_acdp_ACDP_ConnectResType* ACDP_ConnectResType, char* xmlOut, size_t xmlOut_size, size_t* xmlOut_pos);
static int decode_iso20_acdp_ACDP_SystemStatusReqType(exi_bitstream_t* stream, struct iso20_acdp_ACDP_SystemStatusReqType* ACDP_SystemStatusReqType, char* xmlOut, size_t xmlOut_size, size_t* xmlOut_pos);
static int decode_iso20_acdp_ACDP_SystemStatusResType(exi_bitstream_t* stream, struct iso20_acdp_ACDP_SystemStatusResType* ACDP_SystemStatusResType, char* xmlOut, size_t xmlOut_size, size_t* xmlOut_pos);
static int decode_iso20_acdp_ACDP_VehiclePositioningReqType(exi_bitstream_t* stream, struct iso20_acdp_ACDP_VehiclePositioningReqType* ACDP_VehiclePositioningReqType, char* xmlOut, size_t xmlOut_size, size_t* xmlOut_pos);
static int decode_iso20_acdp_ACDP_VehiclePositioningResType(exi_bitstream_t* stream, struct iso20_acdp_ACDP_VehiclePositioningResType* ACDP_VehiclePositioningResType, char* xmlOut, size_t xmlOut_size, size_t* xmlOut_pos);
static int decode_iso20_acdp_CLReqControlModeType(exi_bitstream_t* stream, struct iso20_acdp_CLReqControlModeType* CLReqControlModeType, char* xmlOut, size_t xmlOut_size, size_t* xmlOut_pos);
static int decode_iso20_acdp_CLResControlModeType(exi_bitstream_t* stream, struct iso20_acdp_CLResControlModeType* CLResControlModeType, char* xmlOut, size_t xmlOut_size, size_t* xmlOut_pos);
static int decode_iso20_acdp_ManifestType(exi_bitstream_t* stream, struct iso20_acdp_ManifestType* ManifestType, char* xmlOut, size_t xmlOut_size, size_t* xmlOut_pos);
static int decode_iso20_acdp_SignaturePropertiesType(exi_bitstream_t* stream, struct iso20_acdp_SignaturePropertiesType* SignaturePropertiesType, char* xmlOut, size_t xmlOut_size, size_t* xmlOut_pos);

// Element: definition=complex; name={http://www.w3.org/2000/09/xmldsig#}Transform; type={http://www.w3.org/2000/09/xmldsig#}TransformType; base type=; content type=mixed;
//          abstract=False; final=False; choice=True;
// Particle: Algorithm, anyURI (1, 1); ANY, anyType (0, 1); XPath, string (0, 1);
static int decode_iso20_acdp_TransformType(exi_bitstream_t* stream, struct iso20_acdp_TransformType* TransformType, char* xmlOut, size_t xmlOut_size, size_t* xmlOut_pos) {
    int grammar_id = 0;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_acdp_TransformType(TransformType);

    while (!done)
    {
        switch (grammar_id)
        {
        case 0:
            // Grammar: ID=0; read/write bits=1; START (Algorithm)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: START (Algorithm, anyURI (anyURI)); next=1
                    // XML: attribute
                    xml_write(xmlOut, xmlOut_size, xmlOut_pos, " Algorithm=\"", 12);
                    // decode: string (len, characters) (Attribute)
                    error = exi_basetypes_decoder_uint_16(stream, &TransformType->Algorithm.charactersLen);
                    if (error == 0)
                    {
                        if (TransformType->Algorithm.charactersLen >= 2)
                        {
                            // string tables and table partitions are not supported, so the length has to be decremented by 2
                            TransformType->Algorithm.charactersLen -= 2;
                            error = exi_basetypes_decoder_characters(stream, TransformType->Algorithm.charactersLen, TransformType->Algorithm.characters, iso20_acdp_Algorithm_CHARACTER_SIZE);
                            if (error == 0)
                            {
                                // XML: emit string value
                                xml_write_escaped_attr(xmlOut, xmlOut_size, xmlOut_pos, TransformType->Algorithm.characters, TransformType->Algorithm.charactersLen);
                            }
                        }
                        else
                        {
                            // the string seems to be in the table, but this is not supported
                            error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                        }
                    }
                    grammar_id = 1;
                    xml_write(xmlOut, xmlOut_size, xmlOut_pos, "\"", 1);
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 1:
            // Grammar: ID=1; read/write bits=3; START (XPath), START (ANY), END Element, START (ANY)
            error = exi_basetypes_decoder_nbit_uint(stream, 3, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: START (XPath, string (string)); next=2
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns1:XPath", 10);
                        (void)xml_tag_start;
                    // decode: string (len, characters)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            error = exi_basetypes_decoder_uint_16(stream, &TransformType->XPath.charactersLen);
                            if (error == 0)
                            {
                                if (TransformType->XPath.charactersLen >= 2)
                                {
                                    // string tables and table partitions are not supported, so the length has to be decremented by 2
                                    TransformType->XPath.charactersLen -= 2;
                                    error = exi_basetypes_decoder_characters(stream, TransformType->XPath.charactersLen, TransformType->XPath.characters, iso20_acdp_XPath_CHARACTER_SIZE);
                                    if (error == 0)
                                    {
                                        // XML: emit string value
                                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                                        xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, TransformType->XPath.characters, TransformType->XPath.charactersLen);
                                    }
                                }
                                else
                                {
                                    // the string seems to be in the table, but this is not supported
                                    error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                                }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_characters is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                TransformType->XPath_isUsed = 1u;
                                grammar_id = 2;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns1:XPath>", 12);
                    }
                    break;
                case 1:
                    // Event: START (ANY, anyType (base64Binary)); next=2
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ANY", 4);
                        (void)xml_tag_start;
                    // decode: event not accepted
                    error = EXI_ERROR__UNKNOWN_EVENT_FOR_DECODING;
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ANY>", 6);
                    }
                    break;
                case 2:
                    // Event: END Element; next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                case 3:
                    // Event: START (ANY, anyType (base64Binary)); next=2
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ANY", 4);
                        (void)xml_tag_start;
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &TransformType->ANY.bytesLen, &TransformType->ANY.bytes[0], iso20_acdp_anyType_BYTES_SIZE);
                    if (error == 0)
                    {
                        TransformType->ANY_isUsed = 1u;
                        // XML: emit base64 encoded value
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                        {
                            static const char encoding_table[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
                            static const int mod_table[] = {0, 2, 1};
                            size_t output_length = 4 * ((TransformType->ANY.bytesLen + 2) / 3);
                            unsigned char* encoded_data = (unsigned char*)malloc(output_length + 1);
                            if (encoded_data != NULL)
                            {
                                size_t i, j;
                                for (i = 0, j = 0; i < TransformType->ANY.bytesLen;)
                                {
                                    uint32_t a = i < TransformType->ANY.bytesLen ? TransformType->ANY.bytes[i++] : 0;
                                    uint32_t b = i < TransformType->ANY.bytesLen ? TransformType->ANY.bytes[i++] : 0;
                                    uint32_t c = i < TransformType->ANY.bytesLen ? TransformType->ANY.bytes[i++] : 0;
                                    uint32_t triple = (a << 16) + (b << 8) + c;
                                    encoded_data[j++] = encoding_table[(triple >> 18) & 0x3F];
                                    encoded_data[j++] = encoding_table[(triple >> 12) & 0x3F];
                                    encoded_data[j++] = encoding_table[(triple >> 6) & 0x3F];
                                    encoded_data[j++] = encoding_table[triple & 0x3F];
                                }
                                for (i = 0; i < (size_t)mod_table[TransformType->ANY.bytesLen % 3]; i++)
                                {
                                    encoded_data[output_length - 1 - i] = '=';
                                }
                                xml_write(xmlOut, xmlOut_size, xmlOut_pos, (char*)encoded_data, output_length);
                                free(encoded_data);
                            }
                            else
                            {
                                xml_write(xmlOut, xmlOut_size, xmlOut_pos, "(base64-alloc-failed)", 21);
                            }
                        }
                        grammar_id = 2;
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ANY>", 6);
                    }
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: END Element; next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={http://www.w3.org/2000/09/xmldsig#}DSAKeyValue; type={http://www.w3.org/2000/09/xmldsig#}DSAKeyValueType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: P, CryptoBinary (0, 1) (was 1, 1) (seq. ['P', 'Q']); Q, CryptoBinary (0, 1) (was 1, 1) (seq. ['P', 'Q']); G, CryptoBinary (0, 1); Y, CryptoBinary (1, 1); J, CryptoBinary (0, 1); Seed, CryptoBinary (0, 1) (was 1, 1) (seq. ['Seed', 'PgenCounter']); PgenCounter, CryptoBinary (0, 1) (was 1, 1) (seq. ['Seed', 'PgenCounter']);
static int decode_iso20_acdp_DSAKeyValueType(exi_bitstream_t* stream, struct iso20_acdp_DSAKeyValueType* DSAKeyValueType, char* xmlOut, size_t xmlOut_size, size_t* xmlOut_pos) {
    int grammar_id = 4;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_acdp_DSAKeyValueType(DSAKeyValueType);

    while (!done)
    {
        switch (grammar_id)
        {
        case 4:
            // Grammar: ID=4; read/write bits=2; START (P), START (G), START (Y)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: START (P, CryptoBinary (base64Binary)); next=5
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns1:P", 6);
                        (void)xml_tag_start;
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &DSAKeyValueType->P.bytesLen, &DSAKeyValueType->P.bytes[0], iso20_acdp_CryptoBinary_BYTES_SIZE);
                    if (error == 0)
                    {
                        DSAKeyValueType->P_isUsed = 1u;
                        // XML: emit base64 encoded value
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                        {
                            static const char encoding_table[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
                            static const int mod_table[] = {0, 2, 1};
                            size_t output_length = 4 * ((DSAKeyValueType->P.bytesLen + 2) / 3);
                            unsigned char* encoded_data = (unsigned char*)malloc(output_length + 1);
                            if (encoded_data != NULL)
                            {
                                size_t i, j;
                                for (i = 0, j = 0; i < DSAKeyValueType->P.bytesLen;)
                                {
                                    uint32_t a = i < DSAKeyValueType->P.bytesLen ? DSAKeyValueType->P.bytes[i++] : 0;
                                    uint32_t b = i < DSAKeyValueType->P.bytesLen ? DSAKeyValueType->P.bytes[i++] : 0;
                                    uint32_t c = i < DSAKeyValueType->P.bytesLen ? DSAKeyValueType->P.bytes[i++] : 0;
                                    uint32_t triple = (a << 16) + (b << 8) + c;
                                    encoded_data[j++] = encoding_table[(triple >> 18) & 0x3F];
                                    encoded_data[j++] = encoding_table[(triple >> 12) & 0x3F];
                                    encoded_data[j++] = encoding_table[(triple >> 6) & 0x3F];
                                    encoded_data[j++] = encoding_table[triple & 0x3F];
                                }
                                for (i = 0; i < (size_t)mod_table[DSAKeyValueType->P.bytesLen % 3]; i++)
                                {
                                    encoded_data[output_length - 1 - i] = '=';
                                }
                                xml_write(xmlOut, xmlOut_size, xmlOut_pos, (char*)encoded_data, output_length);
                                free(encoded_data);
                            }
                            else
                            {
                                xml_write(xmlOut, xmlOut_size, xmlOut_pos, "(base64-alloc-failed)", 21);
                            }
                        }
                        grammar_id = 5;
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns1:P>", 8);
                    }
                    break;
                case 1:
                    // Event: START (G, CryptoBinary (base64Binary)); next=7
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns1:G", 6);
                        (void)xml_tag_start;
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &DSAKeyValueType->G.bytesLen, &DSAKeyValueType->G.bytes[0], iso20_acdp_CryptoBinary_BYTES_SIZE);
                    if (error == 0)
                    {
                        DSAKeyValueType->G_isUsed = 1u;
                        // XML: emit base64 encoded value
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                        {
                            static const char encoding_table[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
                            static const int mod_table[] = {0, 2, 1};
                            size_t output_length = 4 * ((DSAKeyValueType->G.bytesLen + 2) / 3);
                            unsigned char* encoded_data = (unsigned char*)malloc(output_length + 1);
                            if (encoded_data != NULL)
                            {
                                size_t i, j;
                                for (i = 0, j = 0; i < DSAKeyValueType->G.bytesLen;)
                                {
                                    uint32_t a = i < DSAKeyValueType->G.bytesLen ? DSAKeyValueType->G.bytes[i++] : 0;
                                    uint32_t b = i < DSAKeyValueType->G.bytesLen ? DSAKeyValueType->G.bytes[i++] : 0;
                                    uint32_t c = i < DSAKeyValueType->G.bytesLen ? DSAKeyValueType->G.bytes[i++] : 0;
                                    uint32_t triple = (a << 16) + (b << 8) + c;
                                    encoded_data[j++] = encoding_table[(triple >> 18) & 0x3F];
                                    encoded_data[j++] = encoding_table[(triple >> 12) & 0x3F];
                                    encoded_data[j++] = encoding_table[(triple >> 6) & 0x3F];
                                    encoded_data[j++] = encoding_table[triple & 0x3F];
                                }
                                for (i = 0; i < (size_t)mod_table[DSAKeyValueType->G.bytesLen % 3]; i++)
                                {
                                    encoded_data[output_length - 1 - i] = '=';
                                }
                                xml_write(xmlOut, xmlOut_size, xmlOut_pos, (char*)encoded_data, output_length);
                                free(encoded_data);
                            }
                            else
                            {
                                xml_write(xmlOut, xmlOut_size, xmlOut_pos, "(base64-alloc-failed)", 21);
                            }
                        }
                        grammar_id = 7;
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns1:G>", 8);
                    }
                    break;
                case 2:
                    // Event: START (Y, CryptoBinary (base64Binary)); next=8
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns1:Y", 6);
                        (void)xml_tag_start;
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &DSAKeyValueType->Y.bytesLen, &DSAKeyValueType->Y.bytes[0], iso20_acdp_CryptoBinary_BYTES_SIZE);
                    if (error == 0)
                    {
                        // XML: emit base64 encoded value
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                        {
                            static const char encoding_table[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
                            static const int mod_table[] = {0, 2, 1};
                            size_t output_length = 4 * ((DSAKeyValueType->Y.bytesLen + 2) / 3);
                            unsigned char* encoded_data = (unsigned char*)malloc(output_length + 1);
                            if (encoded_data != NULL)
                            {
                                size_t i, j;
                                for (i = 0, j = 0; i < DSAKeyValueType->Y.bytesLen;)
                                {
                                    uint32_t a = i < DSAKeyValueType->Y.bytesLen ? DSAKeyValueType->Y.bytes[i++] : 0;
                                    uint32_t b = i < DSAKeyValueType->Y.bytesLen ? DSAKeyValueType->Y.bytes[i++] : 0;
                                    uint32_t c = i < DSAKeyValueType->Y.bytesLen ? DSAKeyValueType->Y.bytes[i++] : 0;
                                    uint32_t triple = (a << 16) + (b << 8) + c;
                                    encoded_data[j++] = encoding_table[(triple >> 18) & 0x3F];
                                    encoded_data[j++] = encoding_table[(triple >> 12) & 0x3F];
                                    encoded_data[j++] = encoding_table[(triple >> 6) & 0x3F];
                                    encoded_data[j++] = encoding_table[triple & 0x3F];
                                }
                                for (i = 0; i < (size_t)mod_table[DSAKeyValueType->Y.bytesLen % 3]; i++)
                                {
                                    encoded_data[output_length - 1 - i] = '=';
                                }
                                xml_write(xmlOut, xmlOut_size, xmlOut_pos, (char*)encoded_data, output_length);
                                free(encoded_data);
                            }
                            else
                            {
                                xml_write(xmlOut, xmlOut_size, xmlOut_pos, "(base64-alloc-failed)", 21);
                            }
                        }
                        grammar_id = 8;
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns1:Y>", 8);
                    }
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 5:
            // Grammar: ID=5; read/write bits=1; START (Q)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: START (Q, CryptoBinary (base64Binary)); next=6
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns1:Q", 6);
                        (void)xml_tag_start;
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &DSAKeyValueType->Q.bytesLen, &DSAKeyValueType->Q.bytes[0], iso20_acdp_CryptoBinary_BYTES_SIZE);
                    if (error == 0)
                    {
                        DSAKeyValueType->Q_isUsed = 1u;
                        // XML: emit base64 encoded value
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                        {
                            static const char encoding_table[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
                            static const int mod_table[] = {0, 2, 1};
                            size_t output_length = 4 * ((DSAKeyValueType->Q.bytesLen + 2) / 3);
                            unsigned char* encoded_data = (unsigned char*)malloc(output_length + 1);
                            if (encoded_data != NULL)
                            {
                                size_t i, j;
                                for (i = 0, j = 0; i < DSAKeyValueType->Q.bytesLen;)
                                {
                                    uint32_t a = i < DSAKeyValueType->Q.bytesLen ? DSAKeyValueType->Q.bytes[i++] : 0;
                                    uint32_t b = i < DSAKeyValueType->Q.bytesLen ? DSAKeyValueType->Q.bytes[i++] : 0;
                                    uint32_t c = i < DSAKeyValueType->Q.bytesLen ? DSAKeyValueType->Q.bytes[i++] : 0;
                                    uint32_t triple = (a << 16) + (b << 8) + c;
                                    encoded_data[j++] = encoding_table[(triple >> 18) & 0x3F];
                                    encoded_data[j++] = encoding_table[(triple >> 12) & 0x3F];
                                    encoded_data[j++] = encoding_table[(triple >> 6) & 0x3F];
                                    encoded_data[j++] = encoding_table[triple & 0x3F];
                                }
                                for (i = 0; i < (size_t)mod_table[DSAKeyValueType->Q.bytesLen % 3]; i++)
                                {
                                    encoded_data[output_length - 1 - i] = '=';
                                }
                                xml_write(xmlOut, xmlOut_size, xmlOut_pos, (char*)encoded_data, output_length);
                                free(encoded_data);
                            }
                            else
                            {
                                xml_write(xmlOut, xmlOut_size, xmlOut_pos, "(base64-alloc-failed)", 21);
                            }
                        }
                        grammar_id = 6;
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns1:Q>", 8);
                    }
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 6:
            // Grammar: ID=6; read/write bits=2; START (G), START (Y)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: START (G, CryptoBinary (base64Binary)); next=7
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns1:G", 6);
                        (void)xml_tag_start;
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &DSAKeyValueType->G.bytesLen, &DSAKeyValueType->G.bytes[0], iso20_acdp_CryptoBinary_BYTES_SIZE);
                    if (error == 0)
                    {
                        DSAKeyValueType->G_isUsed = 1u;
                        // XML: emit base64 encoded value
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                        {
                            static const char encoding_table[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
                            static const int mod_table[] = {0, 2, 1};
                            size_t output_length = 4 * ((DSAKeyValueType->G.bytesLen + 2) / 3);
                            unsigned char* encoded_data = (unsigned char*)malloc(output_length + 1);
                            if (encoded_data != NULL)
                            {
                                size_t i, j;
                                for (i = 0, j = 0; i < DSAKeyValueType->G.bytesLen;)
                                {
                                    uint32_t a = i < DSAKeyValueType->G.bytesLen ? DSAKeyValueType->G.bytes[i++] : 0;
                                    uint32_t b = i < DSAKeyValueType->G.bytesLen ? DSAKeyValueType->G.bytes[i++] : 0;
                                    uint32_t c = i < DSAKeyValueType->G.bytesLen ? DSAKeyValueType->G.bytes[i++] : 0;
                                    uint32_t triple = (a << 16) + (b << 8) + c;
                                    encoded_data[j++] = encoding_table[(triple >> 18) & 0x3F];
                                    encoded_data[j++] = encoding_table[(triple >> 12) & 0x3F];
                                    encoded_data[j++] = encoding_table[(triple >> 6) & 0x3F];
                                    encoded_data[j++] = encoding_table[triple & 0x3F];
                                }
                                for (i = 0; i < (size_t)mod_table[DSAKeyValueType->G.bytesLen % 3]; i++)
                                {
                                    encoded_data[output_length - 1 - i] = '=';
                                }
                                xml_write(xmlOut, xmlOut_size, xmlOut_pos, (char*)encoded_data, output_length);
                                free(encoded_data);
                            }
                            else
                            {
                                xml_write(xmlOut, xmlOut_size, xmlOut_pos, "(base64-alloc-failed)", 21);
                            }
                        }
                        grammar_id = 7;
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns1:G>", 8);
                    }
                    break;
                case 1:
                    // Event: START (Y, CryptoBinary (base64Binary)); next=8
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns1:Y", 6);
                        (void)xml_tag_start;
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &DSAKeyValueType->Y.bytesLen, &DSAKeyValueType->Y.bytes[0], iso20_acdp_CryptoBinary_BYTES_SIZE);
                    if (error == 0)
                    {
                        // XML: emit base64 encoded value
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                        {
                            static const char encoding_table[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
                            static const int mod_table[] = {0, 2, 1};
                            size_t output_length = 4 * ((DSAKeyValueType->Y.bytesLen + 2) / 3);
                            unsigned char* encoded_data = (unsigned char*)malloc(output_length + 1);
                            if (encoded_data != NULL)
                            {
                                size_t i, j;
                                for (i = 0, j = 0; i < DSAKeyValueType->Y.bytesLen;)
                                {
                                    uint32_t a = i < DSAKeyValueType->Y.bytesLen ? DSAKeyValueType->Y.bytes[i++] : 0;
                                    uint32_t b = i < DSAKeyValueType->Y.bytesLen ? DSAKeyValueType->Y.bytes[i++] : 0;
                                    uint32_t c = i < DSAKeyValueType->Y.bytesLen ? DSAKeyValueType->Y.bytes[i++] : 0;
                                    uint32_t triple = (a << 16) + (b << 8) + c;
                                    encoded_data[j++] = encoding_table[(triple >> 18) & 0x3F];
                                    encoded_data[j++] = encoding_table[(triple >> 12) & 0x3F];
                                    encoded_data[j++] = encoding_table[(triple >> 6) & 0x3F];
                                    encoded_data[j++] = encoding_table[triple & 0x3F];
                                }
                                for (i = 0; i < (size_t)mod_table[DSAKeyValueType->Y.bytesLen % 3]; i++)
                                {
                                    encoded_data[output_length - 1 - i] = '=';
                                }
                                xml_write(xmlOut, xmlOut_size, xmlOut_pos, (char*)encoded_data, output_length);
                                free(encoded_data);
                            }
                            else
                            {
                                xml_write(xmlOut, xmlOut_size, xmlOut_pos, "(base64-alloc-failed)", 21);
                            }
                        }
                        grammar_id = 8;
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns1:Y>", 8);
                    }
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 7:
            // Grammar: ID=7; read/write bits=1; START (Y)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: START (Y, CryptoBinary (base64Binary)); next=8
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns1:Y", 6);
                        (void)xml_tag_start;
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &DSAKeyValueType->Y.bytesLen, &DSAKeyValueType->Y.bytes[0], iso20_acdp_CryptoBinary_BYTES_SIZE);
                    if (error == 0)
                    {
                        // XML: emit base64 encoded value
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                        {
                            static const char encoding_table[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
                            static const int mod_table[] = {0, 2, 1};
                            size_t output_length = 4 * ((DSAKeyValueType->Y.bytesLen + 2) / 3);
                            unsigned char* encoded_data = (unsigned char*)malloc(output_length + 1);
                            if (encoded_data != NULL)
                            {
                                size_t i, j;
                                for (i = 0, j = 0; i < DSAKeyValueType->Y.bytesLen;)
                                {
                                    uint32_t a = i < DSAKeyValueType->Y.bytesLen ? DSAKeyValueType->Y.bytes[i++] : 0;
                                    uint32_t b = i < DSAKeyValueType->Y.bytesLen ? DSAKeyValueType->Y.bytes[i++] : 0;
                                    uint32_t c = i < DSAKeyValueType->Y.bytesLen ? DSAKeyValueType->Y.bytes[i++] : 0;
                                    uint32_t triple = (a << 16) + (b << 8) + c;
                                    encoded_data[j++] = encoding_table[(triple >> 18) & 0x3F];
                                    encoded_data[j++] = encoding_table[(triple >> 12) & 0x3F];
                                    encoded_data[j++] = encoding_table[(triple >> 6) & 0x3F];
                                    encoded_data[j++] = encoding_table[triple & 0x3F];
                                }
                                for (i = 0; i < (size_t)mod_table[DSAKeyValueType->Y.bytesLen % 3]; i++)
                                {
                                    encoded_data[output_length - 1 - i] = '=';
                                }
                                xml_write(xmlOut, xmlOut_size, xmlOut_pos, (char*)encoded_data, output_length);
                                free(encoded_data);
                            }
                            else
                            {
                                xml_write(xmlOut, xmlOut_size, xmlOut_pos, "(base64-alloc-failed)", 21);
                            }
                        }
                        grammar_id = 8;
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns1:Y>", 8);
                    }
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 8:
            // Grammar: ID=8; read/write bits=2; START (J), START (Seed), END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: START (J, CryptoBinary (base64Binary)); next=9
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns1:J", 6);
                        (void)xml_tag_start;
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &DSAKeyValueType->J.bytesLen, &DSAKeyValueType->J.bytes[0], iso20_acdp_CryptoBinary_BYTES_SIZE);
                    if (error == 0)
                    {
                        DSAKeyValueType->J_isUsed = 1u;
                        // XML: emit base64 encoded value
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                        {
                            static const char encoding_table[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
                            static const int mod_table[] = {0, 2, 1};
                            size_t output_length = 4 * ((DSAKeyValueType->J.bytesLen + 2) / 3);
                            unsigned char* encoded_data = (unsigned char*)malloc(output_length + 1);
                            if (encoded_data != NULL)
                            {
                                size_t i, j;
                                for (i = 0, j = 0; i < DSAKeyValueType->J.bytesLen;)
                                {
                                    uint32_t a = i < DSAKeyValueType->J.bytesLen ? DSAKeyValueType->J.bytes[i++] : 0;
                                    uint32_t b = i < DSAKeyValueType->J.bytesLen ? DSAKeyValueType->J.bytes[i++] : 0;
                                    uint32_t c = i < DSAKeyValueType->J.bytesLen ? DSAKeyValueType->J.bytes[i++] : 0;
                                    uint32_t triple = (a << 16) + (b << 8) + c;
                                    encoded_data[j++] = encoding_table[(triple >> 18) & 0x3F];
                                    encoded_data[j++] = encoding_table[(triple >> 12) & 0x3F];
                                    encoded_data[j++] = encoding_table[(triple >> 6) & 0x3F];
                                    encoded_data[j++] = encoding_table[triple & 0x3F];
                                }
                                for (i = 0; i < (size_t)mod_table[DSAKeyValueType->J.bytesLen % 3]; i++)
                                {
                                    encoded_data[output_length - 1 - i] = '=';
                                }
                                xml_write(xmlOut, xmlOut_size, xmlOut_pos, (char*)encoded_data, output_length);
                                free(encoded_data);
                            }
                            else
                            {
                                xml_write(xmlOut, xmlOut_size, xmlOut_pos, "(base64-alloc-failed)", 21);
                            }
                        }
                        grammar_id = 9;
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns1:J>", 8);
                    }
                    break;
                case 1:
                    // Event: START (Seed, CryptoBinary (base64Binary)); next=10
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns1:Seed", 9);
                        (void)xml_tag_start;
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &DSAKeyValueType->Seed.bytesLen, &DSAKeyValueType->Seed.bytes[0], iso20_acdp_CryptoBinary_BYTES_SIZE);
                    if (error == 0)
                    {
                        DSAKeyValueType->Seed_isUsed = 1u;
                        // XML: emit base64 encoded value
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                        {
                            static const char encoding_table[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
                            static const int mod_table[] = {0, 2, 1};
                            size_t output_length = 4 * ((DSAKeyValueType->Seed.bytesLen + 2) / 3);
                            unsigned char* encoded_data = (unsigned char*)malloc(output_length + 1);
                            if (encoded_data != NULL)
                            {
                                size_t i, j;
                                for (i = 0, j = 0; i < DSAKeyValueType->Seed.bytesLen;)
                                {
                                    uint32_t a = i < DSAKeyValueType->Seed.bytesLen ? DSAKeyValueType->Seed.bytes[i++] : 0;
                                    uint32_t b = i < DSAKeyValueType->Seed.bytesLen ? DSAKeyValueType->Seed.bytes[i++] : 0;
                                    uint32_t c = i < DSAKeyValueType->Seed.bytesLen ? DSAKeyValueType->Seed.bytes[i++] : 0;
                                    uint32_t triple = (a << 16) + (b << 8) + c;
                                    encoded_data[j++] = encoding_table[(triple >> 18) & 0x3F];
                                    encoded_data[j++] = encoding_table[(triple >> 12) & 0x3F];
                                    encoded_data[j++] = encoding_table[(triple >> 6) & 0x3F];
                                    encoded_data[j++] = encoding_table[triple & 0x3F];
                                }
                                for (i = 0; i < (size_t)mod_table[DSAKeyValueType->Seed.bytesLen % 3]; i++)
                                {
                                    encoded_data[output_length - 1 - i] = '=';
                                }
                                xml_write(xmlOut, xmlOut_size, xmlOut_pos, (char*)encoded_data, output_length);
                                free(encoded_data);
                            }
                            else
                            {
                                xml_write(xmlOut, xmlOut_size, xmlOut_pos, "(base64-alloc-failed)", 21);
                            }
                        }
                        grammar_id = 10;
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns1:Seed>", 11);
                    }
                    break;
                case 2:
                    // Event: END Element; next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 9:
            // Grammar: ID=9; read/write bits=2; START (Seed), END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: START (Seed, CryptoBinary (base64Binary)); next=10
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns1:Seed", 9);
                        (void)xml_tag_start;
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &DSAKeyValueType->Seed.bytesLen, &DSAKeyValueType->Seed.bytes[0], iso20_acdp_CryptoBinary_BYTES_SIZE);
                    if (error == 0)
                    {
                        DSAKeyValueType->Seed_isUsed = 1u;
                        // XML: emit base64 encoded value
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                        {
                            static const char encoding_table[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
                            static const int mod_table[] = {0, 2, 1};
                            size_t output_length = 4 * ((DSAKeyValueType->Seed.bytesLen + 2) / 3);
                            unsigned char* encoded_data = (unsigned char*)malloc(output_length + 1);
                            if (encoded_data != NULL)
                            {
                                size_t i, j;
                                for (i = 0, j = 0; i < DSAKeyValueType->Seed.bytesLen;)
                                {
                                    uint32_t a = i < DSAKeyValueType->Seed.bytesLen ? DSAKeyValueType->Seed.bytes[i++] : 0;
                                    uint32_t b = i < DSAKeyValueType->Seed.bytesLen ? DSAKeyValueType->Seed.bytes[i++] : 0;
                                    uint32_t c = i < DSAKeyValueType->Seed.bytesLen ? DSAKeyValueType->Seed.bytes[i++] : 0;
                                    uint32_t triple = (a << 16) + (b << 8) + c;
                                    encoded_data[j++] = encoding_table[(triple >> 18) & 0x3F];
                                    encoded_data[j++] = encoding_table[(triple >> 12) & 0x3F];
                                    encoded_data[j++] = encoding_table[(triple >> 6) & 0x3F];
                                    encoded_data[j++] = encoding_table[triple & 0x3F];
                                }
                                for (i = 0; i < (size_t)mod_table[DSAKeyValueType->Seed.bytesLen % 3]; i++)
                                {
                                    encoded_data[output_length - 1 - i] = '=';
                                }
                                xml_write(xmlOut, xmlOut_size, xmlOut_pos, (char*)encoded_data, output_length);
                                free(encoded_data);
                            }
                            else
                            {
                                xml_write(xmlOut, xmlOut_size, xmlOut_pos, "(base64-alloc-failed)", 21);
                            }
                        }
                        grammar_id = 10;
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns1:Seed>", 11);
                    }
                    break;
                case 1:
                    // Event: END Element; next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 10:
            // Grammar: ID=10; read/write bits=2; START (PgenCounter), END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: START (PgenCounter, CryptoBinary (base64Binary)); next=2
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns1:PgenCounter", 16);
                        (void)xml_tag_start;
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &DSAKeyValueType->PgenCounter.bytesLen, &DSAKeyValueType->PgenCounter.bytes[0], iso20_acdp_CryptoBinary_BYTES_SIZE);
                    if (error == 0)
                    {
                        DSAKeyValueType->PgenCounter_isUsed = 1u;
                        // XML: emit base64 encoded value
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                        {
                            static const char encoding_table[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
                            static const int mod_table[] = {0, 2, 1};
                            size_t output_length = 4 * ((DSAKeyValueType->PgenCounter.bytesLen + 2) / 3);
                            unsigned char* encoded_data = (unsigned char*)malloc(output_length + 1);
                            if (encoded_data != NULL)
                            {
                                size_t i, j;
                                for (i = 0, j = 0; i < DSAKeyValueType->PgenCounter.bytesLen;)
                                {
                                    uint32_t a = i < DSAKeyValueType->PgenCounter.bytesLen ? DSAKeyValueType->PgenCounter.bytes[i++] : 0;
                                    uint32_t b = i < DSAKeyValueType->PgenCounter.bytesLen ? DSAKeyValueType->PgenCounter.bytes[i++] : 0;
                                    uint32_t c = i < DSAKeyValueType->PgenCounter.bytesLen ? DSAKeyValueType->PgenCounter.bytes[i++] : 0;
                                    uint32_t triple = (a << 16) + (b << 8) + c;
                                    encoded_data[j++] = encoding_table[(triple >> 18) & 0x3F];
                                    encoded_data[j++] = encoding_table[(triple >> 12) & 0x3F];
                                    encoded_data[j++] = encoding_table[(triple >> 6) & 0x3F];
                                    encoded_data[j++] = encoding_table[triple & 0x3F];
                                }
                                for (i = 0; i < (size_t)mod_table[DSAKeyValueType->PgenCounter.bytesLen % 3]; i++)
                                {
                                    encoded_data[output_length - 1 - i] = '=';
                                }
                                xml_write(xmlOut, xmlOut_size, xmlOut_pos, (char*)encoded_data, output_length);
                                free(encoded_data);
                            }
                            else
                            {
                                xml_write(xmlOut, xmlOut_size, xmlOut_pos, "(base64-alloc-failed)", 21);
                            }
                        }
                        grammar_id = 2;
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns1:PgenCounter>", 18);
                    }
                    break;
                case 1:
                    // Event: END Element; next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: END Element; next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={http://www.w3.org/2000/09/xmldsig#}DigestMethod; type={http://www.w3.org/2000/09/xmldsig#}DigestMethodType; base type=; content type=mixed;
//          abstract=False; final=False;
// Particle: Algorithm, anyURI (1, 1); ANY, anyType (0, 1);
static int decode_iso20_acdp_DigestMethodType(exi_bitstream_t* stream, struct iso20_acdp_DigestMethodType* DigestMethodType, char* xmlOut, size_t xmlOut_size, size_t* xmlOut_pos) {
    int grammar_id = 11;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_acdp_DigestMethodType(DigestMethodType);

    while (!done)
    {
        switch (grammar_id)
        {
        case 11:
            // Grammar: ID=11; read/write bits=1; START (Algorithm)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: START (Algorithm, anyURI (anyURI)); next=12
                    // XML: attribute
                    xml_write(xmlOut, xmlOut_size, xmlOut_pos, " Algorithm=\"", 12);
                    // decode: string (len, characters) (Attribute)
                    error = exi_basetypes_decoder_uint_16(stream, &DigestMethodType->Algorithm.charactersLen);
                    if (error == 0)
                    {
                        if (DigestMethodType->Algorithm.charactersLen >= 2)
                        {
                            // string tables and table partitions are not supported, so the length has to be decremented by 2
                            DigestMethodType->Algorithm.charactersLen -= 2;
                            error = exi_basetypes_decoder_characters(stream, DigestMethodType->Algorithm.charactersLen, DigestMethodType->Algorithm.characters, iso20_acdp_Algorithm_CHARACTER_SIZE);
                            if (error == 0)
                            {
                                // XML: emit string value
                                xml_write_escaped_attr(xmlOut, xmlOut_size, xmlOut_pos, DigestMethodType->Algorithm.characters, DigestMethodType->Algorithm.charactersLen);
                            }
                        }
                        else
                        {
                            // the string seems to be in the table, but this is not supported
                            error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                        }
                    }
                    grammar_id = 12;
                    xml_write(xmlOut, xmlOut_size, xmlOut_pos, "\"", 1);
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 12:
            // Grammar: ID=12; read/write bits=2; START (ANY), END Element, START (ANY)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: START (ANY, anyType (base64Binary)); next=2
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ANY", 4);
                        (void)xml_tag_start;
                    // decode: event not accepted
                    error = EXI_ERROR__UNKNOWN_EVENT_FOR_DECODING;
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ANY>", 6);
                    }
                    break;
                case 1:
                    // Event: END Element; next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                case 2:
                    // Event: START (ANY, anyType (base64Binary)); next=2
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ANY", 4);
                        (void)xml_tag_start;
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &DigestMethodType->ANY.bytesLen, &DigestMethodType->ANY.bytes[0], iso20_acdp_anyType_BYTES_SIZE);
                    if (error == 0)
                    {
                        DigestMethodType->ANY_isUsed = 1u;
                        // XML: emit base64 encoded value
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                        {
                            static const char encoding_table[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
                            static const int mod_table[] = {0, 2, 1};
                            size_t output_length = 4 * ((DigestMethodType->ANY.bytesLen + 2) / 3);
                            unsigned char* encoded_data = (unsigned char*)malloc(output_length + 1);
                            if (encoded_data != NULL)
                            {
                                size_t i, j;
                                for (i = 0, j = 0; i < DigestMethodType->ANY.bytesLen;)
                                {
                                    uint32_t a = i < DigestMethodType->ANY.bytesLen ? DigestMethodType->ANY.bytes[i++] : 0;
                                    uint32_t b = i < DigestMethodType->ANY.bytesLen ? DigestMethodType->ANY.bytes[i++] : 0;
                                    uint32_t c = i < DigestMethodType->ANY.bytesLen ? DigestMethodType->ANY.bytes[i++] : 0;
                                    uint32_t triple = (a << 16) + (b << 8) + c;
                                    encoded_data[j++] = encoding_table[(triple >> 18) & 0x3F];
                                    encoded_data[j++] = encoding_table[(triple >> 12) & 0x3F];
                                    encoded_data[j++] = encoding_table[(triple >> 6) & 0x3F];
                                    encoded_data[j++] = encoding_table[triple & 0x3F];
                                }
                                for (i = 0; i < (size_t)mod_table[DigestMethodType->ANY.bytesLen % 3]; i++)
                                {
                                    encoded_data[output_length - 1 - i] = '=';
                                }
                                xml_write(xmlOut, xmlOut_size, xmlOut_pos, (char*)encoded_data, output_length);
                                free(encoded_data);
                            }
                            else
                            {
                                xml_write(xmlOut, xmlOut_size, xmlOut_pos, "(base64-alloc-failed)", 21);
                            }
                        }
                        grammar_id = 2;
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ANY>", 6);
                    }
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: END Element; next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={http://www.w3.org/2000/09/xmldsig#}RSAKeyValue; type={http://www.w3.org/2000/09/xmldsig#}RSAKeyValueType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: Modulus, CryptoBinary (1, 1); Exponent, CryptoBinary (1, 1);
static int decode_iso20_acdp_RSAKeyValueType(exi_bitstream_t* stream, struct iso20_acdp_RSAKeyValueType* RSAKeyValueType, char* xmlOut, size_t xmlOut_size, size_t* xmlOut_pos) {
    int grammar_id = 13;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_acdp_RSAKeyValueType(RSAKeyValueType);

    while (!done)
    {
        switch (grammar_id)
        {
        case 13:
            // Grammar: ID=13; read/write bits=1; START (Modulus)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: START (Modulus, CryptoBinary (base64Binary)); next=14
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns1:Modulus", 12);
                        (void)xml_tag_start;
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &RSAKeyValueType->Modulus.bytesLen, &RSAKeyValueType->Modulus.bytes[0], iso20_acdp_CryptoBinary_BYTES_SIZE);
                    if (error == 0)
                    {
                        // XML: emit base64 encoded value
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                        {
                            static const char encoding_table[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
                            static const int mod_table[] = {0, 2, 1};
                            size_t output_length = 4 * ((RSAKeyValueType->Modulus.bytesLen + 2) / 3);
                            unsigned char* encoded_data = (unsigned char*)malloc(output_length + 1);
                            if (encoded_data != NULL)
                            {
                                size_t i, j;
                                for (i = 0, j = 0; i < RSAKeyValueType->Modulus.bytesLen;)
                                {
                                    uint32_t a = i < RSAKeyValueType->Modulus.bytesLen ? RSAKeyValueType->Modulus.bytes[i++] : 0;
                                    uint32_t b = i < RSAKeyValueType->Modulus.bytesLen ? RSAKeyValueType->Modulus.bytes[i++] : 0;
                                    uint32_t c = i < RSAKeyValueType->Modulus.bytesLen ? RSAKeyValueType->Modulus.bytes[i++] : 0;
                                    uint32_t triple = (a << 16) + (b << 8) + c;
                                    encoded_data[j++] = encoding_table[(triple >> 18) & 0x3F];
                                    encoded_data[j++] = encoding_table[(triple >> 12) & 0x3F];
                                    encoded_data[j++] = encoding_table[(triple >> 6) & 0x3F];
                                    encoded_data[j++] = encoding_table[triple & 0x3F];
                                }
                                for (i = 0; i < (size_t)mod_table[RSAKeyValueType->Modulus.bytesLen % 3]; i++)
                                {
                                    encoded_data[output_length - 1 - i] = '=';
                                }
                                xml_write(xmlOut, xmlOut_size, xmlOut_pos, (char*)encoded_data, output_length);
                                free(encoded_data);
                            }
                            else
                            {
                                xml_write(xmlOut, xmlOut_size, xmlOut_pos, "(base64-alloc-failed)", 21);
                            }
                        }
                        grammar_id = 14;
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns1:Modulus>", 14);
                    }
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 14:
            // Grammar: ID=14; read/write bits=1; START (Exponent)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: START (Exponent, CryptoBinary (base64Binary)); next=2
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns1:Exponent", 13);
                        (void)xml_tag_start;
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &RSAKeyValueType->Exponent.bytesLen, &RSAKeyValueType->Exponent.bytes[0], iso20_acdp_CryptoBinary_BYTES_SIZE);
                    if (error == 0)
                    {
                        // XML: emit base64 encoded value
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                        {
                            static const char encoding_table[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
                            static const int mod_table[] = {0, 2, 1};
                            size_t output_length = 4 * ((RSAKeyValueType->Exponent.bytesLen + 2) / 3);
                            unsigned char* encoded_data = (unsigned char*)malloc(output_length + 1);
                            if (encoded_data != NULL)
                            {
                                size_t i, j;
                                for (i = 0, j = 0; i < RSAKeyValueType->Exponent.bytesLen;)
                                {
                                    uint32_t a = i < RSAKeyValueType->Exponent.bytesLen ? RSAKeyValueType->Exponent.bytes[i++] : 0;
                                    uint32_t b = i < RSAKeyValueType->Exponent.bytesLen ? RSAKeyValueType->Exponent.bytes[i++] : 0;
                                    uint32_t c = i < RSAKeyValueType->Exponent.bytesLen ? RSAKeyValueType->Exponent.bytes[i++] : 0;
                                    uint32_t triple = (a << 16) + (b << 8) + c;
                                    encoded_data[j++] = encoding_table[(triple >> 18) & 0x3F];
                                    encoded_data[j++] = encoding_table[(triple >> 12) & 0x3F];
                                    encoded_data[j++] = encoding_table[(triple >> 6) & 0x3F];
                                    encoded_data[j++] = encoding_table[triple & 0x3F];
                                }
                                for (i = 0; i < (size_t)mod_table[RSAKeyValueType->Exponent.bytesLen % 3]; i++)
                                {
                                    encoded_data[output_length - 1 - i] = '=';
                                }
                                xml_write(xmlOut, xmlOut_size, xmlOut_pos, (char*)encoded_data, output_length);
                                free(encoded_data);
                            }
                            else
                            {
                                xml_write(xmlOut, xmlOut_size, xmlOut_pos, "(base64-alloc-failed)", 21);
                            }
                        }
                        grammar_id = 2;
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns1:Exponent>", 15);
                    }
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: END Element; next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={http://www.w3.org/2000/09/xmldsig#}Transforms; type={http://www.w3.org/2000/09/xmldsig#}TransformsType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: Transform, TransformType (1, 1) (original max unbounded);
static int decode_iso20_acdp_TransformsType(exi_bitstream_t* stream, struct iso20_acdp_TransformsType* TransformsType, char* xmlOut, size_t xmlOut_size, size_t* xmlOut_pos) {
    int grammar_id = 15;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_acdp_TransformsType(TransformsType);

    while (!done)
    {
        switch (grammar_id)
        {
        case 15:
            // Grammar: ID=15; read/write bits=1; START (Transform)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: START (Transform, TransformType (TransformType)); next=16
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns1:Transform", 14);
                        (void)xml_tag_start;
                    // decode: element
                    error = decode_iso20_acdp_TransformType(stream, &TransformsType->Transform, xmlOut, xmlOut_size, xmlOut_pos);
                    if (error == 0)
                    {
                        grammar_id = 16;
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns1:Transform>", 16);
                    }
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 16:
            // Grammar: ID=16; read/write bits=2; START (Transform), END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: START (Transform, TransformType (TransformType)); next=2
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns1:Transform", 14);
                        (void)xml_tag_start;
                    // decode: element
                    // This element should not occur a further time, its representation was reduced to a single element
                    error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns1:Transform>", 16);
                    }
                    break;
                case 1:
                    // Event: END Element; next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: END Element; next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={http://www.w3.org/2000/09/xmldsig#}X509IssuerSerial; type={http://www.w3.org/2000/09/xmldsig#}X509IssuerSerialType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: X509IssuerName, string (1, 1); X509SerialNumber, integer (1, 1);
static int decode_iso20_acdp_X509IssuerSerialType(exi_bitstream_t* stream, struct iso20_acdp_X509IssuerSerialType* X509IssuerSerialType, char* xmlOut, size_t xmlOut_size, size_t* xmlOut_pos) {
    int grammar_id = 17;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_acdp_X509IssuerSerialType(X509IssuerSerialType);

    while (!done)
    {
        switch (grammar_id)
        {
        case 17:
            // Grammar: ID=17; read/write bits=1; START (X509IssuerName)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: START (X509IssuerName, string (string)); next=18
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns1:X509IssuerName", 19);
                        (void)xml_tag_start;
                    // decode: string (len, characters)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            error = exi_basetypes_decoder_uint_16(stream, &X509IssuerSerialType->X509IssuerName.charactersLen);
                            if (error == 0)
                            {
                                if (X509IssuerSerialType->X509IssuerName.charactersLen >= 2)
                                {
                                    // string tables and table partitions are not supported, so the length has to be decremented by 2
                                    X509IssuerSerialType->X509IssuerName.charactersLen -= 2;
                                    error = exi_basetypes_decoder_characters(stream, X509IssuerSerialType->X509IssuerName.charactersLen, X509IssuerSerialType->X509IssuerName.characters, iso20_acdp_X509IssuerName_CHARACTER_SIZE);
                                    if (error == 0)
                                    {
                                        // XML: emit string value
                                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                                        xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, X509IssuerSerialType->X509IssuerName.characters, X509IssuerSerialType->X509IssuerName.charactersLen);
                                    }
                                }
                                else
                                {
                                    // the string seems to be in the table, but this is not supported
                                    error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                                }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_characters is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 18;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns1:X509IssuerName>", 21);
                    }
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 18:
            // Grammar: ID=18; read/write bits=1; START (X509SerialNumber)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: START (X509SerialNumber, integer (decimal)); next=2
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns1:X509SerialNumber", 21);
                        (void)xml_tag_start;
                    // decode: signed
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        error = exi_basetypes_decoder_signed(stream, &X509IssuerSerialType->X509SerialNumber);
                        if (error == 0)
                        {
                            // XML: emit value
                            xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                            { int64_t _sv; exi_basetypes_convert_64_from_signed(&X509IssuerSerialType->X509SerialNumber, &_sv); char _xv[64]; int _xl = snprintf(_xv, sizeof(_xv), "%" PRId64, _sv); xml_write(xmlOut, xmlOut_size, xmlOut_pos, _xv, _xl); }
                            grammar_id = 2;
                        }
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns1:X509SerialNumber>", 23);
                    }
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: END Element; next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={http://www.w3.org/2000/09/xmldsig#}CanonicalizationMethod; type={http://www.w3.org/2000/09/xmldsig#}CanonicalizationMethodType; base type=; content type=mixed;
//          abstract=False; final=False;
// Particle: Algorithm, anyURI (1, 1); ANY, anyType (0, 1);
static int decode_iso20_acdp_CanonicalizationMethodType(exi_bitstream_t* stream, struct iso20_acdp_CanonicalizationMethodType* CanonicalizationMethodType, char* xmlOut, size_t xmlOut_size, size_t* xmlOut_pos) {
    int grammar_id = 19;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_acdp_CanonicalizationMethodType(CanonicalizationMethodType);

    while (!done)
    {
        switch (grammar_id)
        {
        case 19:
            // Grammar: ID=19; read/write bits=1; START (Algorithm)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: START (Algorithm, anyURI (anyURI)); next=20
                    // XML: attribute
                    xml_write(xmlOut, xmlOut_size, xmlOut_pos, " Algorithm=\"", 12);
                    // decode: string (len, characters) (Attribute)
                    error = exi_basetypes_decoder_uint_16(stream, &CanonicalizationMethodType->Algorithm.charactersLen);
                    if (error == 0)
                    {
                        if (CanonicalizationMethodType->Algorithm.charactersLen >= 2)
                        {
                            // string tables and table partitions are not supported, so the length has to be decremented by 2
                            CanonicalizationMethodType->Algorithm.charactersLen -= 2;
                            error = exi_basetypes_decoder_characters(stream, CanonicalizationMethodType->Algorithm.charactersLen, CanonicalizationMethodType->Algorithm.characters, iso20_acdp_Algorithm_CHARACTER_SIZE);
                            if (error == 0)
                            {
                                // XML: emit string value
                                xml_write_escaped_attr(xmlOut, xmlOut_size, xmlOut_pos, CanonicalizationMethodType->Algorithm.characters, CanonicalizationMethodType->Algorithm.charactersLen);
                            }
                        }
                        else
                        {
                            // the string seems to be in the table, but this is not supported
                            error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                        }
                    }
                    grammar_id = 20;
                    xml_write(xmlOut, xmlOut_size, xmlOut_pos, "\"", 1);
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 20:
            // Grammar: ID=20; read/write bits=2; START (ANY), END Element, START (ANY)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: START (ANY, anyType (base64Binary)); next=2
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ANY", 4);
                        (void)xml_tag_start;
                    // decode: event not accepted
                    error = EXI_ERROR__UNKNOWN_EVENT_FOR_DECODING;
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ANY>", 6);
                    }
                    break;
                case 1:
                    // Event: END Element; next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                case 2:
                    // Event: START (ANY, anyType (base64Binary)); next=2
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ANY", 4);
                        (void)xml_tag_start;
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &CanonicalizationMethodType->ANY.bytesLen, &CanonicalizationMethodType->ANY.bytes[0], iso20_acdp_anyType_BYTES_SIZE);
                    if (error == 0)
                    {
                        CanonicalizationMethodType->ANY_isUsed = 1u;
                        // XML: emit base64 encoded value
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                        {
                            static const char encoding_table[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
                            static const int mod_table[] = {0, 2, 1};
                            size_t output_length = 4 * ((CanonicalizationMethodType->ANY.bytesLen + 2) / 3);
                            unsigned char* encoded_data = (unsigned char*)malloc(output_length + 1);
                            if (encoded_data != NULL)
                            {
                                size_t i, j;
                                for (i = 0, j = 0; i < CanonicalizationMethodType->ANY.bytesLen;)
                                {
                                    uint32_t a = i < CanonicalizationMethodType->ANY.bytesLen ? CanonicalizationMethodType->ANY.bytes[i++] : 0;
                                    uint32_t b = i < CanonicalizationMethodType->ANY.bytesLen ? CanonicalizationMethodType->ANY.bytes[i++] : 0;
                                    uint32_t c = i < CanonicalizationMethodType->ANY.bytesLen ? CanonicalizationMethodType->ANY.bytes[i++] : 0;
                                    uint32_t triple = (a << 16) + (b << 8) + c;
                                    encoded_data[j++] = encoding_table[(triple >> 18) & 0x3F];
                                    encoded_data[j++] = encoding_table[(triple >> 12) & 0x3F];
                                    encoded_data[j++] = encoding_table[(triple >> 6) & 0x3F];
                                    encoded_data[j++] = encoding_table[triple & 0x3F];
                                }
                                for (i = 0; i < (size_t)mod_table[CanonicalizationMethodType->ANY.bytesLen % 3]; i++)
                                {
                                    encoded_data[output_length - 1 - i] = '=';
                                }
                                xml_write(xmlOut, xmlOut_size, xmlOut_pos, (char*)encoded_data, output_length);
                                free(encoded_data);
                            }
                            else
                            {
                                xml_write(xmlOut, xmlOut_size, xmlOut_pos, "(base64-alloc-failed)", 21);
                            }
                        }
                        grammar_id = 2;
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ANY>", 6);
                    }
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: END Element; next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={http://www.w3.org/2000/09/xmldsig#}KeyValue; type={http://www.w3.org/2000/09/xmldsig#}KeyValueType; base type=; content type=mixed;
//          abstract=False; final=False; choice=True;
// Particle: DSAKeyValue, DSAKeyValueType (0, 1); RSAKeyValue, RSAKeyValueType (0, 1); ANY, anyType (0, 1);
static int decode_iso20_acdp_KeyValueType(exi_bitstream_t* stream, struct iso20_acdp_KeyValueType* KeyValueType, char* xmlOut, size_t xmlOut_size, size_t* xmlOut_pos) {
    int grammar_id = 21;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_acdp_KeyValueType(KeyValueType);

    while (!done)
    {
        switch (grammar_id)
        {
        case 21:
            // Grammar: ID=21; read/write bits=2; START (DSAKeyValue), START (RSAKeyValue), START (ANY)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: START (DSAKeyValue, DSAKeyValueType (DSAKeyValueType)); next=2
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns1:DSAKeyValue", 16);
                        (void)xml_tag_start;
                    // decode: element
                    error = decode_iso20_acdp_DSAKeyValueType(stream, &KeyValueType->DSAKeyValue, xmlOut, xmlOut_size, xmlOut_pos);
                    if (error == 0)
                    {
                        KeyValueType->DSAKeyValue_isUsed = 1u;
                        grammar_id = 2;
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns1:DSAKeyValue>", 18);
                    }
                    break;
                case 1:
                    // Event: START (RSAKeyValue, RSAKeyValueType (RSAKeyValueType)); next=2
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns1:RSAKeyValue", 16);
                        (void)xml_tag_start;
                    // decode: element
                    error = decode_iso20_acdp_RSAKeyValueType(stream, &KeyValueType->RSAKeyValue, xmlOut, xmlOut_size, xmlOut_pos);
                    if (error == 0)
                    {
                        KeyValueType->RSAKeyValue_isUsed = 1u;
                        grammar_id = 2;
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns1:RSAKeyValue>", 18);
                    }
                    break;
                case 2:
                    // Event: START (ANY, anyType (base64Binary)); next=2
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ANY", 4);
                        (void)xml_tag_start;
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &KeyValueType->ANY.bytesLen, &KeyValueType->ANY.bytes[0], iso20_acdp_anyType_BYTES_SIZE);
                    if (error == 0)
                    {
                        KeyValueType->ANY_isUsed = 1u;
                        // XML: emit base64 encoded value
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                        {
                            static const char encoding_table[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
                            static const int mod_table[] = {0, 2, 1};
                            size_t output_length = 4 * ((KeyValueType->ANY.bytesLen + 2) / 3);
                            unsigned char* encoded_data = (unsigned char*)malloc(output_length + 1);
                            if (encoded_data != NULL)
                            {
                                size_t i, j;
                                for (i = 0, j = 0; i < KeyValueType->ANY.bytesLen;)
                                {
                                    uint32_t a = i < KeyValueType->ANY.bytesLen ? KeyValueType->ANY.bytes[i++] : 0;
                                    uint32_t b = i < KeyValueType->ANY.bytesLen ? KeyValueType->ANY.bytes[i++] : 0;
                                    uint32_t c = i < KeyValueType->ANY.bytesLen ? KeyValueType->ANY.bytes[i++] : 0;
                                    uint32_t triple = (a << 16) + (b << 8) + c;
                                    encoded_data[j++] = encoding_table[(triple >> 18) & 0x3F];
                                    encoded_data[j++] = encoding_table[(triple >> 12) & 0x3F];
                                    encoded_data[j++] = encoding_table[(triple >> 6) & 0x3F];
                                    encoded_data[j++] = encoding_table[triple & 0x3F];
                                }
                                for (i = 0; i < (size_t)mod_table[KeyValueType->ANY.bytesLen % 3]; i++)
                                {
                                    encoded_data[output_length - 1 - i] = '=';
                                }
                                xml_write(xmlOut, xmlOut_size, xmlOut_pos, (char*)encoded_data, output_length);
                                free(encoded_data);
                            }
                            else
                            {
                                xml_write(xmlOut, xmlOut_size, xmlOut_pos, "(base64-alloc-failed)", 21);
                            }
                        }
                        grammar_id = 2;
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ANY>", 6);
                    }
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: END Element; next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={http://www.w3.org/2000/09/xmldsig#}PGPData; type={http://www.w3.org/2000/09/xmldsig#}PGPDataType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False; choice=True; sequence=True (2;
// Particle: PGPKeyID, base64Binary (1, 1); PGPKeyPacket, base64Binary (0, 1); ANY, anyType (0, 1); PGPKeyPacket, base64Binary (1, 1); ANY, anyType (0, 1);
static int decode_iso20_acdp_PGPDataType(exi_bitstream_t* stream, struct iso20_acdp_PGPDataType* PGPDataType, char* xmlOut, size_t xmlOut_size, size_t* xmlOut_pos) {
    int grammar_id = 22;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_acdp_PGPDataType(PGPDataType);

    while (!done)
    {
        switch (grammar_id)
        {
        case 22:
            // Grammar: ID=22; read/write bits=2; START (PGPKeyID), START (PGPKeyPacket)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: START (PGPKeyID, base64Binary (base64Binary)); next=23
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns1:PGPKeyID", 13);
                        (void)xml_tag_start;
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &PGPDataType->choice_1.PGPKeyID.bytesLen, &PGPDataType->choice_1.PGPKeyID.bytes[0], iso20_acdp_base64Binary_BYTES_SIZE);
                    if (error == 0)
                    {
                        // XML: emit base64 encoded value
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                        {
                            static const char encoding_table[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
                            static const int mod_table[] = {0, 2, 1};
                            size_t output_length = 4 * ((PGPDataType->choice_1.PGPKeyID.bytesLen + 2) / 3);
                            unsigned char* encoded_data = (unsigned char*)malloc(output_length + 1);
                            if (encoded_data != NULL)
                            {
                                size_t i, j;
                                for (i = 0, j = 0; i < PGPDataType->choice_1.PGPKeyID.bytesLen;)
                                {
                                    uint32_t a = i < PGPDataType->choice_1.PGPKeyID.bytesLen ? PGPDataType->choice_1.PGPKeyID.bytes[i++] : 0;
                                    uint32_t b = i < PGPDataType->choice_1.PGPKeyID.bytesLen ? PGPDataType->choice_1.PGPKeyID.bytes[i++] : 0;
                                    uint32_t c = i < PGPDataType->choice_1.PGPKeyID.bytesLen ? PGPDataType->choice_1.PGPKeyID.bytes[i++] : 0;
                                    uint32_t triple = (a << 16) + (b << 8) + c;
                                    encoded_data[j++] = encoding_table[(triple >> 18) & 0x3F];
                                    encoded_data[j++] = encoding_table[(triple >> 12) & 0x3F];
                                    encoded_data[j++] = encoding_table[(triple >> 6) & 0x3F];
                                    encoded_data[j++] = encoding_table[triple & 0x3F];
                                }
                                for (i = 0; i < (size_t)mod_table[PGPDataType->choice_1.PGPKeyID.bytesLen % 3]; i++)
                                {
                                    encoded_data[output_length - 1 - i] = '=';
                                }
                                xml_write(xmlOut, xmlOut_size, xmlOut_pos, (char*)encoded_data, output_length);
                                free(encoded_data);
                            }
                            else
                            {
                                xml_write(xmlOut, xmlOut_size, xmlOut_pos, "(base64-alloc-failed)", 21);
                            }
                        }
                        grammar_id = 23;
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns1:PGPKeyID>", 15);
                    }
                    break;
                case 1:
                    // Event: START (PGPKeyPacket, base64Binary (base64Binary)); next=24
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns1:PGPKeyPacket", 17);
                        (void)xml_tag_start;
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &PGPDataType->choice_1.PGPKeyPacket.bytesLen, &PGPDataType->choice_1.PGPKeyPacket.bytes[0], iso20_acdp_base64Binary_BYTES_SIZE);
                    if (error == 0)
                    {
                        PGPDataType->choice_1.PGPKeyPacket_isUsed = 1u;
                        // XML: emit base64 encoded value
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                        {
                            static const char encoding_table[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
                            static const int mod_table[] = {0, 2, 1};
                            size_t output_length = 4 * ((PGPDataType->choice_1.PGPKeyPacket.bytesLen + 2) / 3);
                            unsigned char* encoded_data = (unsigned char*)malloc(output_length + 1);
                            if (encoded_data != NULL)
                            {
                                size_t i, j;
                                for (i = 0, j = 0; i < PGPDataType->choice_1.PGPKeyPacket.bytesLen;)
                                {
                                    uint32_t a = i < PGPDataType->choice_1.PGPKeyPacket.bytesLen ? PGPDataType->choice_1.PGPKeyPacket.bytes[i++] : 0;
                                    uint32_t b = i < PGPDataType->choice_1.PGPKeyPacket.bytesLen ? PGPDataType->choice_1.PGPKeyPacket.bytes[i++] : 0;
                                    uint32_t c = i < PGPDataType->choice_1.PGPKeyPacket.bytesLen ? PGPDataType->choice_1.PGPKeyPacket.bytes[i++] : 0;
                                    uint32_t triple = (a << 16) + (b << 8) + c;
                                    encoded_data[j++] = encoding_table[(triple >> 18) & 0x3F];
                                    encoded_data[j++] = encoding_table[(triple >> 12) & 0x3F];
                                    encoded_data[j++] = encoding_table[(triple >> 6) & 0x3F];
                                    encoded_data[j++] = encoding_table[triple & 0x3F];
                                }
                                for (i = 0; i < (size_t)mod_table[PGPDataType->choice_1.PGPKeyPacket.bytesLen % 3]; i++)
                                {
                                    encoded_data[output_length - 1 - i] = '=';
                                }
                                xml_write(xmlOut, xmlOut_size, xmlOut_pos, (char*)encoded_data, output_length);
                                free(encoded_data);
                            }
                            else
                            {
                                xml_write(xmlOut, xmlOut_size, xmlOut_pos, "(base64-alloc-failed)", 21);
                            }
                        }
                        grammar_id = 24;
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns1:PGPKeyPacket>", 19);
                    }
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 23:
            // Grammar: ID=23; read/write bits=3; START (PGPKeyPacket), START (ANY), END Element, START (ANY)
            error = exi_basetypes_decoder_nbit_uint(stream, 3, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: START (PGPKeyPacket, base64Binary (base64Binary)); next=24
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns1:PGPKeyPacket", 17);
                        (void)xml_tag_start;
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &PGPDataType->choice_1.PGPKeyPacket.bytesLen, &PGPDataType->choice_1.PGPKeyPacket.bytes[0], iso20_acdp_base64Binary_BYTES_SIZE);
                    if (error == 0)
                    {
                        PGPDataType->choice_1.PGPKeyPacket_isUsed = 1u;
                        // XML: emit base64 encoded value
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                        {
                            static const char encoding_table[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
                            static const int mod_table[] = {0, 2, 1};
                            size_t output_length = 4 * ((PGPDataType->choice_1.PGPKeyPacket.bytesLen + 2) / 3);
                            unsigned char* encoded_data = (unsigned char*)malloc(output_length + 1);
                            if (encoded_data != NULL)
                            {
                                size_t i, j;
                                for (i = 0, j = 0; i < PGPDataType->choice_1.PGPKeyPacket.bytesLen;)
                                {
                                    uint32_t a = i < PGPDataType->choice_1.PGPKeyPacket.bytesLen ? PGPDataType->choice_1.PGPKeyPacket.bytes[i++] : 0;
                                    uint32_t b = i < PGPDataType->choice_1.PGPKeyPacket.bytesLen ? PGPDataType->choice_1.PGPKeyPacket.bytes[i++] : 0;
                                    uint32_t c = i < PGPDataType->choice_1.PGPKeyPacket.bytesLen ? PGPDataType->choice_1.PGPKeyPacket.bytes[i++] : 0;
                                    uint32_t triple = (a << 16) + (b << 8) + c;
                                    encoded_data[j++] = encoding_table[(triple >> 18) & 0x3F];
                                    encoded_data[j++] = encoding_table[(triple >> 12) & 0x3F];
                                    encoded_data[j++] = encoding_table[(triple >> 6) & 0x3F];
                                    encoded_data[j++] = encoding_table[triple & 0x3F];
                                }
                                for (i = 0; i < (size_t)mod_table[PGPDataType->choice_1.PGPKeyPacket.bytesLen % 3]; i++)
                                {
                                    encoded_data[output_length - 1 - i] = '=';
                                }
                                xml_write(xmlOut, xmlOut_size, xmlOut_pos, (char*)encoded_data, output_length);
                                free(encoded_data);
                            }
                            else
                            {
                                xml_write(xmlOut, xmlOut_size, xmlOut_pos, "(base64-alloc-failed)", 21);
                            }
                        }
                        grammar_id = 24;
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns1:PGPKeyPacket>", 19);
                    }
                    break;
                case 1:
                    // Event: START (ANY, anyType (base64Binary)); next=25
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ANY", 4);
                        (void)xml_tag_start;
                    // decode: event not accepted
                    error = EXI_ERROR__UNKNOWN_EVENT_FOR_DECODING;
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ANY>", 6);
                    }
                    break;
                case 2:
                    // Event: END Element; next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                case 3:
                    // Event: START (ANY, anyType (base64Binary)); next=25
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ANY", 4);
                        (void)xml_tag_start;
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &PGPDataType->choice_1.ANY.bytesLen, &PGPDataType->choice_1.ANY.bytes[0], iso20_acdp_anyType_BYTES_SIZE);
                    if (error == 0)
                    {
                        PGPDataType->choice_1.ANY_isUsed = 1u;
                        // XML: emit base64 encoded value
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                        {
                            static const char encoding_table[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
                            static const int mod_table[] = {0, 2, 1};
                            size_t output_length = 4 * ((PGPDataType->choice_1.ANY.bytesLen + 2) / 3);
                            unsigned char* encoded_data = (unsigned char*)malloc(output_length + 1);
                            if (encoded_data != NULL)
                            {
                                size_t i, j;
                                for (i = 0, j = 0; i < PGPDataType->choice_1.ANY.bytesLen;)
                                {
                                    uint32_t a = i < PGPDataType->choice_1.ANY.bytesLen ? PGPDataType->choice_1.ANY.bytes[i++] : 0;
                                    uint32_t b = i < PGPDataType->choice_1.ANY.bytesLen ? PGPDataType->choice_1.ANY.bytes[i++] : 0;
                                    uint32_t c = i < PGPDataType->choice_1.ANY.bytesLen ? PGPDataType->choice_1.ANY.bytes[i++] : 0;
                                    uint32_t triple = (a << 16) + (b << 8) + c;
                                    encoded_data[j++] = encoding_table[(triple >> 18) & 0x3F];
                                    encoded_data[j++] = encoding_table[(triple >> 12) & 0x3F];
                                    encoded_data[j++] = encoding_table[(triple >> 6) & 0x3F];
                                    encoded_data[j++] = encoding_table[triple & 0x3F];
                                }
                                for (i = 0; i < (size_t)mod_table[PGPDataType->choice_1.ANY.bytesLen % 3]; i++)
                                {
                                    encoded_data[output_length - 1 - i] = '=';
                                }
                                xml_write(xmlOut, xmlOut_size, xmlOut_pos, (char*)encoded_data, output_length);
                                free(encoded_data);
                            }
                            else
                            {
                                xml_write(xmlOut, xmlOut_size, xmlOut_pos, "(base64-alloc-failed)", 21);
                            }
                        }
                        grammar_id = 25;
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ANY>", 6);
                    }
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 24:
            // Grammar: ID=24; read/write bits=3; START (ANY), END Element, END Element, START (ANY)
            error = exi_basetypes_decoder_nbit_uint(stream, 3, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: START (ANY, anyType (base64Binary)); next=25
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ANY", 4);
                        (void)xml_tag_start;
                    // decode: event not accepted
                    error = EXI_ERROR__UNKNOWN_EVENT_FOR_DECODING;
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ANY>", 6);
                    }
                    break;
                case 1:
                    // Event: END Element; next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                case 2:
                    // Event: END Element; next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                case 3:
                    // Event: START (ANY, anyType (base64Binary)); next=25
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ANY", 4);
                        (void)xml_tag_start;
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &PGPDataType->choice_1.ANY.bytesLen, &PGPDataType->choice_1.ANY.bytes[0], iso20_acdp_anyType_BYTES_SIZE);
                    if (error == 0)
                    {
                        PGPDataType->choice_1.ANY_isUsed = 1u;
                        // XML: emit base64 encoded value
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                        {
                            static const char encoding_table[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
                            static const int mod_table[] = {0, 2, 1};
                            size_t output_length = 4 * ((PGPDataType->choice_1.ANY.bytesLen + 2) / 3);
                            unsigned char* encoded_data = (unsigned char*)malloc(output_length + 1);
                            if (encoded_data != NULL)
                            {
                                size_t i, j;
                                for (i = 0, j = 0; i < PGPDataType->choice_1.ANY.bytesLen;)
                                {
                                    uint32_t a = i < PGPDataType->choice_1.ANY.bytesLen ? PGPDataType->choice_1.ANY.bytes[i++] : 0;
                                    uint32_t b = i < PGPDataType->choice_1.ANY.bytesLen ? PGPDataType->choice_1.ANY.bytes[i++] : 0;
                                    uint32_t c = i < PGPDataType->choice_1.ANY.bytesLen ? PGPDataType->choice_1.ANY.bytes[i++] : 0;
                                    uint32_t triple = (a << 16) + (b << 8) + c;
                                    encoded_data[j++] = encoding_table[(triple >> 18) & 0x3F];
                                    encoded_data[j++] = encoding_table[(triple >> 12) & 0x3F];
                                    encoded_data[j++] = encoding_table[(triple >> 6) & 0x3F];
                                    encoded_data[j++] = encoding_table[triple & 0x3F];
                                }
                                for (i = 0; i < (size_t)mod_table[PGPDataType->choice_1.ANY.bytesLen % 3]; i++)
                                {
                                    encoded_data[output_length - 1 - i] = '=';
                                }
                                xml_write(xmlOut, xmlOut_size, xmlOut_pos, (char*)encoded_data, output_length);
                                free(encoded_data);
                            }
                            else
                            {
                                xml_write(xmlOut, xmlOut_size, xmlOut_pos, "(base64-alloc-failed)", 21);
                            }
                        }
                        grammar_id = 25;
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ANY>", 6);
                    }
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 25:
            // Grammar: ID=25; read/write bits=1; START (PGPKeyPacket)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: START (PGPKeyPacket, base64Binary (base64Binary)); next=26
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns1:PGPKeyPacket", 17);
                        (void)xml_tag_start;
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &PGPDataType->choice_2.PGPKeyPacket.bytesLen, &PGPDataType->choice_2.PGPKeyPacket.bytes[0], iso20_acdp_base64Binary_BYTES_SIZE);
                    if (error == 0)
                    {
                        // XML: emit base64 encoded value
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                        {
                            static const char encoding_table[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
                            static const int mod_table[] = {0, 2, 1};
                            size_t output_length = 4 * ((PGPDataType->choice_2.PGPKeyPacket.bytesLen + 2) / 3);
                            unsigned char* encoded_data = (unsigned char*)malloc(output_length + 1);
                            if (encoded_data != NULL)
                            {
                                size_t i, j;
                                for (i = 0, j = 0; i < PGPDataType->choice_2.PGPKeyPacket.bytesLen;)
                                {
                                    uint32_t a = i < PGPDataType->choice_2.PGPKeyPacket.bytesLen ? PGPDataType->choice_2.PGPKeyPacket.bytes[i++] : 0;
                                    uint32_t b = i < PGPDataType->choice_2.PGPKeyPacket.bytesLen ? PGPDataType->choice_2.PGPKeyPacket.bytes[i++] : 0;
                                    uint32_t c = i < PGPDataType->choice_2.PGPKeyPacket.bytesLen ? PGPDataType->choice_2.PGPKeyPacket.bytes[i++] : 0;
                                    uint32_t triple = (a << 16) + (b << 8) + c;
                                    encoded_data[j++] = encoding_table[(triple >> 18) & 0x3F];
                                    encoded_data[j++] = encoding_table[(triple >> 12) & 0x3F];
                                    encoded_data[j++] = encoding_table[(triple >> 6) & 0x3F];
                                    encoded_data[j++] = encoding_table[triple & 0x3F];
                                }
                                for (i = 0; i < (size_t)mod_table[PGPDataType->choice_2.PGPKeyPacket.bytesLen % 3]; i++)
                                {
                                    encoded_data[output_length - 1 - i] = '=';
                                }
                                xml_write(xmlOut, xmlOut_size, xmlOut_pos, (char*)encoded_data, output_length);
                                free(encoded_data);
                            }
                            else
                            {
                                xml_write(xmlOut, xmlOut_size, xmlOut_pos, "(base64-alloc-failed)", 21);
                            }
                        }
                        grammar_id = 26;
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns1:PGPKeyPacket>", 19);
                    }
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 26:
            // Grammar: ID=26; read/write bits=2; START (ANY), END Element, START (ANY)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: START (ANY, anyType (base64Binary)); next=25
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ANY", 4);
                        (void)xml_tag_start;
                    // decode: event not accepted
                    error = EXI_ERROR__UNKNOWN_EVENT_FOR_DECODING;
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ANY>", 6);
                    }
                    break;
                case 1:
                    // Event: END Element; next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                case 2:
                    // Event: START (ANY, anyType (base64Binary)); next=25
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ANY", 4);
                        (void)xml_tag_start;
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &PGPDataType->choice_2.ANY.bytesLen, &PGPDataType->choice_2.ANY.bytes[0], iso20_acdp_anyType_BYTES_SIZE);
                    if (error == 0)
                    {
                        PGPDataType->choice_2.ANY_isUsed = 1u;
                        // XML: emit base64 encoded value
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                        {
                            static const char encoding_table[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
                            static const int mod_table[] = {0, 2, 1};
                            size_t output_length = 4 * ((PGPDataType->choice_2.ANY.bytesLen + 2) / 3);
                            unsigned char* encoded_data = (unsigned char*)malloc(output_length + 1);
                            if (encoded_data != NULL)
                            {
                                size_t i, j;
                                for (i = 0, j = 0; i < PGPDataType->choice_2.ANY.bytesLen;)
                                {
                                    uint32_t a = i < PGPDataType->choice_2.ANY.bytesLen ? PGPDataType->choice_2.ANY.bytes[i++] : 0;
                                    uint32_t b = i < PGPDataType->choice_2.ANY.bytesLen ? PGPDataType->choice_2.ANY.bytes[i++] : 0;
                                    uint32_t c = i < PGPDataType->choice_2.ANY.bytesLen ? PGPDataType->choice_2.ANY.bytes[i++] : 0;
                                    uint32_t triple = (a << 16) + (b << 8) + c;
                                    encoded_data[j++] = encoding_table[(triple >> 18) & 0x3F];
                                    encoded_data[j++] = encoding_table[(triple >> 12) & 0x3F];
                                    encoded_data[j++] = encoding_table[(triple >> 6) & 0x3F];
                                    encoded_data[j++] = encoding_table[triple & 0x3F];
                                }
                                for (i = 0; i < (size_t)mod_table[PGPDataType->choice_2.ANY.bytesLen % 3]; i++)
                                {
                                    encoded_data[output_length - 1 - i] = '=';
                                }
                                xml_write(xmlOut, xmlOut_size, xmlOut_pos, (char*)encoded_data, output_length);
                                free(encoded_data);
                            }
                            else
                            {
                                xml_write(xmlOut, xmlOut_size, xmlOut_pos, "(base64-alloc-failed)", 21);
                            }
                        }
                        grammar_id = 25;
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ANY>", 6);
                    }
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: END Element; next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={http://www.w3.org/2000/09/xmldsig#}Reference; type={http://www.w3.org/2000/09/xmldsig#}ReferenceType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: Id, ID (0, 1); Type, anyURI (0, 1); URI, anyURI (0, 1); Transforms, TransformsType (0, 1); DigestMethod, DigestMethodType (1, 1); DigestValue, DigestValueType (1, 1);
static int decode_iso20_acdp_ReferenceType(exi_bitstream_t* stream, struct iso20_acdp_ReferenceType* ReferenceType, char* xmlOut, size_t xmlOut_size, size_t* xmlOut_pos) {
    int grammar_id = 27;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_acdp_ReferenceType(ReferenceType);

    while (!done)
    {
        switch (grammar_id)
        {
        case 27:
            // Grammar: ID=27; read/write bits=3; START (Id), START (Type), START (URI), START (Transforms), START (DigestMethod)
            error = exi_basetypes_decoder_nbit_uint(stream, 3, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: START (Id, ID (NCName)); next=28
                    // XML: attribute
                    xml_write(xmlOut, xmlOut_size, xmlOut_pos, " Id=\"", 5);
                    // decode: string (len, characters) (Attribute)
                    error = exi_basetypes_decoder_uint_16(stream, &ReferenceType->Id.charactersLen);
                    if (error == 0)
                    {
                        if (ReferenceType->Id.charactersLen >= 2)
                        {
                            // string tables and table partitions are not supported, so the length has to be decremented by 2
                            ReferenceType->Id.charactersLen -= 2;
                            error = exi_basetypes_decoder_characters(stream, ReferenceType->Id.charactersLen, ReferenceType->Id.characters, iso20_acdp_Id_CHARACTER_SIZE);
                            if (error == 0)
                            {
                                // XML: emit string value
                                xml_write_escaped_attr(xmlOut, xmlOut_size, xmlOut_pos, ReferenceType->Id.characters, ReferenceType->Id.charactersLen);
                            }
                        }
                        else
                        {
                            // the string seems to be in the table, but this is not supported
                            error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                        }
                    }
                    ReferenceType->Id_isUsed = 1u;
                    grammar_id = 28;
                    xml_write(xmlOut, xmlOut_size, xmlOut_pos, "\"", 1);
                    break;
                case 1:
                    // Event: START (Type, anyURI (anyURI)); next=29
                    // XML: attribute
                    xml_write(xmlOut, xmlOut_size, xmlOut_pos, " Type=\"", 7);
                    // decode: string (len, characters) (Attribute)
                    error = exi_basetypes_decoder_uint_16(stream, &ReferenceType->Type.charactersLen);
                    if (error == 0)
                    {
                        if (ReferenceType->Type.charactersLen >= 2)
                        {
                            // string tables and table partitions are not supported, so the length has to be decremented by 2
                            ReferenceType->Type.charactersLen -= 2;
                            error = exi_basetypes_decoder_characters(stream, ReferenceType->Type.charactersLen, ReferenceType->Type.characters, iso20_acdp_Type_CHARACTER_SIZE);
                            if (error == 0)
                            {
                                // XML: emit string value
                                xml_write_escaped_attr(xmlOut, xmlOut_size, xmlOut_pos, ReferenceType->Type.characters, ReferenceType->Type.charactersLen);
                            }
                        }
                        else
                        {
                            // the string seems to be in the table, but this is not supported
                            error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                        }
                    }
                    ReferenceType->Type_isUsed = 1u;
                    grammar_id = 29;
                    xml_write(xmlOut, xmlOut_size, xmlOut_pos, "\"", 1);
                    break;
                case 2:
                    // Event: START (URI, anyURI (anyURI)); next=30
                    // XML: attribute
                    xml_write(xmlOut, xmlOut_size, xmlOut_pos, " URI=\"", 6);
                    // decode: string (len, characters) (Attribute)
                    error = exi_basetypes_decoder_uint_16(stream, &ReferenceType->URI.charactersLen);
                    if (error == 0)
                    {
                        if (ReferenceType->URI.charactersLen >= 2)
                        {
                            // string tables and table partitions are not supported, so the length has to be decremented by 2
                            ReferenceType->URI.charactersLen -= 2;
                            error = exi_basetypes_decoder_characters(stream, ReferenceType->URI.charactersLen, ReferenceType->URI.characters, iso20_acdp_URI_CHARACTER_SIZE);
                            if (error == 0)
                            {
                                // XML: emit string value
                                xml_write_escaped_attr(xmlOut, xmlOut_size, xmlOut_pos, ReferenceType->URI.characters, ReferenceType->URI.charactersLen);
                            }
                        }
                        else
                        {
                            // the string seems to be in the table, but this is not supported
                            error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                        }
                    }
                    ReferenceType->URI_isUsed = 1u;
                    grammar_id = 30;
                    xml_write(xmlOut, xmlOut_size, xmlOut_pos, "\"", 1);
                    break;
                case 3:
                    // Event: START (Transforms, TransformsType (TransformsType)); next=31
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns1:Transforms", 15);
                        (void)xml_tag_start;
                    // decode: element
                    error = decode_iso20_acdp_TransformsType(stream, &ReferenceType->Transforms, xmlOut, xmlOut_size, xmlOut_pos);
                    if (error == 0)
                    {
                        ReferenceType->Transforms_isUsed = 1u;
                        grammar_id = 31;
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns1:Transforms>", 17);
                    }
                    break;
                case 4:
                    // Event: START (DigestMethod, DigestMethodType (DigestMethodType)); next=32
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns1:DigestMethod", 17);
                        (void)xml_tag_start;
                    // decode: element
                    error = decode_iso20_acdp_DigestMethodType(stream, &ReferenceType->DigestMethod, xmlOut, xmlOut_size, xmlOut_pos);
                    if (error == 0)
                    {
                        grammar_id = 32;
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns1:DigestMethod>", 19);
                    }
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 28:
            // Grammar: ID=28; read/write bits=3; START (Type), START (URI), START (Transforms), START (DigestMethod)
            error = exi_basetypes_decoder_nbit_uint(stream, 3, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: START (Type, anyURI (anyURI)); next=29
                    // XML: attribute
                    xml_write(xmlOut, xmlOut_size, xmlOut_pos, " Type=\"", 7);
                    // decode: string (len, characters) (Attribute)
                    error = exi_basetypes_decoder_uint_16(stream, &ReferenceType->Type.charactersLen);
                    if (error == 0)
                    {
                        if (ReferenceType->Type.charactersLen >= 2)
                        {
                            // string tables and table partitions are not supported, so the length has to be decremented by 2
                            ReferenceType->Type.charactersLen -= 2;
                            error = exi_basetypes_decoder_characters(stream, ReferenceType->Type.charactersLen, ReferenceType->Type.characters, iso20_acdp_Type_CHARACTER_SIZE);
                            if (error == 0)
                            {
                                // XML: emit string value
                                xml_write_escaped_attr(xmlOut, xmlOut_size, xmlOut_pos, ReferenceType->Type.characters, ReferenceType->Type.charactersLen);
                            }
                        }
                        else
                        {
                            // the string seems to be in the table, but this is not supported
                            error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                        }
                    }
                    ReferenceType->Type_isUsed = 1u;
                    grammar_id = 29;
                    xml_write(xmlOut, xmlOut_size, xmlOut_pos, "\"", 1);
                    break;
                case 1:
                    // Event: START (URI, anyURI (anyURI)); next=30
                    // XML: attribute
                    xml_write(xmlOut, xmlOut_size, xmlOut_pos, " URI=\"", 6);
                    // decode: string (len, characters) (Attribute)
                    error = exi_basetypes_decoder_uint_16(stream, &ReferenceType->URI.charactersLen);
                    if (error == 0)
                    {
                        if (ReferenceType->URI.charactersLen >= 2)
                        {
                            // string tables and table partitions are not supported, so the length has to be decremented by 2
                            ReferenceType->URI.charactersLen -= 2;
                            error = exi_basetypes_decoder_characters(stream, ReferenceType->URI.charactersLen, ReferenceType->URI.characters, iso20_acdp_URI_CHARACTER_SIZE);
                            if (error == 0)
                            {
                                // XML: emit string value
                                xml_write_escaped_attr(xmlOut, xmlOut_size, xmlOut_pos, ReferenceType->URI.characters, ReferenceType->URI.charactersLen);
                            }
                        }
                        else
                        {
                            // the string seems to be in the table, but this is not supported
                            error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                        }
                    }
                    ReferenceType->URI_isUsed = 1u;
                    grammar_id = 30;
                    xml_write(xmlOut, xmlOut_size, xmlOut_pos, "\"", 1);
                    break;
                case 2:
                    // Event: START (Transforms, TransformsType (TransformsType)); next=31
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns1:Transforms", 15);
                        (void)xml_tag_start;
                    // decode: element
                    error = decode_iso20_acdp_TransformsType(stream, &ReferenceType->Transforms, xmlOut, xmlOut_size, xmlOut_pos);
                    if (error == 0)
                    {
                        ReferenceType->Transforms_isUsed = 1u;
                        grammar_id = 31;
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns1:Transforms>", 17);
                    }
                    break;
                case 3:
                    // Event: START (DigestMethod, DigestMethodType (DigestMethodType)); next=32
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns1:DigestMethod", 17);
                        (void)xml_tag_start;
                    // decode: element
                    error = decode_iso20_acdp_DigestMethodType(stream, &ReferenceType->DigestMethod, xmlOut, xmlOut_size, xmlOut_pos);
                    if (error == 0)
                    {
                        grammar_id = 32;
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns1:DigestMethod>", 19);
                    }
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 29:
            // Grammar: ID=29; read/write bits=2; START (URI), START (Transforms), START (DigestMethod)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: START (URI, anyURI (anyURI)); next=30
                    // XML: attribute
                    xml_write(xmlOut, xmlOut_size, xmlOut_pos, " URI=\"", 6);
                    // decode: string (len, characters) (Attribute)
                    error = exi_basetypes_decoder_uint_16(stream, &ReferenceType->URI.charactersLen);
                    if (error == 0)
                    {
                        if (ReferenceType->URI.charactersLen >= 2)
                        {
                            // string tables and table partitions are not supported, so the length has to be decremented by 2
                            ReferenceType->URI.charactersLen -= 2;
                            error = exi_basetypes_decoder_characters(stream, ReferenceType->URI.charactersLen, ReferenceType->URI.characters, iso20_acdp_URI_CHARACTER_SIZE);
                            if (error == 0)
                            {
                                // XML: emit string value
                                xml_write_escaped_attr(xmlOut, xmlOut_size, xmlOut_pos, ReferenceType->URI.characters, ReferenceType->URI.charactersLen);
                            }
                        }
                        else
                        {
                            // the string seems to be in the table, but this is not supported
                            error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                        }
                    }
                    ReferenceType->URI_isUsed = 1u;
                    grammar_id = 30;
                    xml_write(xmlOut, xmlOut_size, xmlOut_pos, "\"", 1);
                    break;
                case 1:
                    // Event: START (Transforms, TransformsType (TransformsType)); next=31
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns1:Transforms", 15);
                        (void)xml_tag_start;
                    // decode: element
                    error = decode_iso20_acdp_TransformsType(stream, &ReferenceType->Transforms, xmlOut, xmlOut_size, xmlOut_pos);
                    if (error == 0)
                    {
                        ReferenceType->Transforms_isUsed = 1u;
                        grammar_id = 31;
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns1:Transforms>", 17);
                    }
                    break;
                case 2:
                    // Event: START (DigestMethod, DigestMethodType (DigestMethodType)); next=32
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns1:DigestMethod", 17);
                        (void)xml_tag_start;
                    // decode: element
                    error = decode_iso20_acdp_DigestMethodType(stream, &ReferenceType->DigestMethod, xmlOut, xmlOut_size, xmlOut_pos);
                    if (error == 0)
                    {
                        grammar_id = 32;
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns1:DigestMethod>", 19);
                    }
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 30:
            // Grammar: ID=30; read/write bits=2; START (Transforms), START (DigestMethod)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: START (Transforms, TransformsType (TransformsType)); next=31
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns1:Transforms", 15);
                        (void)xml_tag_start;
                    // decode: element
                    error = decode_iso20_acdp_TransformsType(stream, &ReferenceType->Transforms, xmlOut, xmlOut_size, xmlOut_pos);
                    if (error == 0)
                    {
                        ReferenceType->Transforms_isUsed = 1u;
                        grammar_id = 31;
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns1:Transforms>", 17);
                    }
                    break;
                case 1:
                    // Event: START (DigestMethod, DigestMethodType (DigestMethodType)); next=32
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns1:DigestMethod", 17);
                        (void)xml_tag_start;
                    // decode: element
                    error = decode_iso20_acdp_DigestMethodType(stream, &ReferenceType->DigestMethod, xmlOut, xmlOut_size, xmlOut_pos);
                    if (error == 0)
                    {
                        grammar_id = 32;
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns1:DigestMethod>", 19);
                    }
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 31:
            // Grammar: ID=31; read/write bits=1; START (DigestMethod)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: START (DigestMethod, DigestMethodType (DigestMethodType)); next=32
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns1:DigestMethod", 17);
                        (void)xml_tag_start;
                    // decode: element
                    error = decode_iso20_acdp_DigestMethodType(stream, &ReferenceType->DigestMethod, xmlOut, xmlOut_size, xmlOut_pos);
                    if (error == 0)
                    {
                        grammar_id = 32;
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns1:DigestMethod>", 19);
                    }
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 32:
            // Grammar: ID=32; read/write bits=1; START (DigestValue)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: START (DigestValue, DigestValueType (base64Binary)); next=2
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns1:DigestValue", 16);
                        (void)xml_tag_start;
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &ReferenceType->DigestValue.bytesLen, &ReferenceType->DigestValue.bytes[0], iso20_acdp_DigestValueType_BYTES_SIZE);
                    if (error == 0)
                    {
                        // XML: emit base64 encoded value
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                        {
                            static const char encoding_table[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
                            static const int mod_table[] = {0, 2, 1};
                            size_t output_length = 4 * ((ReferenceType->DigestValue.bytesLen + 2) / 3);
                            unsigned char* encoded_data = (unsigned char*)malloc(output_length + 1);
                            if (encoded_data != NULL)
                            {
                                size_t i, j;
                                for (i = 0, j = 0; i < ReferenceType->DigestValue.bytesLen;)
                                {
                                    uint32_t a = i < ReferenceType->DigestValue.bytesLen ? ReferenceType->DigestValue.bytes[i++] : 0;
                                    uint32_t b = i < ReferenceType->DigestValue.bytesLen ? ReferenceType->DigestValue.bytes[i++] : 0;
                                    uint32_t c = i < ReferenceType->DigestValue.bytesLen ? ReferenceType->DigestValue.bytes[i++] : 0;
                                    uint32_t triple = (a << 16) + (b << 8) + c;
                                    encoded_data[j++] = encoding_table[(triple >> 18) & 0x3F];
                                    encoded_data[j++] = encoding_table[(triple >> 12) & 0x3F];
                                    encoded_data[j++] = encoding_table[(triple >> 6) & 0x3F];
                                    encoded_data[j++] = encoding_table[triple & 0x3F];
                                }
                                for (i = 0; i < (size_t)mod_table[ReferenceType->DigestValue.bytesLen % 3]; i++)
                                {
                                    encoded_data[output_length - 1 - i] = '=';
                                }
                                xml_write(xmlOut, xmlOut_size, xmlOut_pos, (char*)encoded_data, output_length);
                                free(encoded_data);
                            }
                            else
                            {
                                xml_write(xmlOut, xmlOut_size, xmlOut_pos, "(base64-alloc-failed)", 21);
                            }
                        }
                        grammar_id = 2;
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns1:DigestValue>", 18);
                    }
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: END Element; next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={http://www.w3.org/2000/09/xmldsig#}RetrievalMethod; type={http://www.w3.org/2000/09/xmldsig#}RetrievalMethodType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: Type, anyURI (0, 1); URI, anyURI (0, 1); Transforms, TransformsType (0, 1);
static int decode_iso20_acdp_RetrievalMethodType(exi_bitstream_t* stream, struct iso20_acdp_RetrievalMethodType* RetrievalMethodType, char* xmlOut, size_t xmlOut_size, size_t* xmlOut_pos) {
    int grammar_id = 33;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_acdp_RetrievalMethodType(RetrievalMethodType);

    while (!done)
    {
        switch (grammar_id)
        {
        case 33:
            // Grammar: ID=33; read/write bits=3; START (Type), START (URI), START (Transforms), END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 3, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: START (Type, anyURI (anyURI)); next=34
                    // XML: attribute
                    xml_write(xmlOut, xmlOut_size, xmlOut_pos, " Type=\"", 7);
                    // decode: string (len, characters) (Attribute)
                    error = exi_basetypes_decoder_uint_16(stream, &RetrievalMethodType->Type.charactersLen);
                    if (error == 0)
                    {
                        if (RetrievalMethodType->Type.charactersLen >= 2)
                        {
                            // string tables and table partitions are not supported, so the length has to be decremented by 2
                            RetrievalMethodType->Type.charactersLen -= 2;
                            error = exi_basetypes_decoder_characters(stream, RetrievalMethodType->Type.charactersLen, RetrievalMethodType->Type.characters, iso20_acdp_Type_CHARACTER_SIZE);
                            if (error == 0)
                            {
                                // XML: emit string value
                                xml_write_escaped_attr(xmlOut, xmlOut_size, xmlOut_pos, RetrievalMethodType->Type.characters, RetrievalMethodType->Type.charactersLen);
                            }
                        }
                        else
                        {
                            // the string seems to be in the table, but this is not supported
                            error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                        }
                    }
                    RetrievalMethodType->Type_isUsed = 1u;
                    grammar_id = 34;
                    xml_write(xmlOut, xmlOut_size, xmlOut_pos, "\"", 1);
                    break;
                case 1:
                    // Event: START (URI, anyURI (anyURI)); next=35
                    // XML: attribute
                    xml_write(xmlOut, xmlOut_size, xmlOut_pos, " URI=\"", 6);
                    // decode: string (len, characters) (Attribute)
                    error = exi_basetypes_decoder_uint_16(stream, &RetrievalMethodType->URI.charactersLen);
                    if (error == 0)
                    {
                        if (RetrievalMethodType->URI.charactersLen >= 2)
                        {
                            // string tables and table partitions are not supported, so the length has to be decremented by 2
                            RetrievalMethodType->URI.charactersLen -= 2;
                            error = exi_basetypes_decoder_characters(stream, RetrievalMethodType->URI.charactersLen, RetrievalMethodType->URI.characters, iso20_acdp_URI_CHARACTER_SIZE);
                            if (error == 0)
                            {
                                // XML: emit string value
                                xml_write_escaped_attr(xmlOut, xmlOut_size, xmlOut_pos, RetrievalMethodType->URI.characters, RetrievalMethodType->URI.charactersLen);
                            }
                        }
                        else
                        {
                            // the string seems to be in the table, but this is not supported
                            error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                        }
                    }
                    RetrievalMethodType->URI_isUsed = 1u;
                    grammar_id = 35;
                    xml_write(xmlOut, xmlOut_size, xmlOut_pos, "\"", 1);
                    break;
                case 2:
                    // Event: START (Transforms, TransformsType (TransformsType)); next=2
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns1:Transforms", 15);
                        (void)xml_tag_start;
                    // decode: element
                    error = decode_iso20_acdp_TransformsType(stream, &RetrievalMethodType->Transforms, xmlOut, xmlOut_size, xmlOut_pos);
                    if (error == 0)
                    {
                        RetrievalMethodType->Transforms_isUsed = 1u;
                        grammar_id = 2;
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns1:Transforms>", 17);
                    }
                    break;
                case 3:
                    // Event: END Element; next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 34:
            // Grammar: ID=34; read/write bits=2; START (URI), START (Transforms), END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: START (URI, anyURI (anyURI)); next=35
                    // XML: attribute
                    xml_write(xmlOut, xmlOut_size, xmlOut_pos, " URI=\"", 6);
                    // decode: string (len, characters) (Attribute)
                    error = exi_basetypes_decoder_uint_16(stream, &RetrievalMethodType->URI.charactersLen);
                    if (error == 0)
                    {
                        if (RetrievalMethodType->URI.charactersLen >= 2)
                        {
                            // string tables and table partitions are not supported, so the length has to be decremented by 2
                            RetrievalMethodType->URI.charactersLen -= 2;
                            error = exi_basetypes_decoder_characters(stream, RetrievalMethodType->URI.charactersLen, RetrievalMethodType->URI.characters, iso20_acdp_URI_CHARACTER_SIZE);
                            if (error == 0)
                            {
                                // XML: emit string value
                                xml_write_escaped_attr(xmlOut, xmlOut_size, xmlOut_pos, RetrievalMethodType->URI.characters, RetrievalMethodType->URI.charactersLen);
                            }
                        }
                        else
                        {
                            // the string seems to be in the table, but this is not supported
                            error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                        }
                    }
                    RetrievalMethodType->URI_isUsed = 1u;
                    grammar_id = 35;
                    xml_write(xmlOut, xmlOut_size, xmlOut_pos, "\"", 1);
                    break;
                case 1:
                    // Event: START (Transforms, TransformsType (TransformsType)); next=2
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns1:Transforms", 15);
                        (void)xml_tag_start;
                    // decode: element
                    error = decode_iso20_acdp_TransformsType(stream, &RetrievalMethodType->Transforms, xmlOut, xmlOut_size, xmlOut_pos);
                    if (error == 0)
                    {
                        RetrievalMethodType->Transforms_isUsed = 1u;
                        grammar_id = 2;
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns1:Transforms>", 17);
                    }
                    break;
                case 2:
                    // Event: END Element; next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 35:
            // Grammar: ID=35; read/write bits=2; START (Transforms), END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: START (Transforms, TransformsType (TransformsType)); next=2
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns1:Transforms", 15);
                        (void)xml_tag_start;
                    // decode: element
                    error = decode_iso20_acdp_TransformsType(stream, &RetrievalMethodType->Transforms, xmlOut, xmlOut_size, xmlOut_pos);
                    if (error == 0)
                    {
                        RetrievalMethodType->Transforms_isUsed = 1u;
                        grammar_id = 2;
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns1:Transforms>", 17);
                    }
                    break;
                case 1:
                    // Event: END Element; next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: END Element; next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={http://www.w3.org/2000/09/xmldsig#}SPKIData; type={http://www.w3.org/2000/09/xmldsig#}SPKIDataType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: SPKISexp, base64Binary (1, 1); ANY, anyType (0, 1);
static int decode_iso20_acdp_SPKIDataType(exi_bitstream_t* stream, struct iso20_acdp_SPKIDataType* SPKIDataType, char* xmlOut, size_t xmlOut_size, size_t* xmlOut_pos) {
    int grammar_id = 36;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_acdp_SPKIDataType(SPKIDataType);

    while (!done)
    {
        switch (grammar_id)
        {
        case 36:
            // Grammar: ID=36; read/write bits=1; START (SPKISexp)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: START (SPKISexp, base64Binary (base64Binary)); next=37
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns1:SPKISexp", 13);
                        (void)xml_tag_start;
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &SPKIDataType->SPKISexp.bytesLen, &SPKIDataType->SPKISexp.bytes[0], iso20_acdp_base64Binary_BYTES_SIZE);
                    if (error == 0)
                    {
                        // XML: emit base64 encoded value
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                        {
                            static const char encoding_table[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
                            static const int mod_table[] = {0, 2, 1};
                            size_t output_length = 4 * ((SPKIDataType->SPKISexp.bytesLen + 2) / 3);
                            unsigned char* encoded_data = (unsigned char*)malloc(output_length + 1);
                            if (encoded_data != NULL)
                            {
                                size_t i, j;
                                for (i = 0, j = 0; i < SPKIDataType->SPKISexp.bytesLen;)
                                {
                                    uint32_t a = i < SPKIDataType->SPKISexp.bytesLen ? SPKIDataType->SPKISexp.bytes[i++] : 0;
                                    uint32_t b = i < SPKIDataType->SPKISexp.bytesLen ? SPKIDataType->SPKISexp.bytes[i++] : 0;
                                    uint32_t c = i < SPKIDataType->SPKISexp.bytesLen ? SPKIDataType->SPKISexp.bytes[i++] : 0;
                                    uint32_t triple = (a << 16) + (b << 8) + c;
                                    encoded_data[j++] = encoding_table[(triple >> 18) & 0x3F];
                                    encoded_data[j++] = encoding_table[(triple >> 12) & 0x3F];
                                    encoded_data[j++] = encoding_table[(triple >> 6) & 0x3F];
                                    encoded_data[j++] = encoding_table[triple & 0x3F];
                                }
                                for (i = 0; i < (size_t)mod_table[SPKIDataType->SPKISexp.bytesLen % 3]; i++)
                                {
                                    encoded_data[output_length - 1 - i] = '=';
                                }
                                xml_write(xmlOut, xmlOut_size, xmlOut_pos, (char*)encoded_data, output_length);
                                free(encoded_data);
                            }
                            else
                            {
                                xml_write(xmlOut, xmlOut_size, xmlOut_pos, "(base64-alloc-failed)", 21);
                            }
                        }
                        grammar_id = 37;
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns1:SPKISexp>", 15);
                    }
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 37:
            // Grammar: ID=37; read/write bits=2; START (ANY), END Element, START (ANY)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: START (ANY, anyType (base64Binary)); next=2
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ANY", 4);
                        (void)xml_tag_start;
                    // decode: event not accepted
                    error = EXI_ERROR__UNKNOWN_EVENT_FOR_DECODING;
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ANY>", 6);
                    }
                    break;
                case 1:
                    // Event: END Element; next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                case 2:
                    // Event: START (ANY, anyType (base64Binary)); next=2
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ANY", 4);
                        (void)xml_tag_start;
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &SPKIDataType->ANY.bytesLen, &SPKIDataType->ANY.bytes[0], iso20_acdp_anyType_BYTES_SIZE);
                    if (error == 0)
                    {
                        SPKIDataType->ANY_isUsed = 1u;
                        // XML: emit base64 encoded value
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                        {
                            static const char encoding_table[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
                            static const int mod_table[] = {0, 2, 1};
                            size_t output_length = 4 * ((SPKIDataType->ANY.bytesLen + 2) / 3);
                            unsigned char* encoded_data = (unsigned char*)malloc(output_length + 1);
                            if (encoded_data != NULL)
                            {
                                size_t i, j;
                                for (i = 0, j = 0; i < SPKIDataType->ANY.bytesLen;)
                                {
                                    uint32_t a = i < SPKIDataType->ANY.bytesLen ? SPKIDataType->ANY.bytes[i++] : 0;
                                    uint32_t b = i < SPKIDataType->ANY.bytesLen ? SPKIDataType->ANY.bytes[i++] : 0;
                                    uint32_t c = i < SPKIDataType->ANY.bytesLen ? SPKIDataType->ANY.bytes[i++] : 0;
                                    uint32_t triple = (a << 16) + (b << 8) + c;
                                    encoded_data[j++] = encoding_table[(triple >> 18) & 0x3F];
                                    encoded_data[j++] = encoding_table[(triple >> 12) & 0x3F];
                                    encoded_data[j++] = encoding_table[(triple >> 6) & 0x3F];
                                    encoded_data[j++] = encoding_table[triple & 0x3F];
                                }
                                for (i = 0; i < (size_t)mod_table[SPKIDataType->ANY.bytesLen % 3]; i++)
                                {
                                    encoded_data[output_length - 1 - i] = '=';
                                }
                                xml_write(xmlOut, xmlOut_size, xmlOut_pos, (char*)encoded_data, output_length);
                                free(encoded_data);
                            }
                            else
                            {
                                xml_write(xmlOut, xmlOut_size, xmlOut_pos, "(base64-alloc-failed)", 21);
                            }
                        }
                        grammar_id = 2;
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ANY>", 6);
                    }
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: END Element; next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={http://www.w3.org/2000/09/xmldsig#}SignatureMethod; type={http://www.w3.org/2000/09/xmldsig#}SignatureMethodType; base type=; content type=mixed;
//          abstract=False; final=False;
// Particle: Algorithm, anyURI (1, 1); HMACOutputLength, HMACOutputLengthType (0, 1); ANY, anyType (0, 1);
static int decode_iso20_acdp_SignatureMethodType(exi_bitstream_t* stream, struct iso20_acdp_SignatureMethodType* SignatureMethodType, char* xmlOut, size_t xmlOut_size, size_t* xmlOut_pos) {
    int grammar_id = 38;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_acdp_SignatureMethodType(SignatureMethodType);

    while (!done)
    {
        switch (grammar_id)
        {
        case 38:
            // Grammar: ID=38; read/write bits=1; START (Algorithm)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: START (Algorithm, anyURI (anyURI)); next=39
                    // XML: attribute
                    xml_write(xmlOut, xmlOut_size, xmlOut_pos, " Algorithm=\"", 12);
                    // decode: string (len, characters) (Attribute)
                    error = exi_basetypes_decoder_uint_16(stream, &SignatureMethodType->Algorithm.charactersLen);
                    if (error == 0)
                    {
                        if (SignatureMethodType->Algorithm.charactersLen >= 2)
                        {
                            // string tables and table partitions are not supported, so the length has to be decremented by 2
                            SignatureMethodType->Algorithm.charactersLen -= 2;
                            error = exi_basetypes_decoder_characters(stream, SignatureMethodType->Algorithm.charactersLen, SignatureMethodType->Algorithm.characters, iso20_acdp_Algorithm_CHARACTER_SIZE);
                            if (error == 0)
                            {
                                // XML: emit string value
                                xml_write_escaped_attr(xmlOut, xmlOut_size, xmlOut_pos, SignatureMethodType->Algorithm.characters, SignatureMethodType->Algorithm.charactersLen);
                            }
                        }
                        else
                        {
                            // the string seems to be in the table, but this is not supported
                            error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                        }
                    }
                    grammar_id = 39;
                    xml_write(xmlOut, xmlOut_size, xmlOut_pos, "\"", 1);
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 39:
            // Grammar: ID=39; read/write bits=3; START (HMACOutputLength), START (ANY), END Element, START (ANY)
            error = exi_basetypes_decoder_nbit_uint(stream, 3, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: START (HMACOutputLength, HMACOutputLengthType (integer)); next=40
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns1:HMACOutputLength", 21);
                        (void)xml_tag_start;
                    // decode: signed
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        error = exi_basetypes_decoder_signed(stream, &SignatureMethodType->HMACOutputLength);
                        if (error == 0)
                        {
                            SignatureMethodType->HMACOutputLength_isUsed = 1u;
                            // XML: emit value
                            xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                            { int64_t _sv; exi_basetypes_convert_64_from_signed(&SignatureMethodType->HMACOutputLength, &_sv); char _xv[64]; int _xl = snprintf(_xv, sizeof(_xv), "%" PRId64, _sv); xml_write(xmlOut, xmlOut_size, xmlOut_pos, _xv, _xl); }
                            grammar_id = 40;
                        }
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns1:HMACOutputLength>", 23);
                    }
                    break;
                case 1:
                    // Event: START (ANY, anyType (base64Binary)); next=2
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ANY", 4);
                        (void)xml_tag_start;
                    // decode: event not accepted
                    error = EXI_ERROR__UNKNOWN_EVENT_FOR_DECODING;
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ANY>", 6);
                    }
                    break;
                case 2:
                    // Event: END Element; next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                case 3:
                    // Event: START (ANY, anyType (base64Binary)); next=2
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ANY", 4);
                        (void)xml_tag_start;
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &SignatureMethodType->ANY.bytesLen, &SignatureMethodType->ANY.bytes[0], iso20_acdp_anyType_BYTES_SIZE);
                    if (error == 0)
                    {
                        SignatureMethodType->ANY_isUsed = 1u;
                        // XML: emit base64 encoded value
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                        {
                            static const char encoding_table[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
                            static const int mod_table[] = {0, 2, 1};
                            size_t output_length = 4 * ((SignatureMethodType->ANY.bytesLen + 2) / 3);
                            unsigned char* encoded_data = (unsigned char*)malloc(output_length + 1);
                            if (encoded_data != NULL)
                            {
                                size_t i, j;
                                for (i = 0, j = 0; i < SignatureMethodType->ANY.bytesLen;)
                                {
                                    uint32_t a = i < SignatureMethodType->ANY.bytesLen ? SignatureMethodType->ANY.bytes[i++] : 0;
                                    uint32_t b = i < SignatureMethodType->ANY.bytesLen ? SignatureMethodType->ANY.bytes[i++] : 0;
                                    uint32_t c = i < SignatureMethodType->ANY.bytesLen ? SignatureMethodType->ANY.bytes[i++] : 0;
                                    uint32_t triple = (a << 16) + (b << 8) + c;
                                    encoded_data[j++] = encoding_table[(triple >> 18) & 0x3F];
                                    encoded_data[j++] = encoding_table[(triple >> 12) & 0x3F];
                                    encoded_data[j++] = encoding_table[(triple >> 6) & 0x3F];
                                    encoded_data[j++] = encoding_table[triple & 0x3F];
                                }
                                for (i = 0; i < (size_t)mod_table[SignatureMethodType->ANY.bytesLen % 3]; i++)
                                {
                                    encoded_data[output_length - 1 - i] = '=';
                                }
                                xml_write(xmlOut, xmlOut_size, xmlOut_pos, (char*)encoded_data, output_length);
                                free(encoded_data);
                            }
                            else
                            {
                                xml_write(xmlOut, xmlOut_size, xmlOut_pos, "(base64-alloc-failed)", 21);
                            }
                        }
                        grammar_id = 2;
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ANY>", 6);
                    }
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 40:
            // Grammar: ID=40; read/write bits=2; START (ANY), END Element, START (ANY)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: START (ANY, anyType (base64Binary)); next=2
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ANY", 4);
                        (void)xml_tag_start;
                    // decode: event not accepted
                    error = EXI_ERROR__UNKNOWN_EVENT_FOR_DECODING;
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ANY>", 6);
                    }
                    break;
                case 1:
                    // Event: END Element; next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                case 2:
                    // Event: START (ANY, anyType (base64Binary)); next=2
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ANY", 4);
                        (void)xml_tag_start;
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &SignatureMethodType->ANY.bytesLen, &SignatureMethodType->ANY.bytes[0], iso20_acdp_anyType_BYTES_SIZE);
                    if (error == 0)
                    {
                        SignatureMethodType->ANY_isUsed = 1u;
                        // XML: emit base64 encoded value
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                        {
                            static const char encoding_table[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
                            static const int mod_table[] = {0, 2, 1};
                            size_t output_length = 4 * ((SignatureMethodType->ANY.bytesLen + 2) / 3);
                            unsigned char* encoded_data = (unsigned char*)malloc(output_length + 1);
                            if (encoded_data != NULL)
                            {
                                size_t i, j;
                                for (i = 0, j = 0; i < SignatureMethodType->ANY.bytesLen;)
                                {
                                    uint32_t a = i < SignatureMethodType->ANY.bytesLen ? SignatureMethodType->ANY.bytes[i++] : 0;
                                    uint32_t b = i < SignatureMethodType->ANY.bytesLen ? SignatureMethodType->ANY.bytes[i++] : 0;
                                    uint32_t c = i < SignatureMethodType->ANY.bytesLen ? SignatureMethodType->ANY.bytes[i++] : 0;
                                    uint32_t triple = (a << 16) + (b << 8) + c;
                                    encoded_data[j++] = encoding_table[(triple >> 18) & 0x3F];
                                    encoded_data[j++] = encoding_table[(triple >> 12) & 0x3F];
                                    encoded_data[j++] = encoding_table[(triple >> 6) & 0x3F];
                                    encoded_data[j++] = encoding_table[triple & 0x3F];
                                }
                                for (i = 0; i < (size_t)mod_table[SignatureMethodType->ANY.bytesLen % 3]; i++)
                                {
                                    encoded_data[output_length - 1 - i] = '=';
                                }
                                xml_write(xmlOut, xmlOut_size, xmlOut_pos, (char*)encoded_data, output_length);
                                free(encoded_data);
                            }
                            else
                            {
                                xml_write(xmlOut, xmlOut_size, xmlOut_pos, "(base64-alloc-failed)", 21);
                            }
                        }
                        grammar_id = 2;
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ANY>", 6);
                    }
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: END Element; next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={http://www.w3.org/2000/09/xmldsig#}X509Data; type={http://www.w3.org/2000/09/xmldsig#}X509DataType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: X509IssuerSerial, X509IssuerSerialType (0, 1); X509SKI, base64Binary (0, 1); X509SubjectName, string (0, 1); X509Certificate, base64Binary (0, 1); X509CRL, base64Binary (0, 1); ANY, anyType (0, 1);
static int decode_iso20_acdp_X509DataType(exi_bitstream_t* stream, struct iso20_acdp_X509DataType* X509DataType, char* xmlOut, size_t xmlOut_size, size_t* xmlOut_pos) {
    int grammar_id = 41;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_acdp_X509DataType(X509DataType);

    while (!done)
    {
        switch (grammar_id)
        {
        case 41:
            // Grammar: ID=41; read/write bits=3; START (X509IssuerSerial), START (X509SKI), START (X509SubjectName), START (X509Certificate), START (X509CRL), START (ANY)
            error = exi_basetypes_decoder_nbit_uint(stream, 3, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: START (X509IssuerSerial, X509IssuerSerialType (X509IssuerSerialType)); next=2
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns1:X509IssuerSerial", 21);
                        (void)xml_tag_start;
                    // decode: element
                    error = decode_iso20_acdp_X509IssuerSerialType(stream, &X509DataType->X509IssuerSerial, xmlOut, xmlOut_size, xmlOut_pos);
                    if (error == 0)
                    {
                        X509DataType->X509IssuerSerial_isUsed = 1u;
                        grammar_id = 2;
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns1:X509IssuerSerial>", 23);
                    }
                    break;
                case 1:
                    // Event: START (X509SKI, base64Binary (base64Binary)); next=2
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns1:X509SKI", 12);
                        (void)xml_tag_start;
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &X509DataType->X509SKI.bytesLen, &X509DataType->X509SKI.bytes[0], iso20_acdp_base64Binary_BYTES_SIZE);
                    if (error == 0)
                    {
                        X509DataType->X509SKI_isUsed = 1u;
                        // XML: emit base64 encoded value
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                        {
                            static const char encoding_table[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
                            static const int mod_table[] = {0, 2, 1};
                            size_t output_length = 4 * ((X509DataType->X509SKI.bytesLen + 2) / 3);
                            unsigned char* encoded_data = (unsigned char*)malloc(output_length + 1);
                            if (encoded_data != NULL)
                            {
                                size_t i, j;
                                for (i = 0, j = 0; i < X509DataType->X509SKI.bytesLen;)
                                {
                                    uint32_t a = i < X509DataType->X509SKI.bytesLen ? X509DataType->X509SKI.bytes[i++] : 0;
                                    uint32_t b = i < X509DataType->X509SKI.bytesLen ? X509DataType->X509SKI.bytes[i++] : 0;
                                    uint32_t c = i < X509DataType->X509SKI.bytesLen ? X509DataType->X509SKI.bytes[i++] : 0;
                                    uint32_t triple = (a << 16) + (b << 8) + c;
                                    encoded_data[j++] = encoding_table[(triple >> 18) & 0x3F];
                                    encoded_data[j++] = encoding_table[(triple >> 12) & 0x3F];
                                    encoded_data[j++] = encoding_table[(triple >> 6) & 0x3F];
                                    encoded_data[j++] = encoding_table[triple & 0x3F];
                                }
                                for (i = 0; i < (size_t)mod_table[X509DataType->X509SKI.bytesLen % 3]; i++)
                                {
                                    encoded_data[output_length - 1 - i] = '=';
                                }
                                xml_write(xmlOut, xmlOut_size, xmlOut_pos, (char*)encoded_data, output_length);
                                free(encoded_data);
                            }
                            else
                            {
                                xml_write(xmlOut, xmlOut_size, xmlOut_pos, "(base64-alloc-failed)", 21);
                            }
                        }
                        grammar_id = 2;
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns1:X509SKI>", 14);
                    }
                    break;
                case 2:
                    // Event: START (X509SubjectName, string (string)); next=2
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns1:X509SubjectName", 20);
                        (void)xml_tag_start;
                    // decode: string (len, characters)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            error = exi_basetypes_decoder_uint_16(stream, &X509DataType->X509SubjectName.charactersLen);
                            if (error == 0)
                            {
                                if (X509DataType->X509SubjectName.charactersLen >= 2)
                                {
                                    // string tables and table partitions are not supported, so the length has to be decremented by 2
                                    X509DataType->X509SubjectName.charactersLen -= 2;
                                    error = exi_basetypes_decoder_characters(stream, X509DataType->X509SubjectName.charactersLen, X509DataType->X509SubjectName.characters, iso20_acdp_X509SubjectName_CHARACTER_SIZE);
                                    if (error == 0)
                                    {
                                        // XML: emit string value
                                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                                        xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, X509DataType->X509SubjectName.characters, X509DataType->X509SubjectName.charactersLen);
                                    }
                                }
                                else
                                {
                                    // the string seems to be in the table, but this is not supported
                                    error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                                }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_characters is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                X509DataType->X509SubjectName_isUsed = 1u;
                                grammar_id = 2;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns1:X509SubjectName>", 22);
                    }
                    break;
                case 3:
                    // Event: START (X509Certificate, base64Binary (base64Binary)); next=2
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns1:X509Certificate", 20);
                        (void)xml_tag_start;
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &X509DataType->X509Certificate.bytesLen, &X509DataType->X509Certificate.bytes[0], iso20_acdp_base64Binary_BYTES_SIZE);
                    if (error == 0)
                    {
                        X509DataType->X509Certificate_isUsed = 1u;
                        // XML: emit base64 encoded value
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                        {
                            static const char encoding_table[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
                            static const int mod_table[] = {0, 2, 1};
                            size_t output_length = 4 * ((X509DataType->X509Certificate.bytesLen + 2) / 3);
                            unsigned char* encoded_data = (unsigned char*)malloc(output_length + 1);
                            if (encoded_data != NULL)
                            {
                                size_t i, j;
                                for (i = 0, j = 0; i < X509DataType->X509Certificate.bytesLen;)
                                {
                                    uint32_t a = i < X509DataType->X509Certificate.bytesLen ? X509DataType->X509Certificate.bytes[i++] : 0;
                                    uint32_t b = i < X509DataType->X509Certificate.bytesLen ? X509DataType->X509Certificate.bytes[i++] : 0;
                                    uint32_t c = i < X509DataType->X509Certificate.bytesLen ? X509DataType->X509Certificate.bytes[i++] : 0;
                                    uint32_t triple = (a << 16) + (b << 8) + c;
                                    encoded_data[j++] = encoding_table[(triple >> 18) & 0x3F];
                                    encoded_data[j++] = encoding_table[(triple >> 12) & 0x3F];
                                    encoded_data[j++] = encoding_table[(triple >> 6) & 0x3F];
                                    encoded_data[j++] = encoding_table[triple & 0x3F];
                                }
                                for (i = 0; i < (size_t)mod_table[X509DataType->X509Certificate.bytesLen % 3]; i++)
                                {
                                    encoded_data[output_length - 1 - i] = '=';
                                }
                                xml_write(xmlOut, xmlOut_size, xmlOut_pos, (char*)encoded_data, output_length);
                                free(encoded_data);
                            }
                            else
                            {
                                xml_write(xmlOut, xmlOut_size, xmlOut_pos, "(base64-alloc-failed)", 21);
                            }
                        }
                        grammar_id = 2;
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns1:X509Certificate>", 22);
                    }
                    break;
                case 4:
                    // Event: START (X509CRL, base64Binary (base64Binary)); next=2
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns1:X509CRL", 12);
                        (void)xml_tag_start;
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &X509DataType->X509CRL.bytesLen, &X509DataType->X509CRL.bytes[0], iso20_acdp_base64Binary_BYTES_SIZE);
                    if (error == 0)
                    {
                        X509DataType->X509CRL_isUsed = 1u;
                        // XML: emit base64 encoded value
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                        {
                            static const char encoding_table[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
                            static const int mod_table[] = {0, 2, 1};
                            size_t output_length = 4 * ((X509DataType->X509CRL.bytesLen + 2) / 3);
                            unsigned char* encoded_data = (unsigned char*)malloc(output_length + 1);
                            if (encoded_data != NULL)
                            {
                                size_t i, j;
                                for (i = 0, j = 0; i < X509DataType->X509CRL.bytesLen;)
                                {
                                    uint32_t a = i < X509DataType->X509CRL.bytesLen ? X509DataType->X509CRL.bytes[i++] : 0;
                                    uint32_t b = i < X509DataType->X509CRL.bytesLen ? X509DataType->X509CRL.bytes[i++] : 0;
                                    uint32_t c = i < X509DataType->X509CRL.bytesLen ? X509DataType->X509CRL.bytes[i++] : 0;
                                    uint32_t triple = (a << 16) + (b << 8) + c;
                                    encoded_data[j++] = encoding_table[(triple >> 18) & 0x3F];
                                    encoded_data[j++] = encoding_table[(triple >> 12) & 0x3F];
                                    encoded_data[j++] = encoding_table[(triple >> 6) & 0x3F];
                                    encoded_data[j++] = encoding_table[triple & 0x3F];
                                }
                                for (i = 0; i < (size_t)mod_table[X509DataType->X509CRL.bytesLen % 3]; i++)
                                {
                                    encoded_data[output_length - 1 - i] = '=';
                                }
                                xml_write(xmlOut, xmlOut_size, xmlOut_pos, (char*)encoded_data, output_length);
                                free(encoded_data);
                            }
                            else
                            {
                                xml_write(xmlOut, xmlOut_size, xmlOut_pos, "(base64-alloc-failed)", 21);
                            }
                        }
                        grammar_id = 2;
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns1:X509CRL>", 14);
                    }
                    break;
                case 5:
                    // Event: START (ANY, anyType (base64Binary)); next=2
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ANY", 4);
                        (void)xml_tag_start;
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &X509DataType->ANY.bytesLen, &X509DataType->ANY.bytes[0], iso20_acdp_anyType_BYTES_SIZE);
                    if (error == 0)
                    {
                        X509DataType->ANY_isUsed = 1u;
                        // XML: emit base64 encoded value
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                        {
                            static const char encoding_table[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
                            static const int mod_table[] = {0, 2, 1};
                            size_t output_length = 4 * ((X509DataType->ANY.bytesLen + 2) / 3);
                            unsigned char* encoded_data = (unsigned char*)malloc(output_length + 1);
                            if (encoded_data != NULL)
                            {
                                size_t i, j;
                                for (i = 0, j = 0; i < X509DataType->ANY.bytesLen;)
                                {
                                    uint32_t a = i < X509DataType->ANY.bytesLen ? X509DataType->ANY.bytes[i++] : 0;
                                    uint32_t b = i < X509DataType->ANY.bytesLen ? X509DataType->ANY.bytes[i++] : 0;
                                    uint32_t c = i < X509DataType->ANY.bytesLen ? X509DataType->ANY.bytes[i++] : 0;
                                    uint32_t triple = (a << 16) + (b << 8) + c;
                                    encoded_data[j++] = encoding_table[(triple >> 18) & 0x3F];
                                    encoded_data[j++] = encoding_table[(triple >> 12) & 0x3F];
                                    encoded_data[j++] = encoding_table[(triple >> 6) & 0x3F];
                                    encoded_data[j++] = encoding_table[triple & 0x3F];
                                }
                                for (i = 0; i < (size_t)mod_table[X509DataType->ANY.bytesLen % 3]; i++)
                                {
                                    encoded_data[output_length - 1 - i] = '=';
                                }
                                xml_write(xmlOut, xmlOut_size, xmlOut_pos, (char*)encoded_data, output_length);
                                free(encoded_data);
                            }
                            else
                            {
                                xml_write(xmlOut, xmlOut_size, xmlOut_pos, "(base64-alloc-failed)", 21);
                            }
                        }
                        grammar_id = 2;
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ANY>", 6);
                    }
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: END Element; next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={http://www.w3.org/2000/09/xmldsig#}KeyInfo; type={http://www.w3.org/2000/09/xmldsig#}KeyInfoType; base type=; content type=mixed;
//          abstract=False; final=False; choice=True;
// Particle: Id, ID (0, 1); KeyName, string (0, 1); KeyValue, KeyValueType (0, 1); RetrievalMethod, RetrievalMethodType (0, 1); X509Data, X509DataType (0, 1); PGPData, PGPDataType (0, 1); SPKIData, SPKIDataType (0, 1); MgmtData, string (0, 1); ANY, anyType (0, 1);
static int decode_iso20_acdp_KeyInfoType(exi_bitstream_t* stream, struct iso20_acdp_KeyInfoType* KeyInfoType, char* xmlOut, size_t xmlOut_size, size_t* xmlOut_pos) {
    int grammar_id = 42;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_acdp_KeyInfoType(KeyInfoType);

    while (!done)
    {
        switch (grammar_id)
        {
        case 42:
            // Grammar: ID=42; read/write bits=4; START (Id), START (KeyName), START (KeyValue), START (RetrievalMethod), START (X509Data), START (PGPData), START (SPKIData), START (MgmtData), START (ANY)
            error = exi_basetypes_decoder_nbit_uint(stream, 4, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: START (Id, ID (NCName)); next=43
                    // XML: attribute
                    xml_write(xmlOut, xmlOut_size, xmlOut_pos, " Id=\"", 5);
                    // decode: string (len, characters) (Attribute)
                    error = exi_basetypes_decoder_uint_16(stream, &KeyInfoType->Id.charactersLen);
                    if (error == 0)
                    {
                        if (KeyInfoType->Id.charactersLen >= 2)
                        {
                            // string tables and table partitions are not supported, so the length has to be decremented by 2
                            KeyInfoType->Id.charactersLen -= 2;
                            error = exi_basetypes_decoder_characters(stream, KeyInfoType->Id.charactersLen, KeyInfoType->Id.characters, iso20_acdp_Id_CHARACTER_SIZE);
                            if (error == 0)
                            {
                                // XML: emit string value
                                xml_write_escaped_attr(xmlOut, xmlOut_size, xmlOut_pos, KeyInfoType->Id.characters, KeyInfoType->Id.charactersLen);
                            }
                        }
                        else
                        {
                            // the string seems to be in the table, but this is not supported
                            error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                        }
                    }
                    KeyInfoType->Id_isUsed = 1u;
                    grammar_id = 43;
                    xml_write(xmlOut, xmlOut_size, xmlOut_pos, "\"", 1);
                    break;
                case 1:
                    // Event: START (KeyName, string (string)); next=2
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns1:KeyName", 12);
                        (void)xml_tag_start;
                    // decode: string (len, characters)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            error = exi_basetypes_decoder_uint_16(stream, &KeyInfoType->KeyName.charactersLen);
                            if (error == 0)
                            {
                                if (KeyInfoType->KeyName.charactersLen >= 2)
                                {
                                    // string tables and table partitions are not supported, so the length has to be decremented by 2
                                    KeyInfoType->KeyName.charactersLen -= 2;
                                    error = exi_basetypes_decoder_characters(stream, KeyInfoType->KeyName.charactersLen, KeyInfoType->KeyName.characters, iso20_acdp_KeyName_CHARACTER_SIZE);
                                    if (error == 0)
                                    {
                                        // XML: emit string value
                                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                                        xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, KeyInfoType->KeyName.characters, KeyInfoType->KeyName.charactersLen);
                                    }
                                }
                                else
                                {
                                    // the string seems to be in the table, but this is not supported
                                    error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                                }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_characters is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                KeyInfoType->KeyName_isUsed = 1u;
                                grammar_id = 2;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns1:KeyName>", 14);
                    }
                    break;
                case 2:
                    // Event: START (KeyValue, KeyValueType (KeyValueType)); next=2
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns1:KeyValue", 13);
                        (void)xml_tag_start;
                    // decode: element
                    error = decode_iso20_acdp_KeyValueType(stream, &KeyInfoType->KeyValue, xmlOut, xmlOut_size, xmlOut_pos);
                    if (error == 0)
                    {
                        KeyInfoType->KeyValue_isUsed = 1u;
                        grammar_id = 2;
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns1:KeyValue>", 15);
                    }
                    break;
                case 3:
                    // Event: START (RetrievalMethod, RetrievalMethodType (RetrievalMethodType)); next=2
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns1:RetrievalMethod", 20);
                        (void)xml_tag_start;
                    // decode: element
                    error = decode_iso20_acdp_RetrievalMethodType(stream, &KeyInfoType->RetrievalMethod, xmlOut, xmlOut_size, xmlOut_pos);
                    if (error == 0)
                    {
                        KeyInfoType->RetrievalMethod_isUsed = 1u;
                        grammar_id = 2;
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns1:RetrievalMethod>", 22);
                    }
                    break;
                case 4:
                    // Event: START (X509Data, X509DataType (X509DataType)); next=2
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns1:X509Data", 13);
                        (void)xml_tag_start;
                    // decode: element
                    error = decode_iso20_acdp_X509DataType(stream, &KeyInfoType->X509Data, xmlOut, xmlOut_size, xmlOut_pos);
                    if (error == 0)
                    {
                        KeyInfoType->X509Data_isUsed = 1u;
                        grammar_id = 2;
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns1:X509Data>", 15);
                    }
                    break;
                case 5:
                    // Event: START (PGPData, PGPDataType (PGPDataType)); next=2
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns1:PGPData", 12);
                        (void)xml_tag_start;
                    // decode: element
                    error = decode_iso20_acdp_PGPDataType(stream, &KeyInfoType->PGPData, xmlOut, xmlOut_size, xmlOut_pos);
                    if (error == 0)
                    {
                        KeyInfoType->PGPData_isUsed = 1u;
                        grammar_id = 2;
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns1:PGPData>", 14);
                    }
                    break;
                case 6:
                    // Event: START (SPKIData, SPKIDataType (SPKIDataType)); next=2
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns1:SPKIData", 13);
                        (void)xml_tag_start;
                    // decode: element
                    error = decode_iso20_acdp_SPKIDataType(stream, &KeyInfoType->SPKIData, xmlOut, xmlOut_size, xmlOut_pos);
                    if (error == 0)
                    {
                        KeyInfoType->SPKIData_isUsed = 1u;
                        grammar_id = 2;
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns1:SPKIData>", 15);
                    }
                    break;
                case 7:
                    // Event: START (MgmtData, string (string)); next=2
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns1:MgmtData", 13);
                        (void)xml_tag_start;
                    // decode: string (len, characters)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            error = exi_basetypes_decoder_uint_16(stream, &KeyInfoType->MgmtData.charactersLen);
                            if (error == 0)
                            {
                                if (KeyInfoType->MgmtData.charactersLen >= 2)
                                {
                                    // string tables and table partitions are not supported, so the length has to be decremented by 2
                                    KeyInfoType->MgmtData.charactersLen -= 2;
                                    error = exi_basetypes_decoder_characters(stream, KeyInfoType->MgmtData.charactersLen, KeyInfoType->MgmtData.characters, iso20_acdp_MgmtData_CHARACTER_SIZE);
                                    if (error == 0)
                                    {
                                        // XML: emit string value
                                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                                        xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, KeyInfoType->MgmtData.characters, KeyInfoType->MgmtData.charactersLen);
                                    }
                                }
                                else
                                {
                                    // the string seems to be in the table, but this is not supported
                                    error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                                }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_characters is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                KeyInfoType->MgmtData_isUsed = 1u;
                                grammar_id = 2;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns1:MgmtData>", 15);
                    }
                    break;
                case 8:
                    // Event: START (ANY, anyType (base64Binary)); next=2
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ANY", 4);
                        (void)xml_tag_start;
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &KeyInfoType->ANY.bytesLen, &KeyInfoType->ANY.bytes[0], iso20_acdp_anyType_BYTES_SIZE);
                    if (error == 0)
                    {
                        KeyInfoType->ANY_isUsed = 1u;
                        // XML: emit base64 encoded value
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                        {
                            static const char encoding_table[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
                            static const int mod_table[] = {0, 2, 1};
                            size_t output_length = 4 * ((KeyInfoType->ANY.bytesLen + 2) / 3);
                            unsigned char* encoded_data = (unsigned char*)malloc(output_length + 1);
                            if (encoded_data != NULL)
                            {
                                size_t i, j;
                                for (i = 0, j = 0; i < KeyInfoType->ANY.bytesLen;)
                                {
                                    uint32_t a = i < KeyInfoType->ANY.bytesLen ? KeyInfoType->ANY.bytes[i++] : 0;
                                    uint32_t b = i < KeyInfoType->ANY.bytesLen ? KeyInfoType->ANY.bytes[i++] : 0;
                                    uint32_t c = i < KeyInfoType->ANY.bytesLen ? KeyInfoType->ANY.bytes[i++] : 0;
                                    uint32_t triple = (a << 16) + (b << 8) + c;
                                    encoded_data[j++] = encoding_table[(triple >> 18) & 0x3F];
                                    encoded_data[j++] = encoding_table[(triple >> 12) & 0x3F];
                                    encoded_data[j++] = encoding_table[(triple >> 6) & 0x3F];
                                    encoded_data[j++] = encoding_table[triple & 0x3F];
                                }
                                for (i = 0; i < (size_t)mod_table[KeyInfoType->ANY.bytesLen % 3]; i++)
                                {
                                    encoded_data[output_length - 1 - i] = '=';
                                }
                                xml_write(xmlOut, xmlOut_size, xmlOut_pos, (char*)encoded_data, output_length);
                                free(encoded_data);
                            }
                            else
                            {
                                xml_write(xmlOut, xmlOut_size, xmlOut_pos, "(base64-alloc-failed)", 21);
                            }
                        }
                        grammar_id = 2;
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ANY>", 6);
                    }
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 43:
            // Grammar: ID=43; read/write bits=4; START (KeyName), START (KeyValue), START (RetrievalMethod), START (X509Data), START (PGPData), START (SPKIData), START (MgmtData), START (ANY)
            error = exi_basetypes_decoder_nbit_uint(stream, 4, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: START (KeyName, string (string)); next=2
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns1:KeyName", 12);
                        (void)xml_tag_start;
                    // decode: string (len, characters)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            error = exi_basetypes_decoder_uint_16(stream, &KeyInfoType->KeyName.charactersLen);
                            if (error == 0)
                            {
                                if (KeyInfoType->KeyName.charactersLen >= 2)
                                {
                                    // string tables and table partitions are not supported, so the length has to be decremented by 2
                                    KeyInfoType->KeyName.charactersLen -= 2;
                                    error = exi_basetypes_decoder_characters(stream, KeyInfoType->KeyName.charactersLen, KeyInfoType->KeyName.characters, iso20_acdp_KeyName_CHARACTER_SIZE);
                                    if (error == 0)
                                    {
                                        // XML: emit string value
                                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                                        xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, KeyInfoType->KeyName.characters, KeyInfoType->KeyName.charactersLen);
                                    }
                                }
                                else
                                {
                                    // the string seems to be in the table, but this is not supported
                                    error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                                }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_characters is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                KeyInfoType->KeyName_isUsed = 1u;
                                grammar_id = 2;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns1:KeyName>", 14);
                    }
                    break;
                case 1:
                    // Event: START (KeyValue, KeyValueType (KeyValueType)); next=2
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns1:KeyValue", 13);
                        (void)xml_tag_start;
                    // decode: element
                    error = decode_iso20_acdp_KeyValueType(stream, &KeyInfoType->KeyValue, xmlOut, xmlOut_size, xmlOut_pos);
                    if (error == 0)
                    {
                        KeyInfoType->KeyValue_isUsed = 1u;
                        grammar_id = 2;
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns1:KeyValue>", 15);
                    }
                    break;
                case 2:
                    // Event: START (RetrievalMethod, RetrievalMethodType (RetrievalMethodType)); next=2
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns1:RetrievalMethod", 20);
                        (void)xml_tag_start;
                    // decode: element
                    error = decode_iso20_acdp_RetrievalMethodType(stream, &KeyInfoType->RetrievalMethod, xmlOut, xmlOut_size, xmlOut_pos);
                    if (error == 0)
                    {
                        KeyInfoType->RetrievalMethod_isUsed = 1u;
                        grammar_id = 2;
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns1:RetrievalMethod>", 22);
                    }
                    break;
                case 3:
                    // Event: START (X509Data, X509DataType (X509DataType)); next=2
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns1:X509Data", 13);
                        (void)xml_tag_start;
                    // decode: element
                    error = decode_iso20_acdp_X509DataType(stream, &KeyInfoType->X509Data, xmlOut, xmlOut_size, xmlOut_pos);
                    if (error == 0)
                    {
                        KeyInfoType->X509Data_isUsed = 1u;
                        grammar_id = 2;
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns1:X509Data>", 15);
                    }
                    break;
                case 4:
                    // Event: START (PGPData, PGPDataType (PGPDataType)); next=2
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns1:PGPData", 12);
                        (void)xml_tag_start;
                    // decode: element
                    error = decode_iso20_acdp_PGPDataType(stream, &KeyInfoType->PGPData, xmlOut, xmlOut_size, xmlOut_pos);
                    if (error == 0)
                    {
                        KeyInfoType->PGPData_isUsed = 1u;
                        grammar_id = 2;
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns1:PGPData>", 14);
                    }
                    break;
                case 5:
                    // Event: START (SPKIData, SPKIDataType (SPKIDataType)); next=2
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns1:SPKIData", 13);
                        (void)xml_tag_start;
                    // decode: element
                    error = decode_iso20_acdp_SPKIDataType(stream, &KeyInfoType->SPKIData, xmlOut, xmlOut_size, xmlOut_pos);
                    if (error == 0)
                    {
                        KeyInfoType->SPKIData_isUsed = 1u;
                        grammar_id = 2;
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns1:SPKIData>", 15);
                    }
                    break;
                case 6:
                    // Event: START (MgmtData, string (string)); next=2
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns1:MgmtData", 13);
                        (void)xml_tag_start;
                    // decode: string (len, characters)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            error = exi_basetypes_decoder_uint_16(stream, &KeyInfoType->MgmtData.charactersLen);
                            if (error == 0)
                            {
                                if (KeyInfoType->MgmtData.charactersLen >= 2)
                                {
                                    // string tables and table partitions are not supported, so the length has to be decremented by 2
                                    KeyInfoType->MgmtData.charactersLen -= 2;
                                    error = exi_basetypes_decoder_characters(stream, KeyInfoType->MgmtData.charactersLen, KeyInfoType->MgmtData.characters, iso20_acdp_MgmtData_CHARACTER_SIZE);
                                    if (error == 0)
                                    {
                                        // XML: emit string value
                                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                                        xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, KeyInfoType->MgmtData.characters, KeyInfoType->MgmtData.charactersLen);
                                    }
                                }
                                else
                                {
                                    // the string seems to be in the table, but this is not supported
                                    error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                                }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_characters is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                KeyInfoType->MgmtData_isUsed = 1u;
                                grammar_id = 2;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns1:MgmtData>", 15);
                    }
                    break;
                case 7:
                    // Event: START (ANY, anyType (base64Binary)); next=2
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ANY", 4);
                        (void)xml_tag_start;
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &KeyInfoType->ANY.bytesLen, &KeyInfoType->ANY.bytes[0], iso20_acdp_anyType_BYTES_SIZE);
                    if (error == 0)
                    {
                        KeyInfoType->ANY_isUsed = 1u;
                        // XML: emit base64 encoded value
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                        {
                            static const char encoding_table[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
                            static const int mod_table[] = {0, 2, 1};
                            size_t output_length = 4 * ((KeyInfoType->ANY.bytesLen + 2) / 3);
                            unsigned char* encoded_data = (unsigned char*)malloc(output_length + 1);
                            if (encoded_data != NULL)
                            {
                                size_t i, j;
                                for (i = 0, j = 0; i < KeyInfoType->ANY.bytesLen;)
                                {
                                    uint32_t a = i < KeyInfoType->ANY.bytesLen ? KeyInfoType->ANY.bytes[i++] : 0;
                                    uint32_t b = i < KeyInfoType->ANY.bytesLen ? KeyInfoType->ANY.bytes[i++] : 0;
                                    uint32_t c = i < KeyInfoType->ANY.bytesLen ? KeyInfoType->ANY.bytes[i++] : 0;
                                    uint32_t triple = (a << 16) + (b << 8) + c;
                                    encoded_data[j++] = encoding_table[(triple >> 18) & 0x3F];
                                    encoded_data[j++] = encoding_table[(triple >> 12) & 0x3F];
                                    encoded_data[j++] = encoding_table[(triple >> 6) & 0x3F];
                                    encoded_data[j++] = encoding_table[triple & 0x3F];
                                }
                                for (i = 0; i < (size_t)mod_table[KeyInfoType->ANY.bytesLen % 3]; i++)
                                {
                                    encoded_data[output_length - 1 - i] = '=';
                                }
                                xml_write(xmlOut, xmlOut_size, xmlOut_pos, (char*)encoded_data, output_length);
                                free(encoded_data);
                            }
                            else
                            {
                                xml_write(xmlOut, xmlOut_size, xmlOut_pos, "(base64-alloc-failed)", 21);
                            }
                        }
                        grammar_id = 2;
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ANY>", 6);
                    }
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: END Element; next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={http://www.w3.org/2000/09/xmldsig#}Object; type={http://www.w3.org/2000/09/xmldsig#}ObjectType; base type=; content type=mixed;
//          abstract=False; final=False;
// Particle: Encoding, anyURI (0, 1); Id, ID (0, 1); MimeType, string (0, 1); ANY, anyType (0, 1) (old 1, 1);
static int decode_iso20_acdp_ObjectType(exi_bitstream_t* stream, struct iso20_acdp_ObjectType* ObjectType, char* xmlOut, size_t xmlOut_size, size_t* xmlOut_pos) {
    int grammar_id = 44;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_acdp_ObjectType(ObjectType);

    while (!done)
    {
        switch (grammar_id)
        {
        case 44:
            // Grammar: ID=44; read/write bits=3; START (Encoding), START (Id), START (MimeType), START (ANY), END Element, START (ANY)
            error = exi_basetypes_decoder_nbit_uint(stream, 3, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: START (Encoding, anyURI (anyURI)); next=45
                    // XML: attribute
                    xml_write(xmlOut, xmlOut_size, xmlOut_pos, " Encoding=\"", 11);
                    // decode: string (len, characters) (Attribute)
                    error = exi_basetypes_decoder_uint_16(stream, &ObjectType->Encoding.charactersLen);
                    if (error == 0)
                    {
                        if (ObjectType->Encoding.charactersLen >= 2)
                        {
                            // string tables and table partitions are not supported, so the length has to be decremented by 2
                            ObjectType->Encoding.charactersLen -= 2;
                            error = exi_basetypes_decoder_characters(stream, ObjectType->Encoding.charactersLen, ObjectType->Encoding.characters, iso20_acdp_Encoding_CHARACTER_SIZE);
                            if (error == 0)
                            {
                                // XML: emit string value
                                xml_write_escaped_attr(xmlOut, xmlOut_size, xmlOut_pos, ObjectType->Encoding.characters, ObjectType->Encoding.charactersLen);
                            }
                        }
                        else
                        {
                            // the string seems to be in the table, but this is not supported
                            error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                        }
                    }
                    ObjectType->Encoding_isUsed = 1u;
                    grammar_id = 45;
                    xml_write(xmlOut, xmlOut_size, xmlOut_pos, "\"", 1);
                    break;
                case 1:
                    // Event: START (Id, ID (NCName)); next=46
                    // XML: attribute
                    xml_write(xmlOut, xmlOut_size, xmlOut_pos, " Id=\"", 5);
                    // decode: string (len, characters) (Attribute)
                    error = exi_basetypes_decoder_uint_16(stream, &ObjectType->Id.charactersLen);
                    if (error == 0)
                    {
                        if (ObjectType->Id.charactersLen >= 2)
                        {
                            // string tables and table partitions are not supported, so the length has to be decremented by 2
                            ObjectType->Id.charactersLen -= 2;
                            error = exi_basetypes_decoder_characters(stream, ObjectType->Id.charactersLen, ObjectType->Id.characters, iso20_acdp_Id_CHARACTER_SIZE);
                            if (error == 0)
                            {
                                // XML: emit string value
                                xml_write_escaped_attr(xmlOut, xmlOut_size, xmlOut_pos, ObjectType->Id.characters, ObjectType->Id.charactersLen);
                            }
                        }
                        else
                        {
                            // the string seems to be in the table, but this is not supported
                            error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                        }
                    }
                    ObjectType->Id_isUsed = 1u;
                    grammar_id = 46;
                    xml_write(xmlOut, xmlOut_size, xmlOut_pos, "\"", 1);
                    break;
                case 2:
                    // Event: START (MimeType, string (string)); next=47
                    // XML: attribute
                    xml_write(xmlOut, xmlOut_size, xmlOut_pos, " MimeType=\"", 11);
                    // decode: string (len, characters) (Attribute)
                    error = exi_basetypes_decoder_uint_16(stream, &ObjectType->MimeType.charactersLen);
                    if (error == 0)
                    {
                        if (ObjectType->MimeType.charactersLen >= 2)
                        {
                            // string tables and table partitions are not supported, so the length has to be decremented by 2
                            ObjectType->MimeType.charactersLen -= 2;
                            error = exi_basetypes_decoder_characters(stream, ObjectType->MimeType.charactersLen, ObjectType->MimeType.characters, iso20_acdp_MimeType_CHARACTER_SIZE);
                            if (error == 0)
                            {
                                // XML: emit string value
                                xml_write_escaped_attr(xmlOut, xmlOut_size, xmlOut_pos, ObjectType->MimeType.characters, ObjectType->MimeType.charactersLen);
                            }
                        }
                        else
                        {
                            // the string seems to be in the table, but this is not supported
                            error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                        }
                    }
                    ObjectType->MimeType_isUsed = 1u;
                    grammar_id = 47;
                    xml_write(xmlOut, xmlOut_size, xmlOut_pos, "\"", 1);
                    break;
                case 3:
                    // Event: START (ANY, anyType (base64Binary)); next=2
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ANY", 4);
                        (void)xml_tag_start;
                    // decode: event not accepted
                    error = EXI_ERROR__UNKNOWN_EVENT_FOR_DECODING;
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ANY>", 6);
                    }
                    break;
                case 4:
                    // Event: END Element; next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                case 5:
                    // Event: START (ANY, anyType (base64Binary)); next=2
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ANY", 4);
                        (void)xml_tag_start;
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &ObjectType->ANY.bytesLen, &ObjectType->ANY.bytes[0], iso20_acdp_anyType_BYTES_SIZE);
                    if (error == 0)
                    {
                        ObjectType->ANY_isUsed = 1u;
                        // XML: emit base64 encoded value
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                        {
                            static const char encoding_table[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
                            static const int mod_table[] = {0, 2, 1};
                            size_t output_length = 4 * ((ObjectType->ANY.bytesLen + 2) / 3);
                            unsigned char* encoded_data = (unsigned char*)malloc(output_length + 1);
                            if (encoded_data != NULL)
                            {
                                size_t i, j;
                                for (i = 0, j = 0; i < ObjectType->ANY.bytesLen;)
                                {
                                    uint32_t a = i < ObjectType->ANY.bytesLen ? ObjectType->ANY.bytes[i++] : 0;
                                    uint32_t b = i < ObjectType->ANY.bytesLen ? ObjectType->ANY.bytes[i++] : 0;
                                    uint32_t c = i < ObjectType->ANY.bytesLen ? ObjectType->ANY.bytes[i++] : 0;
                                    uint32_t triple = (a << 16) + (b << 8) + c;
                                    encoded_data[j++] = encoding_table[(triple >> 18) & 0x3F];
                                    encoded_data[j++] = encoding_table[(triple >> 12) & 0x3F];
                                    encoded_data[j++] = encoding_table[(triple >> 6) & 0x3F];
                                    encoded_data[j++] = encoding_table[triple & 0x3F];
                                }
                                for (i = 0; i < (size_t)mod_table[ObjectType->ANY.bytesLen % 3]; i++)
                                {
                                    encoded_data[output_length - 1 - i] = '=';
                                }
                                xml_write(xmlOut, xmlOut_size, xmlOut_pos, (char*)encoded_data, output_length);
                                free(encoded_data);
                            }
                            else
                            {
                                xml_write(xmlOut, xmlOut_size, xmlOut_pos, "(base64-alloc-failed)", 21);
                            }
                        }
                        grammar_id = 2;
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ANY>", 6);
                    }
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 45:
            // Grammar: ID=45; read/write bits=3; START (Id), START (MimeType), START (ANY), END Element, START (ANY)
            error = exi_basetypes_decoder_nbit_uint(stream, 3, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: START (Id, ID (NCName)); next=46
                    // XML: attribute
                    xml_write(xmlOut, xmlOut_size, xmlOut_pos, " Id=\"", 5);
                    // decode: string (len, characters) (Attribute)
                    error = exi_basetypes_decoder_uint_16(stream, &ObjectType->Id.charactersLen);
                    if (error == 0)
                    {
                        if (ObjectType->Id.charactersLen >= 2)
                        {
                            // string tables and table partitions are not supported, so the length has to be decremented by 2
                            ObjectType->Id.charactersLen -= 2;
                            error = exi_basetypes_decoder_characters(stream, ObjectType->Id.charactersLen, ObjectType->Id.characters, iso20_acdp_Id_CHARACTER_SIZE);
                            if (error == 0)
                            {
                                // XML: emit string value
                                xml_write_escaped_attr(xmlOut, xmlOut_size, xmlOut_pos, ObjectType->Id.characters, ObjectType->Id.charactersLen);
                            }
                        }
                        else
                        {
                            // the string seems to be in the table, but this is not supported
                            error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                        }
                    }
                    ObjectType->Id_isUsed = 1u;
                    grammar_id = 46;
                    xml_write(xmlOut, xmlOut_size, xmlOut_pos, "\"", 1);
                    break;
                case 1:
                    // Event: START (MimeType, string (string)); next=47
                    // XML: attribute
                    xml_write(xmlOut, xmlOut_size, xmlOut_pos, " MimeType=\"", 11);
                    // decode: string (len, characters) (Attribute)
                    error = exi_basetypes_decoder_uint_16(stream, &ObjectType->MimeType.charactersLen);
                    if (error == 0)
                    {
                        if (ObjectType->MimeType.charactersLen >= 2)
                        {
                            // string tables and table partitions are not supported, so the length has to be decremented by 2
                            ObjectType->MimeType.charactersLen -= 2;
                            error = exi_basetypes_decoder_characters(stream, ObjectType->MimeType.charactersLen, ObjectType->MimeType.characters, iso20_acdp_MimeType_CHARACTER_SIZE);
                            if (error == 0)
                            {
                                // XML: emit string value
                                xml_write_escaped_attr(xmlOut, xmlOut_size, xmlOut_pos, ObjectType->MimeType.characters, ObjectType->MimeType.charactersLen);
                            }
                        }
                        else
                        {
                            // the string seems to be in the table, but this is not supported
                            error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                        }
                    }
                    ObjectType->MimeType_isUsed = 1u;
                    grammar_id = 47;
                    xml_write(xmlOut, xmlOut_size, xmlOut_pos, "\"", 1);
                    break;
                case 2:
                    // Event: START (ANY, anyType (base64Binary)); next=2
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ANY", 4);
                        (void)xml_tag_start;
                    // decode: event not accepted
                    error = EXI_ERROR__UNKNOWN_EVENT_FOR_DECODING;
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ANY>", 6);
                    }
                    break;
                case 3:
                    // Event: END Element; next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                case 4:
                    // Event: START (ANY, anyType (base64Binary)); next=2
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ANY", 4);
                        (void)xml_tag_start;
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &ObjectType->ANY.bytesLen, &ObjectType->ANY.bytes[0], iso20_acdp_anyType_BYTES_SIZE);
                    if (error == 0)
                    {
                        ObjectType->ANY_isUsed = 1u;
                        // XML: emit base64 encoded value
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                        {
                            static const char encoding_table[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
                            static const int mod_table[] = {0, 2, 1};
                            size_t output_length = 4 * ((ObjectType->ANY.bytesLen + 2) / 3);
                            unsigned char* encoded_data = (unsigned char*)malloc(output_length + 1);
                            if (encoded_data != NULL)
                            {
                                size_t i, j;
                                for (i = 0, j = 0; i < ObjectType->ANY.bytesLen;)
                                {
                                    uint32_t a = i < ObjectType->ANY.bytesLen ? ObjectType->ANY.bytes[i++] : 0;
                                    uint32_t b = i < ObjectType->ANY.bytesLen ? ObjectType->ANY.bytes[i++] : 0;
                                    uint32_t c = i < ObjectType->ANY.bytesLen ? ObjectType->ANY.bytes[i++] : 0;
                                    uint32_t triple = (a << 16) + (b << 8) + c;
                                    encoded_data[j++] = encoding_table[(triple >> 18) & 0x3F];
                                    encoded_data[j++] = encoding_table[(triple >> 12) & 0x3F];
                                    encoded_data[j++] = encoding_table[(triple >> 6) & 0x3F];
                                    encoded_data[j++] = encoding_table[triple & 0x3F];
                                }
                                for (i = 0; i < (size_t)mod_table[ObjectType->ANY.bytesLen % 3]; i++)
                                {
                                    encoded_data[output_length - 1 - i] = '=';
                                }
                                xml_write(xmlOut, xmlOut_size, xmlOut_pos, (char*)encoded_data, output_length);
                                free(encoded_data);
                            }
                            else
                            {
                                xml_write(xmlOut, xmlOut_size, xmlOut_pos, "(base64-alloc-failed)", 21);
                            }
                        }
                        grammar_id = 2;
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ANY>", 6);
                    }
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 46:
            // Grammar: ID=46; read/write bits=3; START (MimeType), START (ANY), END Element, START (ANY)
            error = exi_basetypes_decoder_nbit_uint(stream, 3, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: START (MimeType, string (string)); next=47
                    // XML: attribute
                    xml_write(xmlOut, xmlOut_size, xmlOut_pos, " MimeType=\"", 11);
                    // decode: string (len, characters) (Attribute)
                    error = exi_basetypes_decoder_uint_16(stream, &ObjectType->MimeType.charactersLen);
                    if (error == 0)
                    {
                        if (ObjectType->MimeType.charactersLen >= 2)
                        {
                            // string tables and table partitions are not supported, so the length has to be decremented by 2
                            ObjectType->MimeType.charactersLen -= 2;
                            error = exi_basetypes_decoder_characters(stream, ObjectType->MimeType.charactersLen, ObjectType->MimeType.characters, iso20_acdp_MimeType_CHARACTER_SIZE);
                            if (error == 0)
                            {
                                // XML: emit string value
                                xml_write_escaped_attr(xmlOut, xmlOut_size, xmlOut_pos, ObjectType->MimeType.characters, ObjectType->MimeType.charactersLen);
                            }
                        }
                        else
                        {
                            // the string seems to be in the table, but this is not supported
                            error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                        }
                    }
                    ObjectType->MimeType_isUsed = 1u;
                    grammar_id = 47;
                    xml_write(xmlOut, xmlOut_size, xmlOut_pos, "\"", 1);
                    break;
                case 1:
                    // Event: START (ANY, anyType (base64Binary)); next=2
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ANY", 4);
                        (void)xml_tag_start;
                    // decode: event not accepted
                    error = EXI_ERROR__UNKNOWN_EVENT_FOR_DECODING;
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ANY>", 6);
                    }
                    break;
                case 2:
                    // Event: END Element; next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                case 3:
                    // Event: START (ANY, anyType (base64Binary)); next=2
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ANY", 4);
                        (void)xml_tag_start;
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &ObjectType->ANY.bytesLen, &ObjectType->ANY.bytes[0], iso20_acdp_anyType_BYTES_SIZE);
                    if (error == 0)
                    {
                        ObjectType->ANY_isUsed = 1u;
                        // XML: emit base64 encoded value
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                        {
                            static const char encoding_table[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
                            static const int mod_table[] = {0, 2, 1};
                            size_t output_length = 4 * ((ObjectType->ANY.bytesLen + 2) / 3);
                            unsigned char* encoded_data = (unsigned char*)malloc(output_length + 1);
                            if (encoded_data != NULL)
                            {
                                size_t i, j;
                                for (i = 0, j = 0; i < ObjectType->ANY.bytesLen;)
                                {
                                    uint32_t a = i < ObjectType->ANY.bytesLen ? ObjectType->ANY.bytes[i++] : 0;
                                    uint32_t b = i < ObjectType->ANY.bytesLen ? ObjectType->ANY.bytes[i++] : 0;
                                    uint32_t c = i < ObjectType->ANY.bytesLen ? ObjectType->ANY.bytes[i++] : 0;
                                    uint32_t triple = (a << 16) + (b << 8) + c;
                                    encoded_data[j++] = encoding_table[(triple >> 18) & 0x3F];
                                    encoded_data[j++] = encoding_table[(triple >> 12) & 0x3F];
                                    encoded_data[j++] = encoding_table[(triple >> 6) & 0x3F];
                                    encoded_data[j++] = encoding_table[triple & 0x3F];
                                }
                                for (i = 0; i < (size_t)mod_table[ObjectType->ANY.bytesLen % 3]; i++)
                                {
                                    encoded_data[output_length - 1 - i] = '=';
                                }
                                xml_write(xmlOut, xmlOut_size, xmlOut_pos, (char*)encoded_data, output_length);
                                free(encoded_data);
                            }
                            else
                            {
                                xml_write(xmlOut, xmlOut_size, xmlOut_pos, "(base64-alloc-failed)", 21);
                            }
                        }
                        grammar_id = 2;
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ANY>", 6);
                    }
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 47:
            // Grammar: ID=47; read/write bits=2; START (ANY), END Element, START (ANY)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: START (ANY, anyType (base64Binary)); next=2
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ANY", 4);
                        (void)xml_tag_start;
                    // decode: event not accepted
                    error = EXI_ERROR__UNKNOWN_EVENT_FOR_DECODING;
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ANY>", 6);
                    }
                    break;
                case 1:
                    // Event: END Element; next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                case 2:
                    // Event: START (ANY, anyType (base64Binary)); next=2
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ANY", 4);
                        (void)xml_tag_start;
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &ObjectType->ANY.bytesLen, &ObjectType->ANY.bytes[0], iso20_acdp_anyType_BYTES_SIZE);
                    if (error == 0)
                    {
                        ObjectType->ANY_isUsed = 1u;
                        // XML: emit base64 encoded value
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                        {
                            static const char encoding_table[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
                            static const int mod_table[] = {0, 2, 1};
                            size_t output_length = 4 * ((ObjectType->ANY.bytesLen + 2) / 3);
                            unsigned char* encoded_data = (unsigned char*)malloc(output_length + 1);
                            if (encoded_data != NULL)
                            {
                                size_t i, j;
                                for (i = 0, j = 0; i < ObjectType->ANY.bytesLen;)
                                {
                                    uint32_t a = i < ObjectType->ANY.bytesLen ? ObjectType->ANY.bytes[i++] : 0;
                                    uint32_t b = i < ObjectType->ANY.bytesLen ? ObjectType->ANY.bytes[i++] : 0;
                                    uint32_t c = i < ObjectType->ANY.bytesLen ? ObjectType->ANY.bytes[i++] : 0;
                                    uint32_t triple = (a << 16) + (b << 8) + c;
                                    encoded_data[j++] = encoding_table[(triple >> 18) & 0x3F];
                                    encoded_data[j++] = encoding_table[(triple >> 12) & 0x3F];
                                    encoded_data[j++] = encoding_table[(triple >> 6) & 0x3F];
                                    encoded_data[j++] = encoding_table[triple & 0x3F];
                                }
                                for (i = 0; i < (size_t)mod_table[ObjectType->ANY.bytesLen % 3]; i++)
                                {
                                    encoded_data[output_length - 1 - i] = '=';
                                }
                                xml_write(xmlOut, xmlOut_size, xmlOut_pos, (char*)encoded_data, output_length);
                                free(encoded_data);
                            }
                            else
                            {
                                xml_write(xmlOut, xmlOut_size, xmlOut_pos, "(base64-alloc-failed)", 21);
                            }
                        }
                        grammar_id = 2;
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ANY>", 6);
                    }
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: END Element; next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={http://www.w3.org/2000/09/xmldsig#}SignatureValue; type={http://www.w3.org/2000/09/xmldsig#}SignatureValueType; base type=base64Binary; content type=simple;
//          abstract=False; final=False; derivation=extension;
// Particle: Id, ID (0, 1); CONTENT, SignatureValueType (1, 1);
static int decode_iso20_acdp_SignatureValueType(exi_bitstream_t* stream, struct iso20_acdp_SignatureValueType* SignatureValueType, char* xmlOut, size_t xmlOut_size, size_t* xmlOut_pos) {
    int grammar_id = 48;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_acdp_SignatureValueType(SignatureValueType);

    while (!done)
    {
        switch (grammar_id)
        {
        case 48:
            // Grammar: ID=48; read/write bits=2; START (Id), START (CONTENT)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: START (Id, ID (NCName)); next=49
                    // XML: attribute
                    xml_write(xmlOut, xmlOut_size, xmlOut_pos, " Id=\"", 5);
                    // decode: string (len, characters) (Attribute)
                    error = exi_basetypes_decoder_uint_16(stream, &SignatureValueType->Id.charactersLen);
                    if (error == 0)
                    {
                        if (SignatureValueType->Id.charactersLen >= 2)
                        {
                            // string tables and table partitions are not supported, so the length has to be decremented by 2
                            SignatureValueType->Id.charactersLen -= 2;
                            error = exi_basetypes_decoder_characters(stream, SignatureValueType->Id.charactersLen, SignatureValueType->Id.characters, iso20_acdp_Id_CHARACTER_SIZE);
                            if (error == 0)
                            {
                                // XML: emit string value
                                xml_write_escaped_attr(xmlOut, xmlOut_size, xmlOut_pos, SignatureValueType->Id.characters, SignatureValueType->Id.charactersLen);
                            }
                        }
                        else
                        {
                            // the string seems to be in the table, but this is not supported
                            error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                        }
                    }
                    SignatureValueType->Id_isUsed = 1u;
                    grammar_id = 49;
                    xml_write(xmlOut, xmlOut_size, xmlOut_pos, "\"", 1);
                    break;
                case 1:
                    // Event: START (CONTENT, SignatureValueType (base64Binary)); next=2
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<CONTENT", 8);
                        (void)xml_tag_start;
                    // decode exi type: base64Binary (simple)
                    error = exi_basetypes_decoder_uint_16(stream, &SignatureValueType->CONTENT.bytesLen);
                    if (error == 0)
                    {
                        error = exi_basetypes_decoder_bytes(stream, SignatureValueType->CONTENT.bytesLen, &SignatureValueType->CONTENT.bytes[0], iso20_acdp_SignatureValueType_BYTES_SIZE);
                        if (error == 0)
                        {
                            // XML: emit base64 encoded value
                            xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                            {
                                static const char encoding_table[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
                                static const int mod_table[] = {0, 2, 1};
                                size_t output_length = 4 * ((SignatureValueType->CONTENT.bytesLen + 2) / 3);
                                unsigned char* encoded_data = (unsigned char*)malloc(output_length + 1);
                                if (encoded_data != NULL)
                                {
                                    size_t i, j;
                                    for (i = 0, j = 0; i < SignatureValueType->CONTENT.bytesLen;)
                                    {
                                        uint32_t a = i < SignatureValueType->CONTENT.bytesLen ? SignatureValueType->CONTENT.bytes[i++] : 0;
                                        uint32_t b = i < SignatureValueType->CONTENT.bytesLen ? SignatureValueType->CONTENT.bytes[i++] : 0;
                                        uint32_t c = i < SignatureValueType->CONTENT.bytesLen ? SignatureValueType->CONTENT.bytes[i++] : 0;
                                        uint32_t triple = (a << 16) + (b << 8) + c;
                                        encoded_data[j++] = encoding_table[(triple >> 18) & 0x3F];
                                        encoded_data[j++] = encoding_table[(triple >> 12) & 0x3F];
                                        encoded_data[j++] = encoding_table[(triple >> 6) & 0x3F];
                                        encoded_data[j++] = encoding_table[triple & 0x3F];
                                    }
                                    for (i = 0; i < (size_t)mod_table[SignatureValueType->CONTENT.bytesLen % 3]; i++)
                                    {
                                        encoded_data[output_length - 1 - i] = '=';
                                    }
                                    xml_write(xmlOut, xmlOut_size, xmlOut_pos, (char*)encoded_data, output_length);
                                    free(encoded_data);
                                }
                                else
                                {
                                    xml_write(xmlOut, xmlOut_size, xmlOut_pos, "(base64-alloc-failed)", 21);
                                }
                            }
                            grammar_id = 2;
                        }
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</CONTENT>", 10);
                    }
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 49:
            // Grammar: ID=49; read/write bits=1; START (CONTENT)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: START (CONTENT, SignatureValueType (base64Binary)); next=2
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<CONTENT", 8);
                        (void)xml_tag_start;
                    // decode exi type: base64Binary (simple)
                    error = exi_basetypes_decoder_uint_16(stream, &SignatureValueType->CONTENT.bytesLen);
                    if (error == 0)
                    {
                        error = exi_basetypes_decoder_bytes(stream, SignatureValueType->CONTENT.bytesLen, &SignatureValueType->CONTENT.bytes[0], iso20_acdp_SignatureValueType_BYTES_SIZE);
                        if (error == 0)
                        {
                            // XML: emit base64 encoded value
                            xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                            {
                                static const char encoding_table[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
                                static const int mod_table[] = {0, 2, 1};
                                size_t output_length = 4 * ((SignatureValueType->CONTENT.bytesLen + 2) / 3);
                                unsigned char* encoded_data = (unsigned char*)malloc(output_length + 1);
                                if (encoded_data != NULL)
                                {
                                    size_t i, j;
                                    for (i = 0, j = 0; i < SignatureValueType->CONTENT.bytesLen;)
                                    {
                                        uint32_t a = i < SignatureValueType->CONTENT.bytesLen ? SignatureValueType->CONTENT.bytes[i++] : 0;
                                        uint32_t b = i < SignatureValueType->CONTENT.bytesLen ? SignatureValueType->CONTENT.bytes[i++] : 0;
                                        uint32_t c = i < SignatureValueType->CONTENT.bytesLen ? SignatureValueType->CONTENT.bytes[i++] : 0;
                                        uint32_t triple = (a << 16) + (b << 8) + c;
                                        encoded_data[j++] = encoding_table[(triple >> 18) & 0x3F];
                                        encoded_data[j++] = encoding_table[(triple >> 12) & 0x3F];
                                        encoded_data[j++] = encoding_table[(triple >> 6) & 0x3F];
                                        encoded_data[j++] = encoding_table[triple & 0x3F];
                                    }
                                    for (i = 0; i < (size_t)mod_table[SignatureValueType->CONTENT.bytesLen % 3]; i++)
                                    {
                                        encoded_data[output_length - 1 - i] = '=';
                                    }
                                    xml_write(xmlOut, xmlOut_size, xmlOut_pos, (char*)encoded_data, output_length);
                                    free(encoded_data);
                                }
                                else
                                {
                                    xml_write(xmlOut, xmlOut_size, xmlOut_pos, "(base64-alloc-failed)", 21);
                                }
                            }
                            grammar_id = 2;
                        }
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</CONTENT>", 10);
                    }
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: END Element; next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={http://www.w3.org/2000/09/xmldsig#}SignedInfo; type={http://www.w3.org/2000/09/xmldsig#}SignedInfoType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: Id, ID (0, 1); CanonicalizationMethod, CanonicalizationMethodType (1, 1); SignatureMethod, SignatureMethodType (1, 1); Reference, ReferenceType (1, 4) (original max unbounded);
static int decode_iso20_acdp_SignedInfoType(exi_bitstream_t* stream, struct iso20_acdp_SignedInfoType* SignedInfoType, char* xmlOut, size_t xmlOut_size, size_t* xmlOut_pos) {
    int grammar_id = 50;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_acdp_SignedInfoType(SignedInfoType);

    while (!done)
    {
        switch (grammar_id)
        {
        case 50:
            // Grammar: ID=50; read/write bits=2; START (Id), START (CanonicalizationMethod)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: START (Id, ID (NCName)); next=51
                    // XML: attribute
                    xml_write(xmlOut, xmlOut_size, xmlOut_pos, " Id=\"", 5);
                    // decode: string (len, characters) (Attribute)
                    error = exi_basetypes_decoder_uint_16(stream, &SignedInfoType->Id.charactersLen);
                    if (error == 0)
                    {
                        if (SignedInfoType->Id.charactersLen >= 2)
                        {
                            // string tables and table partitions are not supported, so the length has to be decremented by 2
                            SignedInfoType->Id.charactersLen -= 2;
                            error = exi_basetypes_decoder_characters(stream, SignedInfoType->Id.charactersLen, SignedInfoType->Id.characters, iso20_acdp_Id_CHARACTER_SIZE);
                            if (error == 0)
                            {
                                // XML: emit string value
                                xml_write_escaped_attr(xmlOut, xmlOut_size, xmlOut_pos, SignedInfoType->Id.characters, SignedInfoType->Id.charactersLen);
                            }
                        }
                        else
                        {
                            // the string seems to be in the table, but this is not supported
                            error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                        }
                    }
                    SignedInfoType->Id_isUsed = 1u;
                    grammar_id = 51;
                    xml_write(xmlOut, xmlOut_size, xmlOut_pos, "\"", 1);
                    break;
                case 1:
                    // Event: START (CanonicalizationMethod, CanonicalizationMethodType (CanonicalizationMethodType)); next=52
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns1:CanonicalizationMethod", 27);
                        (void)xml_tag_start;
                    // decode: element
                    error = decode_iso20_acdp_CanonicalizationMethodType(stream, &SignedInfoType->CanonicalizationMethod, xmlOut, xmlOut_size, xmlOut_pos);
                    if (error == 0)
                    {
                        grammar_id = 52;
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns1:CanonicalizationMethod>", 29);
                    }
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 51:
            // Grammar: ID=51; read/write bits=1; START (CanonicalizationMethod)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: START (CanonicalizationMethod, CanonicalizationMethodType (CanonicalizationMethodType)); next=52
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns1:CanonicalizationMethod", 27);
                        (void)xml_tag_start;
                    // decode: element
                    error = decode_iso20_acdp_CanonicalizationMethodType(stream, &SignedInfoType->CanonicalizationMethod, xmlOut, xmlOut_size, xmlOut_pos);
                    if (error == 0)
                    {
                        grammar_id = 52;
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns1:CanonicalizationMethod>", 29);
                    }
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 52:
            // Grammar: ID=52; read/write bits=1; START (SignatureMethod)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: START (SignatureMethod, SignatureMethodType (SignatureMethodType)); next=53
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns1:SignatureMethod", 20);
                        (void)xml_tag_start;
                    // decode: element
                    error = decode_iso20_acdp_SignatureMethodType(stream, &SignedInfoType->SignatureMethod, xmlOut, xmlOut_size, xmlOut_pos);
                    if (error == 0)
                    {
                        grammar_id = 53;
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns1:SignatureMethod>", 22);
                    }
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 53:
            // Grammar: ID=53; read/write bits=1; START (Reference)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: START (Reference, ReferenceType (ReferenceType)); next=54
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns1:Reference", 14);
                        (void)xml_tag_start;
                    // decode: element array
                    if (SignedInfoType->Reference.arrayLen < iso20_acdp_ReferenceType_4_ARRAY_SIZE)
                    {
                        error = decode_iso20_acdp_ReferenceType(stream, &SignedInfoType->Reference.array[SignedInfoType->Reference.arrayLen++], xmlOut, xmlOut_size, xmlOut_pos);
                    }
                    else
                    {
                        // static array not large enough, only iso20_acdp_ReferenceType_4_ARRAY_SIZE elements
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 54;
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns1:Reference>", 16);
                    }
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 54:
            // Grammar: ID=54; read/write bits=2; LOOP (Reference), END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: LOOP (Reference, ReferenceType (ReferenceType)); next=54
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns1:Reference", 14);
                        (void)xml_tag_start;
                    // decode: element array
                    if (SignedInfoType->Reference.arrayLen < iso20_acdp_ReferenceType_4_ARRAY_SIZE)
                    {
                        error = decode_iso20_acdp_ReferenceType(stream, &SignedInfoType->Reference.array[SignedInfoType->Reference.arrayLen++], xmlOut, xmlOut_size, xmlOut_pos);
                    }
                    else
                    {
                        // static array not large enough, only iso20_acdp_ReferenceType_4_ARRAY_SIZE elements
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 54;
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns1:Reference>", 16);
                    }
                    break;
                case 1:
                    // Event: END Element; next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: END Element; next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:CommonTypes}EVWLANStrength; type={urn:iso:std:iso:15118:-20:CommonTypes}RationalNumberType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: Exponent, byte (1, 1); Value, short (1, 1);
static int decode_iso20_acdp_RationalNumberType(exi_bitstream_t* stream, struct iso20_acdp_RationalNumberType* RationalNumberType, char* xmlOut, size_t xmlOut_size, size_t* xmlOut_pos) {
    int grammar_id = 55;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_acdp_RationalNumberType(RationalNumberType);

    while (!done)
    {
        switch (grammar_id)
        {
        case 55:
            // Grammar: ID=55; read/write bits=1; START (Exponent)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: START (Exponent, byte (short)); next=56
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns3:Exponent", 13);
                        (void)xml_tag_start;
                    // decode: byte (restricted integer)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 8, &value);
                            if (error == 0)
                            {
                                // type has min_value = -128
                                RationalNumberType->Exponent = (int8_t)(value + -128);
                                // XML: emit value
                                xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                                { char _xv[64]; int _xl = snprintf(_xv, sizeof(_xv), "%d", (int)RationalNumberType->Exponent); xml_write(xmlOut, xmlOut_size, xmlOut_pos, _xv, _xl); }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 56;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns3:Exponent>", 15);
                    }
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 56:
            // Grammar: ID=56; read/write bits=1; START (Value)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: START (Value, short (int)); next=2
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns3:Value", 10);
                        (void)xml_tag_start;
                    // decode: short
                    error = decode_exi_type_integer16(stream, &RationalNumberType->Value);
                    if (error == 0)
                    {
                        // XML: emit value
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                        { char _xv[64]; int _xl = snprintf(_xv, sizeof(_xv), "%d", RationalNumberType->Value); xml_write(xmlOut, xmlOut_size, xmlOut_pos, _xv, _xl); }
                        grammar_id = 2;
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns3:Value>", 12);
                    }
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: END Element; next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={http://www.w3.org/2000/09/xmldsig#}Signature; type={http://www.w3.org/2000/09/xmldsig#}SignatureType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: Id, ID (0, 1); SignedInfo, SignedInfoType (1, 1); SignatureValue, SignatureValueType (1, 1); KeyInfo, KeyInfoType (0, 1); Object, ObjectType (0, 1) (original max unbounded);
static int decode_iso20_acdp_SignatureType(exi_bitstream_t* stream, struct iso20_acdp_SignatureType* SignatureType, char* xmlOut, size_t xmlOut_size, size_t* xmlOut_pos) {
    int grammar_id = 57;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_acdp_SignatureType(SignatureType);

    while (!done)
    {
        switch (grammar_id)
        {
        case 57:
            // Grammar: ID=57; read/write bits=2; START (Id), START (SignedInfo)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: START (Id, ID (NCName)); next=58
                    // XML: attribute
                    xml_write(xmlOut, xmlOut_size, xmlOut_pos, " Id=\"", 5);
                    // decode: string (len, characters) (Attribute)
                    error = exi_basetypes_decoder_uint_16(stream, &SignatureType->Id.charactersLen);
                    if (error == 0)
                    {
                        if (SignatureType->Id.charactersLen >= 2)
                        {
                            // string tables and table partitions are not supported, so the length has to be decremented by 2
                            SignatureType->Id.charactersLen -= 2;
                            error = exi_basetypes_decoder_characters(stream, SignatureType->Id.charactersLen, SignatureType->Id.characters, iso20_acdp_Id_CHARACTER_SIZE);
                            if (error == 0)
                            {
                                // XML: emit string value
                                xml_write_escaped_attr(xmlOut, xmlOut_size, xmlOut_pos, SignatureType->Id.characters, SignatureType->Id.charactersLen);
                            }
                        }
                        else
                        {
                            // the string seems to be in the table, but this is not supported
                            error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                        }
                    }
                    SignatureType->Id_isUsed = 1u;
                    grammar_id = 58;
                    xml_write(xmlOut, xmlOut_size, xmlOut_pos, "\"", 1);
                    break;
                case 1:
                    // Event: START (SignedInfo, SignedInfoType (SignedInfoType)); next=59
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns1:SignedInfo", 15);
                        (void)xml_tag_start;
                    // decode: element
                    error = decode_iso20_acdp_SignedInfoType(stream, &SignatureType->SignedInfo, xmlOut, xmlOut_size, xmlOut_pos);
                    if (error == 0)
                    {
                        grammar_id = 59;
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns1:SignedInfo>", 17);
                    }
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 58:
            // Grammar: ID=58; read/write bits=1; START (SignedInfo)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: START (SignedInfo, SignedInfoType (SignedInfoType)); next=59
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns1:SignedInfo", 15);
                        (void)xml_tag_start;
                    // decode: element
                    error = decode_iso20_acdp_SignedInfoType(stream, &SignatureType->SignedInfo, xmlOut, xmlOut_size, xmlOut_pos);
                    if (error == 0)
                    {
                        grammar_id = 59;
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns1:SignedInfo>", 17);
                    }
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 59:
            // Grammar: ID=59; read/write bits=1; START (SignatureValue)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: START (SignatureValue, SignatureValueType (base64Binary)); next=60
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns1:SignatureValue", 19);
                        (void)xml_tag_start;
                    // decode: element
                    error = decode_iso20_acdp_SignatureValueType(stream, &SignatureType->SignatureValue, xmlOut, xmlOut_size, xmlOut_pos);
                    if (error == 0)
                    {
                        grammar_id = 60;
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns1:SignatureValue>", 21);
                    }
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 60:
            // Grammar: ID=60; read/write bits=2; START (KeyInfo), START (Object), END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: START (KeyInfo, KeyInfoType (KeyInfoType)); next=62
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns1:KeyInfo", 12);
                        (void)xml_tag_start;
                    // decode: element
                    error = decode_iso20_acdp_KeyInfoType(stream, &SignatureType->KeyInfo, xmlOut, xmlOut_size, xmlOut_pos);
                    if (error == 0)
                    {
                        SignatureType->KeyInfo_isUsed = 1u;
                        grammar_id = 62;
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns1:KeyInfo>", 14);
                    }
                    break;
                case 1:
                    // Event: START (Object, ObjectType (ObjectType)); next=61
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns1:Object", 11);
                        (void)xml_tag_start;
                    // decode: element
                    error = decode_iso20_acdp_ObjectType(stream, &SignatureType->Object, xmlOut, xmlOut_size, xmlOut_pos);
                    if (error == 0)
                    {
                        SignatureType->Object_isUsed = 1u;
                        grammar_id = 61;
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns1:Object>", 13);
                    }
                    break;
                case 2:
                    // Event: END Element; next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 61:
            // Grammar: ID=61; read/write bits=2; START (Object), END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: START (Object, ObjectType (ObjectType)); next=2
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns1:Object", 11);
                        (void)xml_tag_start;
                    // decode: element
                    // This element should not occur a further time, its representation was reduced to a single element
                    error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns1:Object>", 13);
                    }
                    break;
                case 1:
                    // Event: END Element; next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 62:
            // Grammar: ID=62; read/write bits=2; START (Object), END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: START (Object, ObjectType (ObjectType)); next=63
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns1:Object", 11);
                        (void)xml_tag_start;
                    // decode: element
                    error = decode_iso20_acdp_ObjectType(stream, &SignatureType->Object, xmlOut, xmlOut_size, xmlOut_pos);
                    if (error == 0)
                    {
                        SignatureType->Object_isUsed = 1u;
                        grammar_id = 63;
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns1:Object>", 13);
                    }
                    break;
                case 1:
                    // Event: END Element; next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 63:
            // Grammar: ID=63; read/write bits=2; START (Object), END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: START (Object, ObjectType (ObjectType)); next=2
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns1:Object", 11);
                        (void)xml_tag_start;
                    // decode: element
                    // This element should not occur a further time, its representation was reduced to a single element
                    error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns1:Object>", 13);
                    }
                    break;
                case 1:
                    // Event: END Element; next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: END Element; next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:ACDP}EVTechnicalStatus; type={urn:iso:std:iso:15118:-20:ACDP}EVTechnicalStatusType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: EVReadyToCharge, boolean (1, 1); EVImmobilizationRequest, boolean (1, 1); EVImmobilized, boolean (0, 1); EVWLANStrength, RationalNumberType (0, 1); EVCPStatus, cpStatusType (0, 1); EVSOC, percentValueType (0, 1); EVErrorCode, errorCodeType (0, 1); EVTimeout, boolean (0, 1);
static int decode_iso20_acdp_EVTechnicalStatusType(exi_bitstream_t* stream, struct iso20_acdp_EVTechnicalStatusType* EVTechnicalStatusType, char* xmlOut, size_t xmlOut_size, size_t* xmlOut_pos) {
    int grammar_id = 64;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_acdp_EVTechnicalStatusType(EVTechnicalStatusType);

    while (!done)
    {
        switch (grammar_id)
        {
        case 64:
            // Grammar: ID=64; read/write bits=1; START (EVReadyToCharge)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: START (EVReadyToCharge, boolean (boolean)); next=65
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns2:EVReadyToCharge", 20);
                        (void)xml_tag_start;
                    // decode: boolean
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 1, &value);
                            if (error == 0)
                            {
                                EVTechnicalStatusType->EVReadyToCharge = value;
                                // XML: emit value
                                xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                                if (value) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, "true", 4); } else { xml_write(xmlOut, xmlOut_size, xmlOut_pos, "false", 5); }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 65;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns2:EVReadyToCharge>", 22);
                    }
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 65:
            // Grammar: ID=65; read/write bits=1; START (EVImmobilizationRequest)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: START (EVImmobilizationRequest, boolean (boolean)); next=66
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns2:EVImmobilizationRequest", 28);
                        (void)xml_tag_start;
                    // decode: boolean
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 1, &value);
                            if (error == 0)
                            {
                                EVTechnicalStatusType->EVImmobilizationRequest = value;
                                // XML: emit value
                                xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                                if (value) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, "true", 4); } else { xml_write(xmlOut, xmlOut_size, xmlOut_pos, "false", 5); }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 66;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns2:EVImmobilizationRequest>", 30);
                    }
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 66:
            // Grammar: ID=66; read/write bits=3; START (EVImmobilized), START (EVWLANStrength), START (EVCPStatus), START (EVSOC), START (EVErrorCode), START (EVTimeout), END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 3, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: START (EVImmobilized, boolean (boolean)); next=67
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns2:EVImmobilized", 18);
                        (void)xml_tag_start;
                    // decode: boolean
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 1, &value);
                            if (error == 0)
                            {
                                EVTechnicalStatusType->EVImmobilized = value;
                                EVTechnicalStatusType->EVImmobilized_isUsed = 1u;
                                // XML: emit value
                                xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                                if (value) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, "true", 4); } else { xml_write(xmlOut, xmlOut_size, xmlOut_pos, "false", 5); }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 67;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns2:EVImmobilized>", 20);
                    }
                    break;
                case 1:
                    // Event: START (EVWLANStrength, RationalNumberType (RationalNumberType)); next=68
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns2:EVWLANStrength", 19);
                        (void)xml_tag_start;
                    // decode: element
                    error = decode_iso20_acdp_RationalNumberType(stream, &EVTechnicalStatusType->EVWLANStrength, xmlOut, xmlOut_size, xmlOut_pos);
                    if (error == 0)
                    {
                        EVTechnicalStatusType->EVWLANStrength_isUsed = 1u;
                        grammar_id = 68;
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns2:EVWLANStrength>", 21);
                    }
                    break;
                case 2:
                    // Event: START (EVCPStatus, cpStatusType (string)); next=69
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns2:EVCPStatus", 15);
                        (void)xml_tag_start;
                    // decode: enum
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 3, &value);
                            if (error == 0)
                            {
                                EVTechnicalStatusType->EVCPStatus = (iso20_acdp_cpStatusType)value;
                                EVTechnicalStatusType->EVCPStatus_isUsed = 1u;
                                // XML: emit value
                                xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                                switch (value) {
                                case 0: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "StateA", 6); break;
                                case 1: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "StateB", 6); break;
                                case 2: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "StateC", 6); break;
                                case 3: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "StateD", 6); break;
                                case 4: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "StateE", 6); break;
                                default: { char _xv[64]; int _xl = snprintf(_xv, sizeof(_xv), "%u", (unsigned int)value); xml_write(xmlOut, xmlOut_size, xmlOut_pos, _xv, _xl); } break;
                                }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 69;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns2:EVCPStatus>", 17);
                    }
                    break;
                case 3:
                    // Event: START (EVSOC, percentValueType (byte)); next=70
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns2:EVSOC", 10);
                        (void)xml_tag_start;
                    // decode: restricted integer (4096 or fewer values)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 7, &value);
                            if (error == 0)
                            {
                                EVTechnicalStatusType->EVSOC = (int8_t)value;
                                EVTechnicalStatusType->EVSOC_isUsed = 1u;
                                // XML: emit value
                                xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                                { char _xv[64]; int _xl = snprintf(_xv, sizeof(_xv), "%d", (int)EVTechnicalStatusType->EVSOC); xml_write(xmlOut, xmlOut_size, xmlOut_pos, _xv, _xl); }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 70;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns2:EVSOC>", 12);
                    }
                    break;
                case 4:
                    // Event: START (EVErrorCode, errorCodeType (string)); next=71
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns2:EVErrorCode", 16);
                        (void)xml_tag_start;
                    // decode: enum
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 4, &value);
                            if (error == 0)
                            {
                                EVTechnicalStatusType->EVErrorCode = (iso20_acdp_errorCodeType)value;
                                EVTechnicalStatusType->EVErrorCode_isUsed = 1u;
                                // XML: emit value
                                xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                                switch (value) {
                                case 0: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "OK_NoEVError", 12); break;
                                case 1: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "FAILED", 6); break;
                                case 2: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "FAILED_EmergencyEvent", 21); break;
                                case 3: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "FAILED_Breaker", 14); break;
                                case 4: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "FAILED_RESSTemperatureInhibit", 29); break;
                                case 5: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "FAILED_RESS", 11); break;
                                case 6: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "FAILED_ChargingCurrentDifferential", 34); break;
                                case 7: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "FAILED_ChargingVoltageOutOfRange", 32); break;
                                case 8: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "FAILED_Reserved1", 16); break;
                                case 9: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "FAILED_Reserved2", 16); break;
                                default: { char _xv[64]; int _xl = snprintf(_xv, sizeof(_xv), "%u", (unsigned int)value); xml_write(xmlOut, xmlOut_size, xmlOut_pos, _xv, _xl); } break;
                                }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 71;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns2:EVErrorCode>", 18);
                    }
                    break;
                case 5:
                    // Event: START (EVTimeout, boolean (boolean)); next=2
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns2:EVTimeout", 14);
                        (void)xml_tag_start;
                    // decode: boolean
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 1, &value);
                            if (error == 0)
                            {
                                EVTechnicalStatusType->EVTimeout = value;
                                EVTechnicalStatusType->EVTimeout_isUsed = 1u;
                                // XML: emit value
                                xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                                if (value) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, "true", 4); } else { xml_write(xmlOut, xmlOut_size, xmlOut_pos, "false", 5); }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 2;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns2:EVTimeout>", 16);
                    }
                    break;
                case 6:
                    // Event: END Element; next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 67:
            // Grammar: ID=67; read/write bits=3; START (EVWLANStrength), START (EVCPStatus), START (EVSOC), START (EVErrorCode), START (EVTimeout), END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 3, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: START (EVWLANStrength, RationalNumberType (RationalNumberType)); next=68
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns2:EVWLANStrength", 19);
                        (void)xml_tag_start;
                    // decode: element
                    error = decode_iso20_acdp_RationalNumberType(stream, &EVTechnicalStatusType->EVWLANStrength, xmlOut, xmlOut_size, xmlOut_pos);
                    if (error == 0)
                    {
                        EVTechnicalStatusType->EVWLANStrength_isUsed = 1u;
                        grammar_id = 68;
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns2:EVWLANStrength>", 21);
                    }
                    break;
                case 1:
                    // Event: START (EVCPStatus, cpStatusType (string)); next=69
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns2:EVCPStatus", 15);
                        (void)xml_tag_start;
                    // decode: enum
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 3, &value);
                            if (error == 0)
                            {
                                EVTechnicalStatusType->EVCPStatus = (iso20_acdp_cpStatusType)value;
                                EVTechnicalStatusType->EVCPStatus_isUsed = 1u;
                                // XML: emit value
                                xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                                switch (value) {
                                case 0: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "StateA", 6); break;
                                case 1: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "StateB", 6); break;
                                case 2: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "StateC", 6); break;
                                case 3: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "StateD", 6); break;
                                case 4: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "StateE", 6); break;
                                default: { char _xv[64]; int _xl = snprintf(_xv, sizeof(_xv), "%u", (unsigned int)value); xml_write(xmlOut, xmlOut_size, xmlOut_pos, _xv, _xl); } break;
                                }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 69;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns2:EVCPStatus>", 17);
                    }
                    break;
                case 2:
                    // Event: START (EVSOC, percentValueType (byte)); next=70
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns2:EVSOC", 10);
                        (void)xml_tag_start;
                    // decode: restricted integer (4096 or fewer values)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 7, &value);
                            if (error == 0)
                            {
                                EVTechnicalStatusType->EVSOC = (int8_t)value;
                                EVTechnicalStatusType->EVSOC_isUsed = 1u;
                                // XML: emit value
                                xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                                { char _xv[64]; int _xl = snprintf(_xv, sizeof(_xv), "%d", (int)EVTechnicalStatusType->EVSOC); xml_write(xmlOut, xmlOut_size, xmlOut_pos, _xv, _xl); }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 70;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns2:EVSOC>", 12);
                    }
                    break;
                case 3:
                    // Event: START (EVErrorCode, errorCodeType (string)); next=71
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns2:EVErrorCode", 16);
                        (void)xml_tag_start;
                    // decode: enum
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 4, &value);
                            if (error == 0)
                            {
                                EVTechnicalStatusType->EVErrorCode = (iso20_acdp_errorCodeType)value;
                                EVTechnicalStatusType->EVErrorCode_isUsed = 1u;
                                // XML: emit value
                                xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                                switch (value) {
                                case 0: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "OK_NoEVError", 12); break;
                                case 1: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "FAILED", 6); break;
                                case 2: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "FAILED_EmergencyEvent", 21); break;
                                case 3: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "FAILED_Breaker", 14); break;
                                case 4: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "FAILED_RESSTemperatureInhibit", 29); break;
                                case 5: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "FAILED_RESS", 11); break;
                                case 6: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "FAILED_ChargingCurrentDifferential", 34); break;
                                case 7: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "FAILED_ChargingVoltageOutOfRange", 32); break;
                                case 8: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "FAILED_Reserved1", 16); break;
                                case 9: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "FAILED_Reserved2", 16); break;
                                default: { char _xv[64]; int _xl = snprintf(_xv, sizeof(_xv), "%u", (unsigned int)value); xml_write(xmlOut, xmlOut_size, xmlOut_pos, _xv, _xl); } break;
                                }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 71;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns2:EVErrorCode>", 18);
                    }
                    break;
                case 4:
                    // Event: START (EVTimeout, boolean (boolean)); next=2
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns2:EVTimeout", 14);
                        (void)xml_tag_start;
                    // decode: boolean
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 1, &value);
                            if (error == 0)
                            {
                                EVTechnicalStatusType->EVTimeout = value;
                                EVTechnicalStatusType->EVTimeout_isUsed = 1u;
                                // XML: emit value
                                xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                                if (value) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, "true", 4); } else { xml_write(xmlOut, xmlOut_size, xmlOut_pos, "false", 5); }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 2;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns2:EVTimeout>", 16);
                    }
                    break;
                case 5:
                    // Event: END Element; next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 68:
            // Grammar: ID=68; read/write bits=3; START (EVCPStatus), START (EVSOC), START (EVErrorCode), START (EVTimeout), END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 3, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: START (EVCPStatus, cpStatusType (string)); next=69
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns2:EVCPStatus", 15);
                        (void)xml_tag_start;
                    // decode: enum
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 3, &value);
                            if (error == 0)
                            {
                                EVTechnicalStatusType->EVCPStatus = (iso20_acdp_cpStatusType)value;
                                EVTechnicalStatusType->EVCPStatus_isUsed = 1u;
                                // XML: emit value
                                xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                                switch (value) {
                                case 0: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "StateA", 6); break;
                                case 1: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "StateB", 6); break;
                                case 2: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "StateC", 6); break;
                                case 3: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "StateD", 6); break;
                                case 4: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "StateE", 6); break;
                                default: { char _xv[64]; int _xl = snprintf(_xv, sizeof(_xv), "%u", (unsigned int)value); xml_write(xmlOut, xmlOut_size, xmlOut_pos, _xv, _xl); } break;
                                }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 69;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns2:EVCPStatus>", 17);
                    }
                    break;
                case 1:
                    // Event: START (EVSOC, percentValueType (byte)); next=70
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns2:EVSOC", 10);
                        (void)xml_tag_start;
                    // decode: restricted integer (4096 or fewer values)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 7, &value);
                            if (error == 0)
                            {
                                EVTechnicalStatusType->EVSOC = (int8_t)value;
                                EVTechnicalStatusType->EVSOC_isUsed = 1u;
                                // XML: emit value
                                xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                                { char _xv[64]; int _xl = snprintf(_xv, sizeof(_xv), "%d", (int)EVTechnicalStatusType->EVSOC); xml_write(xmlOut, xmlOut_size, xmlOut_pos, _xv, _xl); }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 70;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns2:EVSOC>", 12);
                    }
                    break;
                case 2:
                    // Event: START (EVErrorCode, errorCodeType (string)); next=71
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns2:EVErrorCode", 16);
                        (void)xml_tag_start;
                    // decode: enum
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 4, &value);
                            if (error == 0)
                            {
                                EVTechnicalStatusType->EVErrorCode = (iso20_acdp_errorCodeType)value;
                                EVTechnicalStatusType->EVErrorCode_isUsed = 1u;
                                // XML: emit value
                                xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                                switch (value) {
                                case 0: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "OK_NoEVError", 12); break;
                                case 1: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "FAILED", 6); break;
                                case 2: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "FAILED_EmergencyEvent", 21); break;
                                case 3: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "FAILED_Breaker", 14); break;
                                case 4: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "FAILED_RESSTemperatureInhibit", 29); break;
                                case 5: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "FAILED_RESS", 11); break;
                                case 6: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "FAILED_ChargingCurrentDifferential", 34); break;
                                case 7: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "FAILED_ChargingVoltageOutOfRange", 32); break;
                                case 8: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "FAILED_Reserved1", 16); break;
                                case 9: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "FAILED_Reserved2", 16); break;
                                default: { char _xv[64]; int _xl = snprintf(_xv, sizeof(_xv), "%u", (unsigned int)value); xml_write(xmlOut, xmlOut_size, xmlOut_pos, _xv, _xl); } break;
                                }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 71;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns2:EVErrorCode>", 18);
                    }
                    break;
                case 3:
                    // Event: START (EVTimeout, boolean (boolean)); next=2
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns2:EVTimeout", 14);
                        (void)xml_tag_start;
                    // decode: boolean
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 1, &value);
                            if (error == 0)
                            {
                                EVTechnicalStatusType->EVTimeout = value;
                                EVTechnicalStatusType->EVTimeout_isUsed = 1u;
                                // XML: emit value
                                xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                                if (value) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, "true", 4); } else { xml_write(xmlOut, xmlOut_size, xmlOut_pos, "false", 5); }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 2;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns2:EVTimeout>", 16);
                    }
                    break;
                case 4:
                    // Event: END Element; next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 69:
            // Grammar: ID=69; read/write bits=3; START (EVSOC), START (EVErrorCode), START (EVTimeout), END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 3, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: START (EVSOC, percentValueType (byte)); next=70
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns2:EVSOC", 10);
                        (void)xml_tag_start;
                    // decode: restricted integer (4096 or fewer values)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 7, &value);
                            if (error == 0)
                            {
                                EVTechnicalStatusType->EVSOC = (int8_t)value;
                                EVTechnicalStatusType->EVSOC_isUsed = 1u;
                                // XML: emit value
                                xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                                { char _xv[64]; int _xl = snprintf(_xv, sizeof(_xv), "%d", (int)EVTechnicalStatusType->EVSOC); xml_write(xmlOut, xmlOut_size, xmlOut_pos, _xv, _xl); }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 70;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns2:EVSOC>", 12);
                    }
                    break;
                case 1:
                    // Event: START (EVErrorCode, errorCodeType (string)); next=71
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns2:EVErrorCode", 16);
                        (void)xml_tag_start;
                    // decode: enum
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 4, &value);
                            if (error == 0)
                            {
                                EVTechnicalStatusType->EVErrorCode = (iso20_acdp_errorCodeType)value;
                                EVTechnicalStatusType->EVErrorCode_isUsed = 1u;
                                // XML: emit value
                                xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                                switch (value) {
                                case 0: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "OK_NoEVError", 12); break;
                                case 1: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "FAILED", 6); break;
                                case 2: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "FAILED_EmergencyEvent", 21); break;
                                case 3: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "FAILED_Breaker", 14); break;
                                case 4: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "FAILED_RESSTemperatureInhibit", 29); break;
                                case 5: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "FAILED_RESS", 11); break;
                                case 6: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "FAILED_ChargingCurrentDifferential", 34); break;
                                case 7: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "FAILED_ChargingVoltageOutOfRange", 32); break;
                                case 8: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "FAILED_Reserved1", 16); break;
                                case 9: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "FAILED_Reserved2", 16); break;
                                default: { char _xv[64]; int _xl = snprintf(_xv, sizeof(_xv), "%u", (unsigned int)value); xml_write(xmlOut, xmlOut_size, xmlOut_pos, _xv, _xl); } break;
                                }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 71;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns2:EVErrorCode>", 18);
                    }
                    break;
                case 2:
                    // Event: START (EVTimeout, boolean (boolean)); next=2
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns2:EVTimeout", 14);
                        (void)xml_tag_start;
                    // decode: boolean
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 1, &value);
                            if (error == 0)
                            {
                                EVTechnicalStatusType->EVTimeout = value;
                                EVTechnicalStatusType->EVTimeout_isUsed = 1u;
                                // XML: emit value
                                xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                                if (value) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, "true", 4); } else { xml_write(xmlOut, xmlOut_size, xmlOut_pos, "false", 5); }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 2;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns2:EVTimeout>", 16);
                    }
                    break;
                case 3:
                    // Event: END Element; next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 70:
            // Grammar: ID=70; read/write bits=2; START (EVErrorCode), START (EVTimeout), END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: START (EVErrorCode, errorCodeType (string)); next=71
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns2:EVErrorCode", 16);
                        (void)xml_tag_start;
                    // decode: enum
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 4, &value);
                            if (error == 0)
                            {
                                EVTechnicalStatusType->EVErrorCode = (iso20_acdp_errorCodeType)value;
                                EVTechnicalStatusType->EVErrorCode_isUsed = 1u;
                                // XML: emit value
                                xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                                switch (value) {
                                case 0: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "OK_NoEVError", 12); break;
                                case 1: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "FAILED", 6); break;
                                case 2: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "FAILED_EmergencyEvent", 21); break;
                                case 3: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "FAILED_Breaker", 14); break;
                                case 4: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "FAILED_RESSTemperatureInhibit", 29); break;
                                case 5: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "FAILED_RESS", 11); break;
                                case 6: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "FAILED_ChargingCurrentDifferential", 34); break;
                                case 7: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "FAILED_ChargingVoltageOutOfRange", 32); break;
                                case 8: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "FAILED_Reserved1", 16); break;
                                case 9: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "FAILED_Reserved2", 16); break;
                                default: { char _xv[64]; int _xl = snprintf(_xv, sizeof(_xv), "%u", (unsigned int)value); xml_write(xmlOut, xmlOut_size, xmlOut_pos, _xv, _xl); } break;
                                }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 71;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns2:EVErrorCode>", 18);
                    }
                    break;
                case 1:
                    // Event: START (EVTimeout, boolean (boolean)); next=2
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns2:EVTimeout", 14);
                        (void)xml_tag_start;
                    // decode: boolean
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 1, &value);
                            if (error == 0)
                            {
                                EVTechnicalStatusType->EVTimeout = value;
                                EVTechnicalStatusType->EVTimeout_isUsed = 1u;
                                // XML: emit value
                                xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                                if (value) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, "true", 4); } else { xml_write(xmlOut, xmlOut_size, xmlOut_pos, "false", 5); }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 2;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns2:EVTimeout>", 16);
                    }
                    break;
                case 2:
                    // Event: END Element; next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 71:
            // Grammar: ID=71; read/write bits=2; START (EVTimeout), END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: START (EVTimeout, boolean (boolean)); next=2
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns2:EVTimeout", 14);
                        (void)xml_tag_start;
                    // decode: boolean
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 1, &value);
                            if (error == 0)
                            {
                                EVTechnicalStatusType->EVTimeout = value;
                                EVTechnicalStatusType->EVTimeout_isUsed = 1u;
                                // XML: emit value
                                xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                                if (value) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, "true", 4); } else { xml_write(xmlOut, xmlOut_size, xmlOut_pos, "false", 5); }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 2;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns2:EVTimeout>", 16);
                    }
                    break;
                case 1:
                    // Event: END Element; next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: END Element; next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:CommonTypes}Header; type={urn:iso:std:iso:15118:-20:CommonTypes}MessageHeaderType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: SessionID, sessionIDType (1, 1); TimeStamp, unsignedLong (1, 1); Signature, SignatureType (0, 1);
static int decode_iso20_acdp_MessageHeaderType(exi_bitstream_t* stream, struct iso20_acdp_MessageHeaderType* MessageHeaderType, char* xmlOut, size_t xmlOut_size, size_t* xmlOut_pos) {
    int grammar_id = 72;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_acdp_MessageHeaderType(MessageHeaderType);

    while (!done)
    {
        switch (grammar_id)
        {
        case 72:
            // Grammar: ID=72; read/write bits=1; START (SessionID)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: START (SessionID, sessionIDType (hexBinary)); next=73
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns3:SessionID", 14);
                        (void)xml_tag_start;
                    // decode exi type: hexBinary
                    error = decode_exi_type_hex_binary(stream, &MessageHeaderType->SessionID.bytesLen, &MessageHeaderType->SessionID.bytes[0], iso20_acdp_sessionIDType_BYTES_SIZE);
                    if (error == 0)
                    {
                        // XML: emit hex binary value
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                        {
                            uint16_t _i;
                            for (_i = 0; _i < MessageHeaderType->SessionID.bytesLen; _i++)
                            {
                                char _xv[3];
                                snprintf(_xv, sizeof(_xv), "%02X", MessageHeaderType->SessionID.bytes[_i]);
                                xml_write(xmlOut, xmlOut_size, xmlOut_pos, _xv, 2);
                            }
                        }
                        grammar_id = 73;
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns3:SessionID>", 16);
                    }
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 73:
            // Grammar: ID=73; read/write bits=1; START (TimeStamp)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: START (TimeStamp, unsignedLong (nonNegativeInteger)); next=74
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns3:TimeStamp", 14);
                        (void)xml_tag_start;
                    // decode: unsigned long int
                    error = decode_exi_type_uint64(stream, &MessageHeaderType->TimeStamp);
                    if (error == 0)
                    {
                        // XML: emit value
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                        { char _xv[64]; int _xl = snprintf(_xv, sizeof(_xv), "%" PRIu64, MessageHeaderType->TimeStamp); xml_write(xmlOut, xmlOut_size, xmlOut_pos, _xv, _xl); }
                        grammar_id = 74;
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns3:TimeStamp>", 16);
                    }
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 74:
            // Grammar: ID=74; read/write bits=2; START (Signature), END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: START (Signature, SignatureType (SignatureType)); next=2
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns1:Signature", 14);
                        (void)xml_tag_start;
                    // decode: element
                    error = decode_iso20_acdp_SignatureType(stream, &MessageHeaderType->Signature, xmlOut, xmlOut_size, xmlOut_pos);
                    if (error == 0)
                    {
                        MessageHeaderType->Signature_isUsed = 1u;
                        grammar_id = 2;
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns1:Signature>", 16);
                    }
                    break;
                case 1:
                    // Event: END Element; next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: END Element; next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={http://www.w3.org/2000/09/xmldsig#}SignatureProperty; type={http://www.w3.org/2000/09/xmldsig#}SignaturePropertyType; base type=; content type=mixed;
//          abstract=False; final=False; choice=True;
// Particle: Id, ID (0, 1); Target, anyURI (1, 1); ANY, anyType (0, 1);
static int decode_iso20_acdp_SignaturePropertyType(exi_bitstream_t* stream, struct iso20_acdp_SignaturePropertyType* SignaturePropertyType, char* xmlOut, size_t xmlOut_size, size_t* xmlOut_pos) {
    int grammar_id = 75;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_acdp_SignaturePropertyType(SignaturePropertyType);

    while (!done)
    {
        switch (grammar_id)
        {
        case 75:
            // Grammar: ID=75; read/write bits=2; START (Id), START (Target)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: START (Id, ID (NCName)); next=76
                    // XML: attribute
                    xml_write(xmlOut, xmlOut_size, xmlOut_pos, " Id=\"", 5);
                    // decode: string (len, characters) (Attribute)
                    error = exi_basetypes_decoder_uint_16(stream, &SignaturePropertyType->Id.charactersLen);
                    if (error == 0)
                    {
                        if (SignaturePropertyType->Id.charactersLen >= 2)
                        {
                            // string tables and table partitions are not supported, so the length has to be decremented by 2
                            SignaturePropertyType->Id.charactersLen -= 2;
                            error = exi_basetypes_decoder_characters(stream, SignaturePropertyType->Id.charactersLen, SignaturePropertyType->Id.characters, iso20_acdp_Id_CHARACTER_SIZE);
                            if (error == 0)
                            {
                                // XML: emit string value
                                xml_write_escaped_attr(xmlOut, xmlOut_size, xmlOut_pos, SignaturePropertyType->Id.characters, SignaturePropertyType->Id.charactersLen);
                            }
                        }
                        else
                        {
                            // the string seems to be in the table, but this is not supported
                            error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                        }
                    }
                    SignaturePropertyType->Id_isUsed = 1u;
                    grammar_id = 76;
                    xml_write(xmlOut, xmlOut_size, xmlOut_pos, "\"", 1);
                    break;
                case 1:
                    // Event: START (Target, anyURI (anyURI)); next=77
                    // XML: attribute
                    xml_write(xmlOut, xmlOut_size, xmlOut_pos, " Target=\"", 9);
                    // decode: string (len, characters) (Attribute)
                    error = exi_basetypes_decoder_uint_16(stream, &SignaturePropertyType->Target.charactersLen);
                    if (error == 0)
                    {
                        if (SignaturePropertyType->Target.charactersLen >= 2)
                        {
                            // string tables and table partitions are not supported, so the length has to be decremented by 2
                            SignaturePropertyType->Target.charactersLen -= 2;
                            error = exi_basetypes_decoder_characters(stream, SignaturePropertyType->Target.charactersLen, SignaturePropertyType->Target.characters, iso20_acdp_Target_CHARACTER_SIZE);
                            if (error == 0)
                            {
                                // XML: emit string value
                                xml_write_escaped_attr(xmlOut, xmlOut_size, xmlOut_pos, SignaturePropertyType->Target.characters, SignaturePropertyType->Target.charactersLen);
                            }
                        }
                        else
                        {
                            // the string seems to be in the table, but this is not supported
                            error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                        }
                    }
                    grammar_id = 77;
                    xml_write(xmlOut, xmlOut_size, xmlOut_pos, "\"", 1);
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 76:
            // Grammar: ID=76; read/write bits=1; START (Target)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: START (Target, anyURI (anyURI)); next=77
                    // XML: attribute
                    xml_write(xmlOut, xmlOut_size, xmlOut_pos, " Target=\"", 9);
                    // decode: string (len, characters) (Attribute)
                    error = exi_basetypes_decoder_uint_16(stream, &SignaturePropertyType->Target.charactersLen);
                    if (error == 0)
                    {
                        if (SignaturePropertyType->Target.charactersLen >= 2)
                        {
                            // string tables and table partitions are not supported, so the length has to be decremented by 2
                            SignaturePropertyType->Target.charactersLen -= 2;
                            error = exi_basetypes_decoder_characters(stream, SignaturePropertyType->Target.charactersLen, SignaturePropertyType->Target.characters, iso20_acdp_Target_CHARACTER_SIZE);
                            if (error == 0)
                            {
                                // XML: emit string value
                                xml_write_escaped_attr(xmlOut, xmlOut_size, xmlOut_pos, SignaturePropertyType->Target.characters, SignaturePropertyType->Target.charactersLen);
                            }
                        }
                        else
                        {
                            // the string seems to be in the table, but this is not supported
                            error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                        }
                    }
                    grammar_id = 77;
                    xml_write(xmlOut, xmlOut_size, xmlOut_pos, "\"", 1);
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 77:
            // Grammar: ID=77; read/write bits=1; START (ANY)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: START (ANY, anyType (base64Binary)); next=2
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ANY", 4);
                        (void)xml_tag_start;
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &SignaturePropertyType->ANY.bytesLen, &SignaturePropertyType->ANY.bytes[0], iso20_acdp_anyType_BYTES_SIZE);
                    if (error == 0)
                    {
                        SignaturePropertyType->ANY_isUsed = 1u;
                        // XML: emit base64 encoded value
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                        {
                            static const char encoding_table[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
                            static const int mod_table[] = {0, 2, 1};
                            size_t output_length = 4 * ((SignaturePropertyType->ANY.bytesLen + 2) / 3);
                            unsigned char* encoded_data = (unsigned char*)malloc(output_length + 1);
                            if (encoded_data != NULL)
                            {
                                size_t i, j;
                                for (i = 0, j = 0; i < SignaturePropertyType->ANY.bytesLen;)
                                {
                                    uint32_t a = i < SignaturePropertyType->ANY.bytesLen ? SignaturePropertyType->ANY.bytes[i++] : 0;
                                    uint32_t b = i < SignaturePropertyType->ANY.bytesLen ? SignaturePropertyType->ANY.bytes[i++] : 0;
                                    uint32_t c = i < SignaturePropertyType->ANY.bytesLen ? SignaturePropertyType->ANY.bytes[i++] : 0;
                                    uint32_t triple = (a << 16) + (b << 8) + c;
                                    encoded_data[j++] = encoding_table[(triple >> 18) & 0x3F];
                                    encoded_data[j++] = encoding_table[(triple >> 12) & 0x3F];
                                    encoded_data[j++] = encoding_table[(triple >> 6) & 0x3F];
                                    encoded_data[j++] = encoding_table[triple & 0x3F];
                                }
                                for (i = 0; i < (size_t)mod_table[SignaturePropertyType->ANY.bytesLen % 3]; i++)
                                {
                                    encoded_data[output_length - 1 - i] = '=';
                                }
                                xml_write(xmlOut, xmlOut_size, xmlOut_pos, (char*)encoded_data, output_length);
                                free(encoded_data);
                            }
                            else
                            {
                                xml_write(xmlOut, xmlOut_size, xmlOut_pos, "(base64-alloc-failed)", 21);
                            }
                        }
                        grammar_id = 2;
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ANY>", 6);
                    }
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: END Element; next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:ACDP}ACDP_ConnectReq; type={urn:iso:std:iso:15118:-20:ACDP}ACDP_ConnectReqType; base type=V2GRequestType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: Header, MessageHeaderType (1, 1); EVElectricalChargingDeviceStatus, electricalChargingDeviceStatusType (1, 1);
static int decode_iso20_acdp_ACDP_ConnectReqType(exi_bitstream_t* stream, struct iso20_acdp_ACDP_ConnectReqType* ACDP_ConnectReqType, char* xmlOut, size_t xmlOut_size, size_t* xmlOut_pos) {
    int grammar_id = 78;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_acdp_ACDP_ConnectReqType(ACDP_ConnectReqType);

    while (!done)
    {
        switch (grammar_id)
        {
        case 78:
            // Grammar: ID=78; read/write bits=1; START (Header)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: START (Header, MessageHeaderType (MessageHeaderType)); next=79
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns3:Header", 11);
                        (void)xml_tag_start;
                    // decode: element
                    error = decode_iso20_acdp_MessageHeaderType(stream, &ACDP_ConnectReqType->Header, xmlOut, xmlOut_size, xmlOut_pos);
                    if (error == 0)
                    {
                        grammar_id = 79;
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns3:Header>", 13);
                    }
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 79:
            // Grammar: ID=79; read/write bits=1; START (EVElectricalChargingDeviceStatus)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: START (EVElectricalChargingDeviceStatus, electricalChargingDeviceStatusType (string)); next=2
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns2:EVElectricalChargingDeviceStatus", 37);
                        (void)xml_tag_start;
                    // decode: enum
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 2, &value);
                            if (error == 0)
                            {
                                ACDP_ConnectReqType->EVElectricalChargingDeviceStatus = (iso20_acdp_electricalChargingDeviceStatusType)value;
                                // XML: emit value
                                xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                                switch (value) {
                                case 0: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "State_A", 7); break;
                                case 1: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "State_B", 7); break;
                                case 2: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "State_C", 7); break;
                                case 3: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "State_D", 7); break;
                                default: { char _xv[64]; int _xl = snprintf(_xv, sizeof(_xv), "%u", (unsigned int)value); xml_write(xmlOut, xmlOut_size, xmlOut_pos, _xv, _xl); } break;
                                }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 2;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns2:EVElectricalChargingDeviceStatus>", 39);
                    }
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: END Element; next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:ACDP}ACDP_ConnectRes; type={urn:iso:std:iso:15118:-20:ACDP}ACDP_ConnectResType; base type=V2GResponseType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: Header, MessageHeaderType (1, 1); ResponseCode, responseCodeType (1, 1); EVSEProcessing, processingType (1, 1); EVSEElectricalChargingDeviceStatus, electricalChargingDeviceStatusType (1, 1); EVSEMechanicalChargingDeviceStatus, mechanicalChargingDeviceStatusType (1, 1);
static int decode_iso20_acdp_ACDP_ConnectResType(exi_bitstream_t* stream, struct iso20_acdp_ACDP_ConnectResType* ACDP_ConnectResType, char* xmlOut, size_t xmlOut_size, size_t* xmlOut_pos) {
    int grammar_id = 80;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_acdp_ACDP_ConnectResType(ACDP_ConnectResType);

    while (!done)
    {
        switch (grammar_id)
        {
        case 80:
            // Grammar: ID=80; read/write bits=1; START (Header)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: START (Header, MessageHeaderType (MessageHeaderType)); next=81
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns3:Header", 11);
                        (void)xml_tag_start;
                    // decode: element
                    error = decode_iso20_acdp_MessageHeaderType(stream, &ACDP_ConnectResType->Header, xmlOut, xmlOut_size, xmlOut_pos);
                    if (error == 0)
                    {
                        grammar_id = 81;
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns3:Header>", 13);
                    }
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 81:
            // Grammar: ID=81; read/write bits=1; START (ResponseCode)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: START (ResponseCode, responseCodeType (string)); next=82
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns3:ResponseCode", 17);
                        (void)xml_tag_start;
                    // decode: enum
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 6, &value);
                            if (error == 0)
                            {
                                ACDP_ConnectResType->ResponseCode = (iso20_acdp_responseCodeType)value;
                                // XML: emit value
                                xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                                switch (value) {
                                case 0: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "OK", 2); break;
                                case 1: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "OK_CertificateExpiresSoon", 25); break;
                                case 2: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "OK_NewSessionEstablished", 24); break;
                                case 3: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "OK_OldSessionJoined", 19); break;
                                case 4: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "OK_PowerToleranceConfirmed", 26); break;
                                case 5: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "WARNING_AuthorizationSelectionInvalid", 37); break;
                                case 6: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "WARNING_CertificateExpired", 26); break;
                                case 7: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "WARNING_CertificateNotYetValid", 30); break;
                                case 8: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "WARNING_CertificateRevoked", 26); break;
                                case 9: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "WARNING_CertificateValidationError", 34); break;
                                case 10: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "WARNING_ChallengeInvalid", 24); break;
                                case 11: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "WARNING_EIMAuthorizationFailure", 31); break;
                                case 12: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "WARNING_eMSPUnknown", 19); break;
                                case 13: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "WARNING_EVPowerProfileViolation", 31); break;
                                case 14: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "WARNING_GeneralPnCAuthorizationError", 36); break;
                                case 15: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "WARNING_NoCertificateAvailable", 30); break;
                                case 16: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "WARNING_NoContractMatchingPCIDFound", 35); break;
                                case 17: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "WARNING_PowerToleranceNotConfirmed", 34); break;
                                case 18: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "WARNING_ScheduleRenegotiationFailed", 35); break;
                                case 19: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "WARNING_StandbyNotAllowed", 25); break;
                                case 20: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "WARNING_WPT", 11); break;
                                case 21: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "FAILED", 6); break;
                                case 22: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "FAILED_AssociationError", 23); break;
                                case 23: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "FAILED_ContactorError", 21); break;
                                case 24: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "FAILED_EVPowerProfileInvalid", 28); break;
                                case 25: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "FAILED_EVPowerProfileViolation", 30); break;
                                case 26: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "FAILED_MeteringSignatureNotValid", 32); break;
                                case 27: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "FAILED_NoEnergyTransferServiceSelected", 38); break;
                                case 28: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "FAILED_NoServiceRenegotiationSupported", 38); break;
                                case 29: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "FAILED_PauseNotAllowed", 22); break;
                                case 30: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "FAILED_PowerDeliveryNotApplied", 30); break;
                                case 31: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "FAILED_PowerToleranceNotConfirmed", 33); break;
                                case 32: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "FAILED_ScheduleRenegotiation", 28); break;
                                case 33: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "FAILED_ScheduleSelectionInvalid", 31); break;
                                case 34: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "FAILED_SequenceError", 20); break;
                                case 35: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "FAILED_ServiceIDInvalid", 23); break;
                                case 36: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "FAILED_ServiceSelectionInvalid", 30); break;
                                case 37: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "FAILED_SignatureError", 21); break;
                                case 38: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "FAILED_UnknownSession", 21); break;
                                case 39: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "FAILED_WrongChargeParameter", 27); break;
                                default: { char _xv[64]; int _xl = snprintf(_xv, sizeof(_xv), "%u", (unsigned int)value); xml_write(xmlOut, xmlOut_size, xmlOut_pos, _xv, _xl); } break;
                                }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 82;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns3:ResponseCode>", 19);
                    }
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 82:
            // Grammar: ID=82; read/write bits=1; START (EVSEProcessing)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: START (EVSEProcessing, processingType (string)); next=83
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns2:EVSEProcessing", 19);
                        (void)xml_tag_start;
                    // decode: enum
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 2, &value);
                            if (error == 0)
                            {
                                ACDP_ConnectResType->EVSEProcessing = (iso20_acdp_processingType)value;
                                // XML: emit value
                                xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                                switch (value) {
                                case 0: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "Finished", 8); break;
                                case 1: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "Ongoing", 7); break;
                                case 2: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "Ongoing_WaitingForCustomerInteraction", 37); break;
                                default: { char _xv[64]; int _xl = snprintf(_xv, sizeof(_xv), "%u", (unsigned int)value); xml_write(xmlOut, xmlOut_size, xmlOut_pos, _xv, _xl); } break;
                                }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 83;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns2:EVSEProcessing>", 21);
                    }
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 83:
            // Grammar: ID=83; read/write bits=1; START (EVSEElectricalChargingDeviceStatus)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: START (EVSEElectricalChargingDeviceStatus, electricalChargingDeviceStatusType (string)); next=84
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns2:EVSEElectricalChargingDeviceStatus", 39);
                        (void)xml_tag_start;
                    // decode: enum
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 2, &value);
                            if (error == 0)
                            {
                                ACDP_ConnectResType->EVSEElectricalChargingDeviceStatus = (iso20_acdp_electricalChargingDeviceStatusType)value;
                                // XML: emit value
                                xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                                switch (value) {
                                case 0: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "State_A", 7); break;
                                case 1: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "State_B", 7); break;
                                case 2: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "State_C", 7); break;
                                case 3: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "State_D", 7); break;
                                default: { char _xv[64]; int _xl = snprintf(_xv, sizeof(_xv), "%u", (unsigned int)value); xml_write(xmlOut, xmlOut_size, xmlOut_pos, _xv, _xl); } break;
                                }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 84;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns2:EVSEElectricalChargingDeviceStatus>", 41);
                    }
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 84:
            // Grammar: ID=84; read/write bits=1; START (EVSEMechanicalChargingDeviceStatus)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: START (EVSEMechanicalChargingDeviceStatus, mechanicalChargingDeviceStatusType (string)); next=2
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns2:EVSEMechanicalChargingDeviceStatus", 39);
                        (void)xml_tag_start;
                    // decode: enum
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 2, &value);
                            if (error == 0)
                            {
                                ACDP_ConnectResType->EVSEMechanicalChargingDeviceStatus = (iso20_acdp_mechanicalChargingDeviceStatusType)value;
                                // XML: emit value
                                xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                                switch (value) {
                                case 0: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "Home", 4); break;
                                case 1: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "Moving", 6); break;
                                case 2: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "EndPosition", 11); break;
                                default: { char _xv[64]; int _xl = snprintf(_xv, sizeof(_xv), "%u", (unsigned int)value); xml_write(xmlOut, xmlOut_size, xmlOut_pos, _xv, _xl); } break;
                                }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 2;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns2:EVSEMechanicalChargingDeviceStatus>", 41);
                    }
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: END Element; next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:ACDP}ACDP_SystemStatusReq; type={urn:iso:std:iso:15118:-20:ACDP}ACDP_SystemStatusReqType; base type=V2GRequestType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: Header, MessageHeaderType (1, 1); EVTechnicalStatus, EVTechnicalStatusType (1, 1);
static int decode_iso20_acdp_ACDP_SystemStatusReqType(exi_bitstream_t* stream, struct iso20_acdp_ACDP_SystemStatusReqType* ACDP_SystemStatusReqType, char* xmlOut, size_t xmlOut_size, size_t* xmlOut_pos) {
    int grammar_id = 85;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_acdp_ACDP_SystemStatusReqType(ACDP_SystemStatusReqType);

    while (!done)
    {
        switch (grammar_id)
        {
        case 85:
            // Grammar: ID=85; read/write bits=1; START (Header)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: START (Header, MessageHeaderType (MessageHeaderType)); next=86
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns3:Header", 11);
                        (void)xml_tag_start;
                    // decode: element
                    error = decode_iso20_acdp_MessageHeaderType(stream, &ACDP_SystemStatusReqType->Header, xmlOut, xmlOut_size, xmlOut_pos);
                    if (error == 0)
                    {
                        grammar_id = 86;
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns3:Header>", 13);
                    }
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 86:
            // Grammar: ID=86; read/write bits=1; START (EVTechnicalStatus)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: START (EVTechnicalStatus, EVTechnicalStatusType (EVTechnicalStatusType)); next=2
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns2:EVTechnicalStatus", 22);
                        (void)xml_tag_start;
                    // decode: element
                    error = decode_iso20_acdp_EVTechnicalStatusType(stream, &ACDP_SystemStatusReqType->EVTechnicalStatus, xmlOut, xmlOut_size, xmlOut_pos);
                    if (error == 0)
                    {
                        grammar_id = 2;
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns2:EVTechnicalStatus>", 24);
                    }
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: END Element; next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:ACDP}ACDP_SystemStatusRes; type={urn:iso:std:iso:15118:-20:ACDP}ACDP_SystemStatusResType; base type=V2GResponseType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: Header, MessageHeaderType (1, 1); ResponseCode, responseCodeType (1, 1); EVSEMechanicalChargingDeviceStatus, mechanicalChargingDeviceStatusType (1, 1); EVSEReadyToCharge, boolean (1, 1); EVSEIsolationStatus, isolationStatusType (1, 1); EVSEDisabled, boolean (1, 1); EVSEUtilityInterruptEvent, boolean (1, 1); EVSEEmergencyShutdown, boolean (1, 1); EVSEMalfunction, boolean (1, 1); EVInChargePosition, boolean (1, 1); EVAssociationStatus, boolean (1, 1);
static int decode_iso20_acdp_ACDP_SystemStatusResType(exi_bitstream_t* stream, struct iso20_acdp_ACDP_SystemStatusResType* ACDP_SystemStatusResType, char* xmlOut, size_t xmlOut_size, size_t* xmlOut_pos) {
    int grammar_id = 87;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_acdp_ACDP_SystemStatusResType(ACDP_SystemStatusResType);

    while (!done)
    {
        switch (grammar_id)
        {
        case 87:
            // Grammar: ID=87; read/write bits=1; START (Header)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: START (Header, MessageHeaderType (MessageHeaderType)); next=88
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns3:Header", 11);
                        (void)xml_tag_start;
                    // decode: element
                    error = decode_iso20_acdp_MessageHeaderType(stream, &ACDP_SystemStatusResType->Header, xmlOut, xmlOut_size, xmlOut_pos);
                    if (error == 0)
                    {
                        grammar_id = 88;
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns3:Header>", 13);
                    }
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 88:
            // Grammar: ID=88; read/write bits=1; START (ResponseCode)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: START (ResponseCode, responseCodeType (string)); next=89
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns3:ResponseCode", 17);
                        (void)xml_tag_start;
                    // decode: enum
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 6, &value);
                            if (error == 0)
                            {
                                ACDP_SystemStatusResType->ResponseCode = (iso20_acdp_responseCodeType)value;
                                // XML: emit value
                                xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                                switch (value) {
                                case 0: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "OK", 2); break;
                                case 1: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "OK_CertificateExpiresSoon", 25); break;
                                case 2: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "OK_NewSessionEstablished", 24); break;
                                case 3: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "OK_OldSessionJoined", 19); break;
                                case 4: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "OK_PowerToleranceConfirmed", 26); break;
                                case 5: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "WARNING_AuthorizationSelectionInvalid", 37); break;
                                case 6: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "WARNING_CertificateExpired", 26); break;
                                case 7: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "WARNING_CertificateNotYetValid", 30); break;
                                case 8: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "WARNING_CertificateRevoked", 26); break;
                                case 9: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "WARNING_CertificateValidationError", 34); break;
                                case 10: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "WARNING_ChallengeInvalid", 24); break;
                                case 11: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "WARNING_EIMAuthorizationFailure", 31); break;
                                case 12: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "WARNING_eMSPUnknown", 19); break;
                                case 13: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "WARNING_EVPowerProfileViolation", 31); break;
                                case 14: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "WARNING_GeneralPnCAuthorizationError", 36); break;
                                case 15: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "WARNING_NoCertificateAvailable", 30); break;
                                case 16: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "WARNING_NoContractMatchingPCIDFound", 35); break;
                                case 17: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "WARNING_PowerToleranceNotConfirmed", 34); break;
                                case 18: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "WARNING_ScheduleRenegotiationFailed", 35); break;
                                case 19: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "WARNING_StandbyNotAllowed", 25); break;
                                case 20: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "WARNING_WPT", 11); break;
                                case 21: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "FAILED", 6); break;
                                case 22: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "FAILED_AssociationError", 23); break;
                                case 23: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "FAILED_ContactorError", 21); break;
                                case 24: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "FAILED_EVPowerProfileInvalid", 28); break;
                                case 25: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "FAILED_EVPowerProfileViolation", 30); break;
                                case 26: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "FAILED_MeteringSignatureNotValid", 32); break;
                                case 27: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "FAILED_NoEnergyTransferServiceSelected", 38); break;
                                case 28: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "FAILED_NoServiceRenegotiationSupported", 38); break;
                                case 29: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "FAILED_PauseNotAllowed", 22); break;
                                case 30: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "FAILED_PowerDeliveryNotApplied", 30); break;
                                case 31: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "FAILED_PowerToleranceNotConfirmed", 33); break;
                                case 32: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "FAILED_ScheduleRenegotiation", 28); break;
                                case 33: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "FAILED_ScheduleSelectionInvalid", 31); break;
                                case 34: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "FAILED_SequenceError", 20); break;
                                case 35: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "FAILED_ServiceIDInvalid", 23); break;
                                case 36: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "FAILED_ServiceSelectionInvalid", 30); break;
                                case 37: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "FAILED_SignatureError", 21); break;
                                case 38: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "FAILED_UnknownSession", 21); break;
                                case 39: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "FAILED_WrongChargeParameter", 27); break;
                                default: { char _xv[64]; int _xl = snprintf(_xv, sizeof(_xv), "%u", (unsigned int)value); xml_write(xmlOut, xmlOut_size, xmlOut_pos, _xv, _xl); } break;
                                }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 89;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns3:ResponseCode>", 19);
                    }
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 89:
            // Grammar: ID=89; read/write bits=1; START (EVSEMechanicalChargingDeviceStatus)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: START (EVSEMechanicalChargingDeviceStatus, mechanicalChargingDeviceStatusType (string)); next=90
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns2:EVSEMechanicalChargingDeviceStatus", 39);
                        (void)xml_tag_start;
                    // decode: enum
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 2, &value);
                            if (error == 0)
                            {
                                ACDP_SystemStatusResType->EVSEMechanicalChargingDeviceStatus = (iso20_acdp_mechanicalChargingDeviceStatusType)value;
                                // XML: emit value
                                xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                                switch (value) {
                                case 0: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "Home", 4); break;
                                case 1: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "Moving", 6); break;
                                case 2: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "EndPosition", 11); break;
                                default: { char _xv[64]; int _xl = snprintf(_xv, sizeof(_xv), "%u", (unsigned int)value); xml_write(xmlOut, xmlOut_size, xmlOut_pos, _xv, _xl); } break;
                                }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 90;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns2:EVSEMechanicalChargingDeviceStatus>", 41);
                    }
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 90:
            // Grammar: ID=90; read/write bits=1; START (EVSEReadyToCharge)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: START (EVSEReadyToCharge, boolean (boolean)); next=91
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns2:EVSEReadyToCharge", 22);
                        (void)xml_tag_start;
                    // decode: boolean
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 1, &value);
                            if (error == 0)
                            {
                                ACDP_SystemStatusResType->EVSEReadyToCharge = value;
                                // XML: emit value
                                xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                                if (value) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, "true", 4); } else { xml_write(xmlOut, xmlOut_size, xmlOut_pos, "false", 5); }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 91;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns2:EVSEReadyToCharge>", 24);
                    }
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 91:
            // Grammar: ID=91; read/write bits=1; START (EVSEIsolationStatus)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: START (EVSEIsolationStatus, isolationStatusType (string)); next=92
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns2:EVSEIsolationStatus", 24);
                        (void)xml_tag_start;
                    // decode: enum
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 2, &value);
                            if (error == 0)
                            {
                                ACDP_SystemStatusResType->EVSEIsolationStatus = (iso20_acdp_isolationStatusType)value;
                                // XML: emit value
                                xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                                switch (value) {
                                case 0: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "Invalid", 7); break;
                                case 1: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "Safe", 4); break;
                                case 2: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "Warning", 7); break;
                                case 3: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "Fault", 5); break;
                                default: { char _xv[64]; int _xl = snprintf(_xv, sizeof(_xv), "%u", (unsigned int)value); xml_write(xmlOut, xmlOut_size, xmlOut_pos, _xv, _xl); } break;
                                }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 92;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns2:EVSEIsolationStatus>", 26);
                    }
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 92:
            // Grammar: ID=92; read/write bits=1; START (EVSEDisabled)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: START (EVSEDisabled, boolean (boolean)); next=93
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns2:EVSEDisabled", 17);
                        (void)xml_tag_start;
                    // decode: boolean
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 1, &value);
                            if (error == 0)
                            {
                                ACDP_SystemStatusResType->EVSEDisabled = value;
                                // XML: emit value
                                xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                                if (value) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, "true", 4); } else { xml_write(xmlOut, xmlOut_size, xmlOut_pos, "false", 5); }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 93;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns2:EVSEDisabled>", 19);
                    }
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 93:
            // Grammar: ID=93; read/write bits=1; START (EVSEUtilityInterruptEvent)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: START (EVSEUtilityInterruptEvent, boolean (boolean)); next=94
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns2:EVSEUtilityInterruptEvent", 30);
                        (void)xml_tag_start;
                    // decode: boolean
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 1, &value);
                            if (error == 0)
                            {
                                ACDP_SystemStatusResType->EVSEUtilityInterruptEvent = value;
                                // XML: emit value
                                xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                                if (value) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, "true", 4); } else { xml_write(xmlOut, xmlOut_size, xmlOut_pos, "false", 5); }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 94;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns2:EVSEUtilityInterruptEvent>", 32);
                    }
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 94:
            // Grammar: ID=94; read/write bits=1; START (EVSEEmergencyShutdown)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: START (EVSEEmergencyShutdown, boolean (boolean)); next=95
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns2:EVSEEmergencyShutdown", 26);
                        (void)xml_tag_start;
                    // decode: boolean
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 1, &value);
                            if (error == 0)
                            {
                                ACDP_SystemStatusResType->EVSEEmergencyShutdown = value;
                                // XML: emit value
                                xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                                if (value) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, "true", 4); } else { xml_write(xmlOut, xmlOut_size, xmlOut_pos, "false", 5); }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 95;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns2:EVSEEmergencyShutdown>", 28);
                    }
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 95:
            // Grammar: ID=95; read/write bits=1; START (EVSEMalfunction)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: START (EVSEMalfunction, boolean (boolean)); next=96
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns2:EVSEMalfunction", 20);
                        (void)xml_tag_start;
                    // decode: boolean
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 1, &value);
                            if (error == 0)
                            {
                                ACDP_SystemStatusResType->EVSEMalfunction = value;
                                // XML: emit value
                                xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                                if (value) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, "true", 4); } else { xml_write(xmlOut, xmlOut_size, xmlOut_pos, "false", 5); }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 96;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns2:EVSEMalfunction>", 22);
                    }
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 96:
            // Grammar: ID=96; read/write bits=1; START (EVInChargePosition)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: START (EVInChargePosition, boolean (boolean)); next=97
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns2:EVInChargePosition", 23);
                        (void)xml_tag_start;
                    // decode: boolean
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 1, &value);
                            if (error == 0)
                            {
                                ACDP_SystemStatusResType->EVInChargePosition = value;
                                // XML: emit value
                                xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                                if (value) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, "true", 4); } else { xml_write(xmlOut, xmlOut_size, xmlOut_pos, "false", 5); }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 97;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns2:EVInChargePosition>", 25);
                    }
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 97:
            // Grammar: ID=97; read/write bits=1; START (EVAssociationStatus)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: START (EVAssociationStatus, boolean (boolean)); next=2
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns2:EVAssociationStatus", 24);
                        (void)xml_tag_start;
                    // decode: boolean
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 1, &value);
                            if (error == 0)
                            {
                                ACDP_SystemStatusResType->EVAssociationStatus = value;
                                // XML: emit value
                                xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                                if (value) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, "true", 4); } else { xml_write(xmlOut, xmlOut_size, xmlOut_pos, "false", 5); }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 2;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns2:EVAssociationStatus>", 26);
                    }
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: END Element; next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:ACDP}ACDP_VehiclePositioningReq; type={urn:iso:std:iso:15118:-20:ACDP}ACDP_VehiclePositioningReqType; base type=V2GRequestType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: Header, MessageHeaderType (1, 1); EVMobilityStatus, boolean (1, 1); EVPositioningSupport, boolean (1, 1);
static int decode_iso20_acdp_ACDP_VehiclePositioningReqType(exi_bitstream_t* stream, struct iso20_acdp_ACDP_VehiclePositioningReqType* ACDP_VehiclePositioningReqType, char* xmlOut, size_t xmlOut_size, size_t* xmlOut_pos) {
    int grammar_id = 98;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_acdp_ACDP_VehiclePositioningReqType(ACDP_VehiclePositioningReqType);

    while (!done)
    {
        switch (grammar_id)
        {
        case 98:
            // Grammar: ID=98; read/write bits=1; START (Header)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: START (Header, MessageHeaderType (MessageHeaderType)); next=99
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns3:Header", 11);
                        (void)xml_tag_start;
                    // decode: element
                    error = decode_iso20_acdp_MessageHeaderType(stream, &ACDP_VehiclePositioningReqType->Header, xmlOut, xmlOut_size, xmlOut_pos);
                    if (error == 0)
                    {
                        grammar_id = 99;
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns3:Header>", 13);
                    }
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 99:
            // Grammar: ID=99; read/write bits=1; START (EVMobilityStatus)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: START (EVMobilityStatus, boolean (boolean)); next=100
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns2:EVMobilityStatus", 21);
                        (void)xml_tag_start;
                    // decode: boolean
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 1, &value);
                            if (error == 0)
                            {
                                ACDP_VehiclePositioningReqType->EVMobilityStatus = value;
                                // XML: emit value
                                xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                                if (value) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, "true", 4); } else { xml_write(xmlOut, xmlOut_size, xmlOut_pos, "false", 5); }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 100;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns2:EVMobilityStatus>", 23);
                    }
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 100:
            // Grammar: ID=100; read/write bits=1; START (EVPositioningSupport)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: START (EVPositioningSupport, boolean (boolean)); next=2
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns2:EVPositioningSupport", 25);
                        (void)xml_tag_start;
                    // decode: boolean
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 1, &value);
                            if (error == 0)
                            {
                                ACDP_VehiclePositioningReqType->EVPositioningSupport = value;
                                // XML: emit value
                                xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                                if (value) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, "true", 4); } else { xml_write(xmlOut, xmlOut_size, xmlOut_pos, "false", 5); }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 2;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns2:EVPositioningSupport>", 27);
                    }
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: END Element; next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:ACDP}ACDP_VehiclePositioningRes; type={urn:iso:std:iso:15118:-20:ACDP}ACDP_VehiclePositioningResType; base type=V2GResponseType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: Header, MessageHeaderType (1, 1); ResponseCode, responseCodeType (1, 1); EVSEProcessing, processingType (1, 1); EVSEPositioningSupport, boolean (1, 1); EVRelativeXDeviation, short (1, 1); EVRelativeYDeviation, short (1, 1); ContactWindowXc, short (1, 1); ContactWindowYc, short (1, 1); EVInChargePosition, boolean (1, 1);
static int decode_iso20_acdp_ACDP_VehiclePositioningResType(exi_bitstream_t* stream, struct iso20_acdp_ACDP_VehiclePositioningResType* ACDP_VehiclePositioningResType, char* xmlOut, size_t xmlOut_size, size_t* xmlOut_pos) {
    int grammar_id = 101;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_acdp_ACDP_VehiclePositioningResType(ACDP_VehiclePositioningResType);

    while (!done)
    {
        switch (grammar_id)
        {
        case 101:
            // Grammar: ID=101; read/write bits=1; START (Header)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: START (Header, MessageHeaderType (MessageHeaderType)); next=102
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns3:Header", 11);
                        (void)xml_tag_start;
                    // decode: element
                    error = decode_iso20_acdp_MessageHeaderType(stream, &ACDP_VehiclePositioningResType->Header, xmlOut, xmlOut_size, xmlOut_pos);
                    if (error == 0)
                    {
                        grammar_id = 102;
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns3:Header>", 13);
                    }
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 102:
            // Grammar: ID=102; read/write bits=1; START (ResponseCode)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: START (ResponseCode, responseCodeType (string)); next=103
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns3:ResponseCode", 17);
                        (void)xml_tag_start;
                    // decode: enum
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 6, &value);
                            if (error == 0)
                            {
                                ACDP_VehiclePositioningResType->ResponseCode = (iso20_acdp_responseCodeType)value;
                                // XML: emit value
                                xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                                switch (value) {
                                case 0: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "OK", 2); break;
                                case 1: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "OK_CertificateExpiresSoon", 25); break;
                                case 2: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "OK_NewSessionEstablished", 24); break;
                                case 3: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "OK_OldSessionJoined", 19); break;
                                case 4: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "OK_PowerToleranceConfirmed", 26); break;
                                case 5: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "WARNING_AuthorizationSelectionInvalid", 37); break;
                                case 6: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "WARNING_CertificateExpired", 26); break;
                                case 7: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "WARNING_CertificateNotYetValid", 30); break;
                                case 8: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "WARNING_CertificateRevoked", 26); break;
                                case 9: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "WARNING_CertificateValidationError", 34); break;
                                case 10: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "WARNING_ChallengeInvalid", 24); break;
                                case 11: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "WARNING_EIMAuthorizationFailure", 31); break;
                                case 12: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "WARNING_eMSPUnknown", 19); break;
                                case 13: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "WARNING_EVPowerProfileViolation", 31); break;
                                case 14: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "WARNING_GeneralPnCAuthorizationError", 36); break;
                                case 15: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "WARNING_NoCertificateAvailable", 30); break;
                                case 16: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "WARNING_NoContractMatchingPCIDFound", 35); break;
                                case 17: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "WARNING_PowerToleranceNotConfirmed", 34); break;
                                case 18: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "WARNING_ScheduleRenegotiationFailed", 35); break;
                                case 19: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "WARNING_StandbyNotAllowed", 25); break;
                                case 20: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "WARNING_WPT", 11); break;
                                case 21: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "FAILED", 6); break;
                                case 22: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "FAILED_AssociationError", 23); break;
                                case 23: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "FAILED_ContactorError", 21); break;
                                case 24: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "FAILED_EVPowerProfileInvalid", 28); break;
                                case 25: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "FAILED_EVPowerProfileViolation", 30); break;
                                case 26: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "FAILED_MeteringSignatureNotValid", 32); break;
                                case 27: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "FAILED_NoEnergyTransferServiceSelected", 38); break;
                                case 28: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "FAILED_NoServiceRenegotiationSupported", 38); break;
                                case 29: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "FAILED_PauseNotAllowed", 22); break;
                                case 30: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "FAILED_PowerDeliveryNotApplied", 30); break;
                                case 31: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "FAILED_PowerToleranceNotConfirmed", 33); break;
                                case 32: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "FAILED_ScheduleRenegotiation", 28); break;
                                case 33: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "FAILED_ScheduleSelectionInvalid", 31); break;
                                case 34: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "FAILED_SequenceError", 20); break;
                                case 35: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "FAILED_ServiceIDInvalid", 23); break;
                                case 36: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "FAILED_ServiceSelectionInvalid", 30); break;
                                case 37: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "FAILED_SignatureError", 21); break;
                                case 38: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "FAILED_UnknownSession", 21); break;
                                case 39: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "FAILED_WrongChargeParameter", 27); break;
                                default: { char _xv[64]; int _xl = snprintf(_xv, sizeof(_xv), "%u", (unsigned int)value); xml_write(xmlOut, xmlOut_size, xmlOut_pos, _xv, _xl); } break;
                                }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 103;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns3:ResponseCode>", 19);
                    }
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 103:
            // Grammar: ID=103; read/write bits=1; START (EVSEProcessing)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: START (EVSEProcessing, processingType (string)); next=104
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns2:EVSEProcessing", 19);
                        (void)xml_tag_start;
                    // decode: enum
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 2, &value);
                            if (error == 0)
                            {
                                ACDP_VehiclePositioningResType->EVSEProcessing = (iso20_acdp_processingType)value;
                                // XML: emit value
                                xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                                switch (value) {
                                case 0: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "Finished", 8); break;
                                case 1: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "Ongoing", 7); break;
                                case 2: xml_write_escaped_text(xmlOut, xmlOut_size, xmlOut_pos, "Ongoing_WaitingForCustomerInteraction", 37); break;
                                default: { char _xv[64]; int _xl = snprintf(_xv, sizeof(_xv), "%u", (unsigned int)value); xml_write(xmlOut, xmlOut_size, xmlOut_pos, _xv, _xl); } break;
                                }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 104;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns2:EVSEProcessing>", 21);
                    }
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 104:
            // Grammar: ID=104; read/write bits=1; START (EVSEPositioningSupport)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: START (EVSEPositioningSupport, boolean (boolean)); next=105
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns2:EVSEPositioningSupport", 27);
                        (void)xml_tag_start;
                    // decode: boolean
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 1, &value);
                            if (error == 0)
                            {
                                ACDP_VehiclePositioningResType->EVSEPositioningSupport = value;
                                // XML: emit value
                                xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                                if (value) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, "true", 4); } else { xml_write(xmlOut, xmlOut_size, xmlOut_pos, "false", 5); }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 105;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns2:EVSEPositioningSupport>", 29);
                    }
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 105:
            // Grammar: ID=105; read/write bits=1; START (EVRelativeXDeviation)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: START (EVRelativeXDeviation, short (int)); next=106
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns2:EVRelativeXDeviation", 25);
                        (void)xml_tag_start;
                    // decode: short
                    error = decode_exi_type_integer16(stream, &ACDP_VehiclePositioningResType->EVRelativeXDeviation);
                    if (error == 0)
                    {
                        // XML: emit value
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                        { char _xv[64]; int _xl = snprintf(_xv, sizeof(_xv), "%d", ACDP_VehiclePositioningResType->EVRelativeXDeviation); xml_write(xmlOut, xmlOut_size, xmlOut_pos, _xv, _xl); }
                        grammar_id = 106;
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns2:EVRelativeXDeviation>", 27);
                    }
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 106:
            // Grammar: ID=106; read/write bits=1; START (EVRelativeYDeviation)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: START (EVRelativeYDeviation, short (int)); next=107
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns2:EVRelativeYDeviation", 25);
                        (void)xml_tag_start;
                    // decode: short
                    error = decode_exi_type_integer16(stream, &ACDP_VehiclePositioningResType->EVRelativeYDeviation);
                    if (error == 0)
                    {
                        // XML: emit value
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                        { char _xv[64]; int _xl = snprintf(_xv, sizeof(_xv), "%d", ACDP_VehiclePositioningResType->EVRelativeYDeviation); xml_write(xmlOut, xmlOut_size, xmlOut_pos, _xv, _xl); }
                        grammar_id = 107;
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns2:EVRelativeYDeviation>", 27);
                    }
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 107:
            // Grammar: ID=107; read/write bits=1; START (ContactWindowXc)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: START (ContactWindowXc, short (int)); next=108
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns2:ContactWindowXc", 20);
                        (void)xml_tag_start;
                    // decode: short
                    error = decode_exi_type_integer16(stream, &ACDP_VehiclePositioningResType->ContactWindowXc);
                    if (error == 0)
                    {
                        // XML: emit value
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                        { char _xv[64]; int _xl = snprintf(_xv, sizeof(_xv), "%d", ACDP_VehiclePositioningResType->ContactWindowXc); xml_write(xmlOut, xmlOut_size, xmlOut_pos, _xv, _xl); }
                        grammar_id = 108;
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns2:ContactWindowXc>", 22);
                    }
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 108:
            // Grammar: ID=108; read/write bits=1; START (ContactWindowYc)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: START (ContactWindowYc, short (int)); next=109
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns2:ContactWindowYc", 20);
                        (void)xml_tag_start;
                    // decode: short
                    error = decode_exi_type_integer16(stream, &ACDP_VehiclePositioningResType->ContactWindowYc);
                    if (error == 0)
                    {
                        // XML: emit value
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                        { char _xv[64]; int _xl = snprintf(_xv, sizeof(_xv), "%d", ACDP_VehiclePositioningResType->ContactWindowYc); xml_write(xmlOut, xmlOut_size, xmlOut_pos, _xv, _xl); }
                        grammar_id = 109;
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns2:ContactWindowYc>", 22);
                    }
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 109:
            // Grammar: ID=109; read/write bits=1; START (EVInChargePosition)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: START (EVInChargePosition, boolean (boolean)); next=2
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns2:EVInChargePosition", 23);
                        (void)xml_tag_start;
                    // decode: boolean
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 1, &value);
                            if (error == 0)
                            {
                                ACDP_VehiclePositioningResType->EVInChargePosition = value;
                                // XML: emit value
                                xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                                if (value) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, "true", 4); } else { xml_write(xmlOut, xmlOut_size, xmlOut_pos, "false", 5); }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 2;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns2:EVInChargePosition>", 25);
                    }
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: END Element; next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:CommonTypes}CLReqControlMode; type={urn:iso:std:iso:15118:-20:CommonTypes}CLReqControlModeType; base type=; content type=empty;
//          abstract=False; final=False;
static int decode_iso20_acdp_CLReqControlModeType(exi_bitstream_t* stream, struct iso20_acdp_CLReqControlModeType* CLReqControlModeType, char* xmlOut, size_t xmlOut_size, size_t* xmlOut_pos) {
    // Element has no particles, so the function just decodes END Element
    (void)CLReqControlModeType;
    uint32_t eventCode;

    int error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
    if (error == 0)
    {
        if (eventCode != 0)
        {
            error = EXI_ERROR__UNKNOWN_EVENT_CODE;
        }
    }

    return error;
}

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:CommonTypes}CLResControlMode; type={urn:iso:std:iso:15118:-20:CommonTypes}CLResControlModeType; base type=; content type=empty;
//          abstract=False; final=False;
static int decode_iso20_acdp_CLResControlModeType(exi_bitstream_t* stream, struct iso20_acdp_CLResControlModeType* CLResControlModeType, char* xmlOut, size_t xmlOut_size, size_t* xmlOut_pos) {
    // Element has no particles, so the function just decodes END Element
    (void)CLResControlModeType;
    uint32_t eventCode;

    int error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
    if (error == 0)
    {
        if (eventCode != 0)
        {
            error = EXI_ERROR__UNKNOWN_EVENT_CODE;
        }
    }

    return error;
}

// Element: definition=complex; name={http://www.w3.org/2000/09/xmldsig#}Manifest; type={http://www.w3.org/2000/09/xmldsig#}ManifestType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: Id, ID (0, 1); Reference, ReferenceType (1, 4) (original max unbounded);
static int decode_iso20_acdp_ManifestType(exi_bitstream_t* stream, struct iso20_acdp_ManifestType* ManifestType, char* xmlOut, size_t xmlOut_size, size_t* xmlOut_pos) {
    int grammar_id = 110;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_acdp_ManifestType(ManifestType);

    while (!done)
    {
        switch (grammar_id)
        {
        case 110:
            // Grammar: ID=110; read/write bits=2; START (Id), START (Reference)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: START (Id, ID (NCName)); next=112
                    // XML: attribute
                    xml_write(xmlOut, xmlOut_size, xmlOut_pos, " Id=\"", 5);
                    // decode: string (len, characters) (Attribute)
                    error = exi_basetypes_decoder_uint_16(stream, &ManifestType->Id.charactersLen);
                    if (error == 0)
                    {
                        if (ManifestType->Id.charactersLen >= 2)
                        {
                            // string tables and table partitions are not supported, so the length has to be decremented by 2
                            ManifestType->Id.charactersLen -= 2;
                            error = exi_basetypes_decoder_characters(stream, ManifestType->Id.charactersLen, ManifestType->Id.characters, iso20_acdp_Id_CHARACTER_SIZE);
                            if (error == 0)
                            {
                                // XML: emit string value
                                xml_write_escaped_attr(xmlOut, xmlOut_size, xmlOut_pos, ManifestType->Id.characters, ManifestType->Id.charactersLen);
                            }
                        }
                        else
                        {
                            // the string seems to be in the table, but this is not supported
                            error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                        }
                    }
                    ManifestType->Id_isUsed = 1u;
                    grammar_id = 112;
                    xml_write(xmlOut, xmlOut_size, xmlOut_pos, "\"", 1);
                    break;
                case 1:
                    // Event: START (Reference, ReferenceType (ReferenceType)); next=111
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns1:Reference", 14);
                        (void)xml_tag_start;
                    // decode: element array
                    if (ManifestType->Reference.arrayLen < iso20_acdp_ReferenceType_4_ARRAY_SIZE)
                    {
                        error = decode_iso20_acdp_ReferenceType(stream, &ManifestType->Reference.array[ManifestType->Reference.arrayLen++], xmlOut, xmlOut_size, xmlOut_pos);
                    }
                    else
                    {
                        // static array not large enough, only iso20_acdp_ReferenceType_4_ARRAY_SIZE elements
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 111;
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns1:Reference>", 16);
                    }
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 111:
            // Grammar: ID=111; read/write bits=2; LOOP (Reference), END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: LOOP (Reference, ReferenceType (ReferenceType)); next=111
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns1:Reference", 14);
                        (void)xml_tag_start;
                    // decode: element array
                    if (ManifestType->Reference.arrayLen < iso20_acdp_ReferenceType_4_ARRAY_SIZE)
                    {
                        error = decode_iso20_acdp_ReferenceType(stream, &ManifestType->Reference.array[ManifestType->Reference.arrayLen++], xmlOut, xmlOut_size, xmlOut_pos);
                    }
                    else
                    {
                        // static array not large enough, only iso20_acdp_ReferenceType_4_ARRAY_SIZE elements
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 111;
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns1:Reference>", 16);
                    }
                    break;
                case 1:
                    // Event: END Element; next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 112:
            // Grammar: ID=112; read/write bits=1; START (Reference)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: START (Reference, ReferenceType (ReferenceType)); next=113
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns1:Reference", 14);
                        (void)xml_tag_start;
                    // decode: element array
                    if (ManifestType->Reference.arrayLen < iso20_acdp_ReferenceType_4_ARRAY_SIZE)
                    {
                        error = decode_iso20_acdp_ReferenceType(stream, &ManifestType->Reference.array[ManifestType->Reference.arrayLen++], xmlOut, xmlOut_size, xmlOut_pos);
                    }
                    else
                    {
                        // static array not large enough, only iso20_acdp_ReferenceType_4_ARRAY_SIZE elements
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 113;
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns1:Reference>", 16);
                    }
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 113:
            // Grammar: ID=113; read/write bits=2; LOOP (Reference), END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: LOOP (Reference, ReferenceType (ReferenceType)); next=113
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns1:Reference", 14);
                        (void)xml_tag_start;
                    // decode: element array
                    if (ManifestType->Reference.arrayLen < iso20_acdp_ReferenceType_4_ARRAY_SIZE)
                    {
                        error = decode_iso20_acdp_ReferenceType(stream, &ManifestType->Reference.array[ManifestType->Reference.arrayLen++], xmlOut, xmlOut_size, xmlOut_pos);
                    }
                    else
                    {
                        // static array not large enough, only iso20_acdp_ReferenceType_4_ARRAY_SIZE elements
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 113;
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns1:Reference>", 16);
                    }
                    break;
                case 1:
                    // Event: END Element; next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: END Element; next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={http://www.w3.org/2000/09/xmldsig#}SignatureProperties; type={http://www.w3.org/2000/09/xmldsig#}SignaturePropertiesType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: Id, ID (0, 1); SignatureProperty, SignaturePropertyType (1, 1) (original max unbounded);
static int decode_iso20_acdp_SignaturePropertiesType(exi_bitstream_t* stream, struct iso20_acdp_SignaturePropertiesType* SignaturePropertiesType, char* xmlOut, size_t xmlOut_size, size_t* xmlOut_pos) {
    int grammar_id = 114;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_acdp_SignaturePropertiesType(SignaturePropertiesType);

    while (!done)
    {
        switch (grammar_id)
        {
        case 114:
            // Grammar: ID=114; read/write bits=2; START (Id), START (SignatureProperty)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: START (Id, ID (NCName)); next=116
                    // XML: attribute
                    xml_write(xmlOut, xmlOut_size, xmlOut_pos, " Id=\"", 5);
                    // decode: string (len, characters) (Attribute)
                    error = exi_basetypes_decoder_uint_16(stream, &SignaturePropertiesType->Id.charactersLen);
                    if (error == 0)
                    {
                        if (SignaturePropertiesType->Id.charactersLen >= 2)
                        {
                            // string tables and table partitions are not supported, so the length has to be decremented by 2
                            SignaturePropertiesType->Id.charactersLen -= 2;
                            error = exi_basetypes_decoder_characters(stream, SignaturePropertiesType->Id.charactersLen, SignaturePropertiesType->Id.characters, iso20_acdp_Id_CHARACTER_SIZE);
                            if (error == 0)
                            {
                                // XML: emit string value
                                xml_write_escaped_attr(xmlOut, xmlOut_size, xmlOut_pos, SignaturePropertiesType->Id.characters, SignaturePropertiesType->Id.charactersLen);
                            }
                        }
                        else
                        {
                            // the string seems to be in the table, but this is not supported
                            error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                        }
                    }
                    SignaturePropertiesType->Id_isUsed = 1u;
                    grammar_id = 116;
                    xml_write(xmlOut, xmlOut_size, xmlOut_pos, "\"", 1);
                    break;
                case 1:
                    // Event: START (SignatureProperty, SignaturePropertyType (SignaturePropertyType)); next=115
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns1:SignatureProperty", 22);
                        (void)xml_tag_start;
                    // decode: element
                    error = decode_iso20_acdp_SignaturePropertyType(stream, &SignaturePropertiesType->SignatureProperty, xmlOut, xmlOut_size, xmlOut_pos);
                    if (error == 0)
                    {
                        grammar_id = 115;
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns1:SignatureProperty>", 24);
                    }
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 115:
            // Grammar: ID=115; read/write bits=2; START (SignatureProperty), END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: START (SignatureProperty, SignaturePropertyType (SignaturePropertyType)); next=2
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns1:SignatureProperty", 22);
                        (void)xml_tag_start;
                    // decode: element
                    // This element should not occur a further time, its representation was reduced to a single element
                    error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns1:SignatureProperty>", 24);
                    }
                    break;
                case 1:
                    // Event: END Element; next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 116:
            // Grammar: ID=116; read/write bits=1; START (SignatureProperty)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: START (SignatureProperty, SignaturePropertyType (SignaturePropertyType)); next=117
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns1:SignatureProperty", 22);
                        (void)xml_tag_start;
                    // decode: element
                    error = decode_iso20_acdp_SignaturePropertyType(stream, &SignaturePropertiesType->SignatureProperty, xmlOut, xmlOut_size, xmlOut_pos);
                    if (error == 0)
                    {
                        grammar_id = 117;
                    }
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns1:SignatureProperty>", 24);
                    }
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 117:
            // Grammar: ID=117; read/write bits=2; START (SignatureProperty), END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: START (SignatureProperty, SignaturePropertyType (SignaturePropertyType)); next=2
                    // XML: open tag
                    if (*xmlOut_pos > 0 && xmlOut[*xmlOut_pos - 1] != '>')
                    {
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1);
                    }
                    {
                        size_t xml_tag_start = *xmlOut_pos;
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "<ns1:SignatureProperty", 22);
                        (void)xml_tag_start;
                    // decode: element
                    // This element should not occur a further time, its representation was reduced to a single element
                    error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                        // XML: close tag
                        {
                            int xml_closed = 0;
                            size_t i;
                            for (i = xml_tag_start; i < *xmlOut_pos; i++)
                            {
                                if (xmlOut[i] == '>') { xml_closed = 1; break; }
                            }
                            if (!xml_closed) { xml_write(xmlOut, xmlOut_size, xmlOut_pos, ">", 1); }
                        }
                        xml_write(xmlOut, xmlOut_size, xmlOut_pos, "</ns1:SignatureProperty>", 24);
                    }
                    break;
                case 1:
                    // Event: END Element; next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch (eventCode)
                {
                case 0:
                    // Event: END Element; next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}


// main function for decoding
int decode_iso20_acdp_exiDocument(exi_bitstream_t* stream, struct iso20_acdp_exiDocument* exiDoc, char* xmlOut, size_t xmlOut_size) {
    uint32_t eventCode;
    int error = exi_header_read_and_check(stream);

    size_t xmlOut_pos = xml_init(xmlOut, xmlOut_size);

    if (error == 0)
    {
        init_iso20_acdp_exiDocument(exiDoc);

        // XML: write XML declaration
        xml_write(xmlOut, xmlOut_size, &xmlOut_pos, "<?xml version=\"1.0\" encoding=\"UTF-8\"?>", 38);

        error = exi_basetypes_decoder_nbit_uint(stream, 6, &eventCode);
        if (error == 0)
        {
            switch (eventCode)
            {
            case 0:
                // XML: open tag with xmlns declarations
                xml_write(xmlOut, xmlOut_size, &xmlOut_pos, "<ns2:ACDP_ConnectReq xmlns:ns1=\"http://www.w3.org/2000/09/xmldsig#\" xmlns:ns2=\"urn:iso:std:iso:15118:-20:ACDP\" xmlns:ns3=\"urn:iso:std:iso:15118:-20:CommonTypes\">", 161);
                error = decode_iso20_acdp_ACDP_ConnectReqType(stream, &exiDoc->ACDP_ConnectReq, xmlOut, xmlOut_size, &xmlOut_pos);
                exiDoc->ACDP_ConnectReq_isUsed = 1u;
                // XML: close tag
                if (error == 0)
                {
                    xml_write(xmlOut, xmlOut_size, &xmlOut_pos, "</ns2:ACDP_ConnectReq>", 22);
                }
                break;
            case 1:
                // XML: open tag with xmlns declarations
                xml_write(xmlOut, xmlOut_size, &xmlOut_pos, "<ns2:ACDP_DisconnectReq xmlns:ns1=\"http://www.w3.org/2000/09/xmldsig#\" xmlns:ns2=\"urn:iso:std:iso:15118:-20:ACDP\" xmlns:ns3=\"urn:iso:std:iso:15118:-20:CommonTypes\">", 164);
                error = decode_iso20_acdp_ACDP_ConnectReqType(stream, &exiDoc->ACDP_DisconnectReq, xmlOut, xmlOut_size, &xmlOut_pos);
                exiDoc->ACDP_DisconnectReq_isUsed = 1u;
                // XML: close tag
                if (error == 0)
                {
                    xml_write(xmlOut, xmlOut_size, &xmlOut_pos, "</ns2:ACDP_DisconnectReq>", 25);
                }
                break;
            case 2:
                // XML: open tag with xmlns declarations
                xml_write(xmlOut, xmlOut_size, &xmlOut_pos, "<ns2:ACDP_ConnectRes xmlns:ns1=\"http://www.w3.org/2000/09/xmldsig#\" xmlns:ns2=\"urn:iso:std:iso:15118:-20:ACDP\" xmlns:ns3=\"urn:iso:std:iso:15118:-20:CommonTypes\">", 161);
                error = decode_iso20_acdp_ACDP_ConnectResType(stream, &exiDoc->ACDP_ConnectRes, xmlOut, xmlOut_size, &xmlOut_pos);
                exiDoc->ACDP_ConnectRes_isUsed = 1u;
                // XML: close tag
                if (error == 0)
                {
                    xml_write(xmlOut, xmlOut_size, &xmlOut_pos, "</ns2:ACDP_ConnectRes>", 22);
                }
                break;
            case 3:
                // XML: open tag with xmlns declarations
                xml_write(xmlOut, xmlOut_size, &xmlOut_pos, "<ns2:ACDP_DisconnectRes xmlns:ns1=\"http://www.w3.org/2000/09/xmldsig#\" xmlns:ns2=\"urn:iso:std:iso:15118:-20:ACDP\" xmlns:ns3=\"urn:iso:std:iso:15118:-20:CommonTypes\">", 164);
                error = decode_iso20_acdp_ACDP_ConnectResType(stream, &exiDoc->ACDP_DisconnectRes, xmlOut, xmlOut_size, &xmlOut_pos);
                exiDoc->ACDP_DisconnectRes_isUsed = 1u;
                // XML: close tag
                if (error == 0)
                {
                    xml_write(xmlOut, xmlOut_size, &xmlOut_pos, "</ns2:ACDP_DisconnectRes>", 25);
                }
                break;
            case 4:
                // XML: open tag with xmlns declarations
                xml_write(xmlOut, xmlOut_size, &xmlOut_pos, "<ns2:ACDP_SystemStatusReq xmlns:ns1=\"http://www.w3.org/2000/09/xmldsig#\" xmlns:ns2=\"urn:iso:std:iso:15118:-20:ACDP\" xmlns:ns3=\"urn:iso:std:iso:15118:-20:CommonTypes\">", 166);
                error = decode_iso20_acdp_ACDP_SystemStatusReqType(stream, &exiDoc->ACDP_SystemStatusReq, xmlOut, xmlOut_size, &xmlOut_pos);
                exiDoc->ACDP_SystemStatusReq_isUsed = 1u;
                // XML: close tag
                if (error == 0)
                {
                    xml_write(xmlOut, xmlOut_size, &xmlOut_pos, "</ns2:ACDP_SystemStatusReq>", 27);
                }
                break;
            case 5:
                // XML: open tag with xmlns declarations
                xml_write(xmlOut, xmlOut_size, &xmlOut_pos, "<ns2:ACDP_SystemStatusRes xmlns:ns1=\"http://www.w3.org/2000/09/xmldsig#\" xmlns:ns2=\"urn:iso:std:iso:15118:-20:ACDP\" xmlns:ns3=\"urn:iso:std:iso:15118:-20:CommonTypes\">", 166);
                error = decode_iso20_acdp_ACDP_SystemStatusResType(stream, &exiDoc->ACDP_SystemStatusRes, xmlOut, xmlOut_size, &xmlOut_pos);
                exiDoc->ACDP_SystemStatusRes_isUsed = 1u;
                // XML: close tag
                if (error == 0)
                {
                    xml_write(xmlOut, xmlOut_size, &xmlOut_pos, "</ns2:ACDP_SystemStatusRes>", 27);
                }
                break;
            case 6:
                // XML: open tag with xmlns declarations
                xml_write(xmlOut, xmlOut_size, &xmlOut_pos, "<ns2:ACDP_VehiclePositioningReq xmlns:ns1=\"http://www.w3.org/2000/09/xmldsig#\" xmlns:ns2=\"urn:iso:std:iso:15118:-20:ACDP\" xmlns:ns3=\"urn:iso:std:iso:15118:-20:CommonTypes\">", 172);
                error = decode_iso20_acdp_ACDP_VehiclePositioningReqType(stream, &exiDoc->ACDP_VehiclePositioningReq, xmlOut, xmlOut_size, &xmlOut_pos);
                exiDoc->ACDP_VehiclePositioningReq_isUsed = 1u;
                // XML: close tag
                if (error == 0)
                {
                    xml_write(xmlOut, xmlOut_size, &xmlOut_pos, "</ns2:ACDP_VehiclePositioningReq>", 33);
                }
                break;
            case 7:
                // XML: open tag with xmlns declarations
                xml_write(xmlOut, xmlOut_size, &xmlOut_pos, "<ns2:ACDP_VehiclePositioningRes xmlns:ns1=\"http://www.w3.org/2000/09/xmldsig#\" xmlns:ns2=\"urn:iso:std:iso:15118:-20:ACDP\" xmlns:ns3=\"urn:iso:std:iso:15118:-20:CommonTypes\">", 172);
                error = decode_iso20_acdp_ACDP_VehiclePositioningResType(stream, &exiDoc->ACDP_VehiclePositioningRes, xmlOut, xmlOut_size, &xmlOut_pos);
                exiDoc->ACDP_VehiclePositioningRes_isUsed = 1u;
                // XML: close tag
                if (error == 0)
                {
                    xml_write(xmlOut, xmlOut_size, &xmlOut_pos, "</ns2:ACDP_VehiclePositioningRes>", 33);
                }
                break;
            case 8:
                // XML: open tag with xmlns declarations
                xml_write(xmlOut, xmlOut_size, &xmlOut_pos, "<ns3:CLReqControlMode xmlns:ns1=\"http://www.w3.org/2000/09/xmldsig#\" xmlns:ns2=\"urn:iso:std:iso:15118:-20:ACDP\" xmlns:ns3=\"urn:iso:std:iso:15118:-20:CommonTypes\">", 162);
                error = decode_iso20_acdp_CLReqControlModeType(stream, &exiDoc->CLReqControlMode, xmlOut, xmlOut_size, &xmlOut_pos);
                exiDoc->CLReqControlMode_isUsed = 1u;
                // XML: close tag
                if (error == 0)
                {
                    xml_write(xmlOut, xmlOut_size, &xmlOut_pos, "</ns3:CLReqControlMode>", 23);
                }
                break;
            case 9:
                // XML: open tag with xmlns declarations
                xml_write(xmlOut, xmlOut_size, &xmlOut_pos, "<ns3:CLResControlMode xmlns:ns1=\"http://www.w3.org/2000/09/xmldsig#\" xmlns:ns2=\"urn:iso:std:iso:15118:-20:ACDP\" xmlns:ns3=\"urn:iso:std:iso:15118:-20:CommonTypes\">", 162);
                error = decode_iso20_acdp_CLResControlModeType(stream, &exiDoc->CLResControlMode, xmlOut, xmlOut_size, &xmlOut_pos);
                exiDoc->CLResControlMode_isUsed = 1u;
                // XML: close tag
                if (error == 0)
                {
                    xml_write(xmlOut, xmlOut_size, &xmlOut_pos, "</ns3:CLResControlMode>", 23);
                }
                break;
            case 10:
                // XML: open tag with xmlns declarations
                xml_write(xmlOut, xmlOut_size, &xmlOut_pos, "<ns1:CanonicalizationMethod xmlns:ns1=\"http://www.w3.org/2000/09/xmldsig#\" xmlns:ns2=\"urn:iso:std:iso:15118:-20:ACDP\" xmlns:ns3=\"urn:iso:std:iso:15118:-20:CommonTypes\">", 168);
                error = decode_iso20_acdp_CanonicalizationMethodType(stream, &exiDoc->CanonicalizationMethod, xmlOut, xmlOut_size, &xmlOut_pos);
                exiDoc->CanonicalizationMethod_isUsed = 1u;
                // XML: close tag
                if (error == 0)
                {
                    xml_write(xmlOut, xmlOut_size, &xmlOut_pos, "</ns1:CanonicalizationMethod>", 29);
                }
                break;
            case 11:
                // XML: open tag with xmlns declarations
                xml_write(xmlOut, xmlOut_size, &xmlOut_pos, "<ns1:DSAKeyValue xmlns:ns1=\"http://www.w3.org/2000/09/xmldsig#\" xmlns:ns2=\"urn:iso:std:iso:15118:-20:ACDP\" xmlns:ns3=\"urn:iso:std:iso:15118:-20:CommonTypes\">", 157);
                error = decode_iso20_acdp_DSAKeyValueType(stream, &exiDoc->DSAKeyValue, xmlOut, xmlOut_size, &xmlOut_pos);
                exiDoc->DSAKeyValue_isUsed = 1u;
                // XML: close tag
                if (error == 0)
                {
                    xml_write(xmlOut, xmlOut_size, &xmlOut_pos, "</ns1:DSAKeyValue>", 18);
                }
                break;
            case 12:
                // XML: open tag with xmlns declarations
                xml_write(xmlOut, xmlOut_size, &xmlOut_pos, "<ns1:DigestMethod xmlns:ns1=\"http://www.w3.org/2000/09/xmldsig#\" xmlns:ns2=\"urn:iso:std:iso:15118:-20:ACDP\" xmlns:ns3=\"urn:iso:std:iso:15118:-20:CommonTypes\">", 158);
                error = decode_iso20_acdp_DigestMethodType(stream, &exiDoc->DigestMethod, xmlOut, xmlOut_size, &xmlOut_pos);
                exiDoc->DigestMethod_isUsed = 1u;
                // XML: close tag
                if (error == 0)
                {
                    xml_write(xmlOut, xmlOut_size, &xmlOut_pos, "</ns1:DigestMethod>", 19);
                }
                break;
            case 13:
                // simple type! decode_iso20_acdp_DigestValue;
                break;
            case 14:
                // XML: open tag with xmlns declarations
                xml_write(xmlOut, xmlOut_size, &xmlOut_pos, "<ns1:KeyInfo xmlns:ns1=\"http://www.w3.org/2000/09/xmldsig#\" xmlns:ns2=\"urn:iso:std:iso:15118:-20:ACDP\" xmlns:ns3=\"urn:iso:std:iso:15118:-20:CommonTypes\">", 153);
                error = decode_iso20_acdp_KeyInfoType(stream, &exiDoc->KeyInfo, xmlOut, xmlOut_size, &xmlOut_pos);
                exiDoc->KeyInfo_isUsed = 1u;
                // XML: close tag
                if (error == 0)
                {
                    xml_write(xmlOut, xmlOut_size, &xmlOut_pos, "</ns1:KeyInfo>", 14);
                }
                break;
            case 15:
                // simple type! decode_iso20_acdp_KeyName;
                break;
            case 16:
                // XML: open tag with xmlns declarations
                xml_write(xmlOut, xmlOut_size, &xmlOut_pos, "<ns1:KeyValue xmlns:ns1=\"http://www.w3.org/2000/09/xmldsig#\" xmlns:ns2=\"urn:iso:std:iso:15118:-20:ACDP\" xmlns:ns3=\"urn:iso:std:iso:15118:-20:CommonTypes\">", 154);
                error = decode_iso20_acdp_KeyValueType(stream, &exiDoc->KeyValue, xmlOut, xmlOut_size, &xmlOut_pos);
                exiDoc->KeyValue_isUsed = 1u;
                // XML: close tag
                if (error == 0)
                {
                    xml_write(xmlOut, xmlOut_size, &xmlOut_pos, "</ns1:KeyValue>", 15);
                }
                break;
            case 17:
                // XML: open tag with xmlns declarations
                xml_write(xmlOut, xmlOut_size, &xmlOut_pos, "<ns1:Manifest xmlns:ns1=\"http://www.w3.org/2000/09/xmldsig#\" xmlns:ns2=\"urn:iso:std:iso:15118:-20:ACDP\" xmlns:ns3=\"urn:iso:std:iso:15118:-20:CommonTypes\">", 154);
                error = decode_iso20_acdp_ManifestType(stream, &exiDoc->Manifest, xmlOut, xmlOut_size, &xmlOut_pos);
                exiDoc->Manifest_isUsed = 1u;
                // XML: close tag
                if (error == 0)
                {
                    xml_write(xmlOut, xmlOut_size, &xmlOut_pos, "</ns1:Manifest>", 15);
                }
                break;
            case 18:
                // simple type! decode_iso20_acdp_MgmtData;
                break;
            case 19:
                // XML: open tag with xmlns declarations
                xml_write(xmlOut, xmlOut_size, &xmlOut_pos, "<ns1:Object xmlns:ns1=\"http://www.w3.org/2000/09/xmldsig#\" xmlns:ns2=\"urn:iso:std:iso:15118:-20:ACDP\" xmlns:ns3=\"urn:iso:std:iso:15118:-20:CommonTypes\">", 152);
                error = decode_iso20_acdp_ObjectType(stream, &exiDoc->Object, xmlOut, xmlOut_size, &xmlOut_pos);
                exiDoc->Object_isUsed = 1u;
                // XML: close tag
                if (error == 0)
                {
                    xml_write(xmlOut, xmlOut_size, &xmlOut_pos, "</ns1:Object>", 13);
                }
                break;
            case 20:
                // XML: open tag with xmlns declarations
                xml_write(xmlOut, xmlOut_size, &xmlOut_pos, "<ns1:PGPData xmlns:ns1=\"http://www.w3.org/2000/09/xmldsig#\" xmlns:ns2=\"urn:iso:std:iso:15118:-20:ACDP\" xmlns:ns3=\"urn:iso:std:iso:15118:-20:CommonTypes\">", 153);
                error = decode_iso20_acdp_PGPDataType(stream, &exiDoc->PGPData, xmlOut, xmlOut_size, &xmlOut_pos);
                exiDoc->PGPData_isUsed = 1u;
                // XML: close tag
                if (error == 0)
                {
                    xml_write(xmlOut, xmlOut_size, &xmlOut_pos, "</ns1:PGPData>", 14);
                }
                break;
            case 21:
                // XML: open tag with xmlns declarations
                xml_write(xmlOut, xmlOut_size, &xmlOut_pos, "<ns1:RSAKeyValue xmlns:ns1=\"http://www.w3.org/2000/09/xmldsig#\" xmlns:ns2=\"urn:iso:std:iso:15118:-20:ACDP\" xmlns:ns3=\"urn:iso:std:iso:15118:-20:CommonTypes\">", 157);
                error = decode_iso20_acdp_RSAKeyValueType(stream, &exiDoc->RSAKeyValue, xmlOut, xmlOut_size, &xmlOut_pos);
                exiDoc->RSAKeyValue_isUsed = 1u;
                // XML: close tag
                if (error == 0)
                {
                    xml_write(xmlOut, xmlOut_size, &xmlOut_pos, "</ns1:RSAKeyValue>", 18);
                }
                break;
            case 22:
                // XML: open tag with xmlns declarations
                xml_write(xmlOut, xmlOut_size, &xmlOut_pos, "<ns1:Reference xmlns:ns1=\"http://www.w3.org/2000/09/xmldsig#\" xmlns:ns2=\"urn:iso:std:iso:15118:-20:ACDP\" xmlns:ns3=\"urn:iso:std:iso:15118:-20:CommonTypes\">", 155);
                error = decode_iso20_acdp_ReferenceType(stream, &exiDoc->Reference, xmlOut, xmlOut_size, &xmlOut_pos);
                exiDoc->Reference_isUsed = 1u;
                // XML: close tag
                if (error == 0)
                {
                    xml_write(xmlOut, xmlOut_size, &xmlOut_pos, "</ns1:Reference>", 16);
                }
                break;
            case 23:
                // XML: open tag with xmlns declarations
                xml_write(xmlOut, xmlOut_size, &xmlOut_pos, "<ns1:RetrievalMethod xmlns:ns1=\"http://www.w3.org/2000/09/xmldsig#\" xmlns:ns2=\"urn:iso:std:iso:15118:-20:ACDP\" xmlns:ns3=\"urn:iso:std:iso:15118:-20:CommonTypes\">", 161);
                error = decode_iso20_acdp_RetrievalMethodType(stream, &exiDoc->RetrievalMethod, xmlOut, xmlOut_size, &xmlOut_pos);
                exiDoc->RetrievalMethod_isUsed = 1u;
                // XML: close tag
                if (error == 0)
                {
                    xml_write(xmlOut, xmlOut_size, &xmlOut_pos, "</ns1:RetrievalMethod>", 22);
                }
                break;
            case 24:
                // XML: open tag with xmlns declarations
                xml_write(xmlOut, xmlOut_size, &xmlOut_pos, "<ns1:SPKIData xmlns:ns1=\"http://www.w3.org/2000/09/xmldsig#\" xmlns:ns2=\"urn:iso:std:iso:15118:-20:ACDP\" xmlns:ns3=\"urn:iso:std:iso:15118:-20:CommonTypes\">", 154);
                error = decode_iso20_acdp_SPKIDataType(stream, &exiDoc->SPKIData, xmlOut, xmlOut_size, &xmlOut_pos);
                exiDoc->SPKIData_isUsed = 1u;
                // XML: close tag
                if (error == 0)
                {
                    xml_write(xmlOut, xmlOut_size, &xmlOut_pos, "</ns1:SPKIData>", 15);
                }
                break;
            case 25:
                // XML: open tag with xmlns declarations
                xml_write(xmlOut, xmlOut_size, &xmlOut_pos, "<ns1:SignatureMethod xmlns:ns1=\"http://www.w3.org/2000/09/xmldsig#\" xmlns:ns2=\"urn:iso:std:iso:15118:-20:ACDP\" xmlns:ns3=\"urn:iso:std:iso:15118:-20:CommonTypes\">", 161);
                error = decode_iso20_acdp_SignatureMethodType(stream, &exiDoc->SignatureMethod, xmlOut, xmlOut_size, &xmlOut_pos);
                exiDoc->SignatureMethod_isUsed = 1u;
                // XML: close tag
                if (error == 0)
                {
                    xml_write(xmlOut, xmlOut_size, &xmlOut_pos, "</ns1:SignatureMethod>", 22);
                }
                break;
            case 26:
                // XML: open tag with xmlns declarations
                xml_write(xmlOut, xmlOut_size, &xmlOut_pos, "<ns1:SignatureProperties xmlns:ns1=\"http://www.w3.org/2000/09/xmldsig#\" xmlns:ns2=\"urn:iso:std:iso:15118:-20:ACDP\" xmlns:ns3=\"urn:iso:std:iso:15118:-20:CommonTypes\">", 165);
                error = decode_iso20_acdp_SignaturePropertiesType(stream, &exiDoc->SignatureProperties, xmlOut, xmlOut_size, &xmlOut_pos);
                exiDoc->SignatureProperties_isUsed = 1u;
                // XML: close tag
                if (error == 0)
                {
                    xml_write(xmlOut, xmlOut_size, &xmlOut_pos, "</ns1:SignatureProperties>", 26);
                }
                break;
            case 27:
                // XML: open tag with xmlns declarations
                xml_write(xmlOut, xmlOut_size, &xmlOut_pos, "<ns1:SignatureProperty xmlns:ns1=\"http://www.w3.org/2000/09/xmldsig#\" xmlns:ns2=\"urn:iso:std:iso:15118:-20:ACDP\" xmlns:ns3=\"urn:iso:std:iso:15118:-20:CommonTypes\">", 163);
                error = decode_iso20_acdp_SignaturePropertyType(stream, &exiDoc->SignatureProperty, xmlOut, xmlOut_size, &xmlOut_pos);
                exiDoc->SignatureProperty_isUsed = 1u;
                // XML: close tag
                if (error == 0)
                {
                    xml_write(xmlOut, xmlOut_size, &xmlOut_pos, "</ns1:SignatureProperty>", 24);
                }
                break;
            case 28:
                // XML: open tag with xmlns declarations
                xml_write(xmlOut, xmlOut_size, &xmlOut_pos, "<ns1:Signature xmlns:ns1=\"http://www.w3.org/2000/09/xmldsig#\" xmlns:ns2=\"urn:iso:std:iso:15118:-20:ACDP\" xmlns:ns3=\"urn:iso:std:iso:15118:-20:CommonTypes\">", 155);
                error = decode_iso20_acdp_SignatureType(stream, &exiDoc->Signature, xmlOut, xmlOut_size, &xmlOut_pos);
                exiDoc->Signature_isUsed = 1u;
                // XML: close tag
                if (error == 0)
                {
                    xml_write(xmlOut, xmlOut_size, &xmlOut_pos, "</ns1:Signature>", 16);
                }
                break;
            case 29:
                // XML: open tag with xmlns declarations
                xml_write(xmlOut, xmlOut_size, &xmlOut_pos, "<ns1:SignatureValue xmlns:ns1=\"http://www.w3.org/2000/09/xmldsig#\" xmlns:ns2=\"urn:iso:std:iso:15118:-20:ACDP\" xmlns:ns3=\"urn:iso:std:iso:15118:-20:CommonTypes\">", 160);
                error = decode_iso20_acdp_SignatureValueType(stream, &exiDoc->SignatureValue, xmlOut, xmlOut_size, &xmlOut_pos);
                exiDoc->SignatureValue_isUsed = 1u;
                // XML: close tag
                if (error == 0)
                {
                    xml_write(xmlOut, xmlOut_size, &xmlOut_pos, "</ns1:SignatureValue>", 21);
                }
                break;
            case 30:
                // XML: open tag with xmlns declarations
                xml_write(xmlOut, xmlOut_size, &xmlOut_pos, "<ns1:SignedInfo xmlns:ns1=\"http://www.w3.org/2000/09/xmldsig#\" xmlns:ns2=\"urn:iso:std:iso:15118:-20:ACDP\" xmlns:ns3=\"urn:iso:std:iso:15118:-20:CommonTypes\">", 156);
                error = decode_iso20_acdp_SignedInfoType(stream, &exiDoc->SignedInfo, xmlOut, xmlOut_size, &xmlOut_pos);
                exiDoc->SignedInfo_isUsed = 1u;
                // XML: close tag
                if (error == 0)
                {
                    xml_write(xmlOut, xmlOut_size, &xmlOut_pos, "</ns1:SignedInfo>", 17);
                }
                break;
            case 31:
                // XML: open tag with xmlns declarations
                xml_write(xmlOut, xmlOut_size, &xmlOut_pos, "<ns1:Transform xmlns:ns1=\"http://www.w3.org/2000/09/xmldsig#\" xmlns:ns2=\"urn:iso:std:iso:15118:-20:ACDP\" xmlns:ns3=\"urn:iso:std:iso:15118:-20:CommonTypes\">", 155);
                error = decode_iso20_acdp_TransformType(stream, &exiDoc->Transform, xmlOut, xmlOut_size, &xmlOut_pos);
                exiDoc->Transform_isUsed = 1u;
                // XML: close tag
                if (error == 0)
                {
                    xml_write(xmlOut, xmlOut_size, &xmlOut_pos, "</ns1:Transform>", 16);
                }
                break;
            case 32:
                // XML: open tag with xmlns declarations
                xml_write(xmlOut, xmlOut_size, &xmlOut_pos, "<ns1:Transforms xmlns:ns1=\"http://www.w3.org/2000/09/xmldsig#\" xmlns:ns2=\"urn:iso:std:iso:15118:-20:ACDP\" xmlns:ns3=\"urn:iso:std:iso:15118:-20:CommonTypes\">", 156);
                error = decode_iso20_acdp_TransformsType(stream, &exiDoc->Transforms, xmlOut, xmlOut_size, &xmlOut_pos);
                exiDoc->Transforms_isUsed = 1u;
                // XML: close tag
                if (error == 0)
                {
                    xml_write(xmlOut, xmlOut_size, &xmlOut_pos, "</ns1:Transforms>", 17);
                }
                break;
            case 33:
                // XML: open tag with xmlns declarations
                xml_write(xmlOut, xmlOut_size, &xmlOut_pos, "<ns1:X509Data xmlns:ns1=\"http://www.w3.org/2000/09/xmldsig#\" xmlns:ns2=\"urn:iso:std:iso:15118:-20:ACDP\" xmlns:ns3=\"urn:iso:std:iso:15118:-20:CommonTypes\">", 154);
                error = decode_iso20_acdp_X509DataType(stream, &exiDoc->X509Data, xmlOut, xmlOut_size, &xmlOut_pos);
                exiDoc->X509Data_isUsed = 1u;
                // XML: close tag
                if (error == 0)
                {
                    xml_write(xmlOut, xmlOut_size, &xmlOut_pos, "</ns1:X509Data>", 15);
                }
                break;
            default:
                error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                break;
            }
        }
    }

    return error;
}


