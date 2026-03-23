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
  * @file iso20_AC_DER_Datatypes.h
  * @brief Description goes here
  *
  **/

#ifndef ISO20_AC_DER_DATATYPES_H
#define ISO20_AC_DER_DATATYPES_H

#ifdef __cplusplus
extern "C" {
#endif


#include <stdint.h>

#include "exi_basetypes.h"



#define iso20_ac_der_Algorithm_CHARACTER_SIZE (EXI_STRING_MAX_LEN + ASCII_EXTRA_CHAR)
#define iso20_ac_der_CryptoBinary_BYTES_SIZE (EXI_BYTE_ARRAY_MAX_LEN)
#define iso20_ac_der_DataTupleType_10_ARRAY_SIZE (10)
#define iso20_ac_der_DetailedTaxType_10_ARRAY_SIZE (10)
#define iso20_ac_der_DigestValueType_BYTES_SIZE (EXI_BYTE_ARRAY_MAX_LEN)
#define iso20_ac_der_EVInverterHwVersion_CHARACTER_SIZE (32 + ASCII_EXTRA_CHAR)
#define iso20_ac_der_EVInverterManufacturer_CHARACTER_SIZE (32 + ASCII_EXTRA_CHAR)
#define iso20_ac_der_EVInverterModel_CHARACTER_SIZE (32 + ASCII_EXTRA_CHAR)
#define iso20_ac_der_EVInverterSerialNumber_CHARACTER_SIZE (32 + ASCII_EXTRA_CHAR)
#define iso20_ac_der_EVInverterSwVersion_CHARACTER_SIZE (32 + ASCII_EXTRA_CHAR)
#define iso20_ac_der_Encoding_CHARACTER_SIZE (EXI_STRING_MAX_LEN + ASCII_EXTRA_CHAR)
#define iso20_ac_der_ExtraInfo_CHARACTER_SIZE (160 + ASCII_EXTRA_CHAR)
#define iso20_ac_der_Id_CHARACTER_SIZE (EXI_STRING_MAX_LEN + ASCII_EXTRA_CHAR)
#define iso20_ac_der_KeyName_CHARACTER_SIZE (EXI_STRING_MAX_LEN + ASCII_EXTRA_CHAR)
#define iso20_ac_der_MeterID_CHARACTER_SIZE (32 + ASCII_EXTRA_CHAR)
#define iso20_ac_der_MgmtData_CHARACTER_SIZE (EXI_STRING_MAX_LEN + ASCII_EXTRA_CHAR)
#define iso20_ac_der_MimeType_CHARACTER_SIZE (EXI_STRING_MAX_LEN + ASCII_EXTRA_CHAR)
#define iso20_ac_der_ReferenceType_4_ARRAY_SIZE (4)
#define iso20_ac_der_SignatureValueType_BYTES_SIZE (EXI_BYTE_ARRAY_MAX_LEN)
#define iso20_ac_der_Target_CHARACTER_SIZE (EXI_STRING_MAX_LEN + ASCII_EXTRA_CHAR)
#define iso20_ac_der_Type_CHARACTER_SIZE (EXI_STRING_MAX_LEN + ASCII_EXTRA_CHAR)
#define iso20_ac_der_URI_CHARACTER_SIZE (EXI_STRING_MAX_LEN + ASCII_EXTRA_CHAR)
#define iso20_ac_der_X509IssuerName_CHARACTER_SIZE (EXI_STRING_MAX_LEN + ASCII_EXTRA_CHAR)
#define iso20_ac_der_X509SubjectName_CHARACTER_SIZE (EXI_STRING_MAX_LEN + ASCII_EXTRA_CHAR)
#define iso20_ac_der_XPath_CHARACTER_SIZE (EXI_STRING_MAX_LEN + ASCII_EXTRA_CHAR)
#define iso20_ac_der_anyType_BYTES_SIZE (4)
#define iso20_ac_der_base64Binary_BYTES_SIZE (EXI_BYTE_ARRAY_MAX_LEN)
#define iso20_ac_der_meterSignatureType_BYTES_SIZE (64)
#define iso20_ac_der_sessionIDType_BYTES_SIZE (8)


// enum for function numbers
typedef enum {
    iso20_ac_der_AC_CPDReqEnergyTransferMode = 0,
    iso20_ac_der_AC_CPDResEnergyTransferMode = 1,
    iso20_ac_der_AC_ChargeLoopReq = 2,
    iso20_ac_der_AC_ChargeLoopRes = 3,
    iso20_ac_der_AC_ChargeParameterDiscoveryReq = 4,
    iso20_ac_der_AC_ChargeParameterDiscoveryRes = 5,
    iso20_ac_der_BPT_AC_CPDReqEnergyTransferMode = 6,
    iso20_ac_der_BPT_AC_CPDResEnergyTransferMode = 7,
    iso20_ac_der_BPT_Dynamic_AC_CLReqControlMode = 8,
    iso20_ac_der_BPT_Dynamic_AC_CLResControlMode = 9,
    iso20_ac_der_BPT_Scheduled_AC_CLReqControlMode = 10,
    iso20_ac_der_BPT_Scheduled_AC_CLResControlMode = 11,
    iso20_ac_der_CLReqControlMode = 12,
    iso20_ac_der_CLResControlMode = 13,
    iso20_ac_der_CanonicalizationMethod = 14,
    iso20_ac_der_DER_AC_CPDReqEnergyTransferMode = 15,
    iso20_ac_der_DER_AC_CPDResEnergyTransferMode = 16,
    iso20_ac_der_DER_Dynamic_AC_CLReqControlMode = 17,
    iso20_ac_der_DER_Dynamic_AC_CLResControlMode = 18,
    iso20_ac_der_DER_Scheduled_AC_CLReqControlMode = 19,
    iso20_ac_der_DER_Scheduled_AC_CLResControlMode = 20,
    iso20_ac_der_DSAKeyValue = 21,
    iso20_ac_der_DigestMethod = 22,
    iso20_ac_der_DigestValue = 23,
    iso20_ac_der_Dynamic_AC_CLReqControlMode = 24,
    iso20_ac_der_Dynamic_AC_CLResControlMode = 25,
    iso20_ac_der_EU_FrequencyDroop = 26,
    iso20_ac_der_FrequencyDroop = 27,
    iso20_ac_der_KeyInfo = 28,
    iso20_ac_der_KeyName = 29,
    iso20_ac_der_KeyValue = 30,
    iso20_ac_der_Manifest = 31,
    iso20_ac_der_MgmtData = 32,
    iso20_ac_der_Object = 33,
    iso20_ac_der_PGPData = 34,
    iso20_ac_der_RSAKeyValue = 35,
    iso20_ac_der_Reference = 36,
    iso20_ac_der_RetrievalMethod = 37,
    iso20_ac_der_SPKIData = 38,
    iso20_ac_der_Scheduled_AC_CLReqControlMode = 39,
    iso20_ac_der_Scheduled_AC_CLResControlMode = 40,
    iso20_ac_der_Signature = 41,
    iso20_ac_der_SignatureMethod = 42,
    iso20_ac_der_SignatureProperties = 43,
    iso20_ac_der_SignatureProperty = 44,
    iso20_ac_der_SignatureValue = 45,
    iso20_ac_der_SignedInfo = 46,
    iso20_ac_der_Transform = 47,
    iso20_ac_der_Transforms = 48,
    iso20_ac_der_US_FrequencyDroop = 49,
    iso20_ac_der_X509Data = 50
} iso20_ac_der_generatedFunctionNumbersType;

// Element: definition=enum; name={urn:iso:std:iso:15118:-20:AC-DER}LockInValue; type={urn:iso:std:iso:15118:-20:AC-DER}lockValueUnitType; base type=string; content type=simple;
//          abstract=False; final=False; derivation=restriction;
typedef enum {
    iso20_ac_der_lockValueUnitType_V = 0,
    iso20_ac_der_lockValueUnitType_Hz = 1,
    iso20_ac_der_lockValueUnitType_W = 2,
    iso20_ac_der_lockValueUnitType_s = 3,
    iso20_ac_der_lockValueUnitType_var = 4
} iso20_ac_der_lockValueUnitType;

// Element: definition=enum; name={urn:iso:std:iso:15118:-20:AC-DER}PowerFactorExcitation; type={urn:iso:std:iso:15118:-20:AC-DER}powerFactorExcitationType; base type=string; content type=simple;
//          abstract=False; final=False; derivation=restriction;
typedef enum {
    iso20_ac_der_powerFactorExcitationType_OverExcited = 0,
    iso20_ac_der_powerFactorExcitationType_UnderExcited = 1
} iso20_ac_der_powerFactorExcitationType;

// Element: definition=enum; name={urn:iso:std:iso:15118:-20:AC-DER}PowerReference; type={urn:iso:std:iso:15118:-20:AC-DER}powerReferenceType; base type=string; content type=simple;
//          abstract=False; final=False; derivation=restriction;
typedef enum {
    iso20_ac_der_powerReferenceType_MaximumDischargePower = 0,
    iso20_ac_der_powerReferenceType_PresentActivePower = 1
} iso20_ac_der_powerReferenceType;

// Element: definition=enum; name={urn:iso:std:iso:15118:-20:AC-DER}xUnit; type={urn:iso:std:iso:15118:-20:AC-DER}curveDataPointsUnitType; base type=string; content type=simple;
//          abstract=False; final=False; derivation=restriction;
typedef enum {
    iso20_ac_der_curveDataPointsUnitType_V = 0,
    iso20_ac_der_curveDataPointsUnitType_Hz = 1,
    iso20_ac_der_curveDataPointsUnitType_W = 2,
    iso20_ac_der_curveDataPointsUnitType_s = 3,
    iso20_ac_der_curveDataPointsUnitType_var = 4,
    iso20_ac_der_curveDataPointsUnitType_PercentageMaximumConfiguredDischargePower = 5,
    iso20_ac_der_curveDataPointsUnitType_PercentageMaximumConfiguredDischargeReactivePower = 6,
    iso20_ac_der_curveDataPointsUnitType_PercentageMaximumAvailableChargePower = 7,
    iso20_ac_der_curveDataPointsUnitType_PercentageMaximumConfiguredChargeReactivePower = 8,
    iso20_ac_der_curveDataPointsUnitType_PercentageMaximumAvailableDischargePower = 9,
    iso20_ac_der_curveDataPointsUnitType_PercentageMaximumAvailableDischargeReactivePower = 10
} iso20_ac_der_curveDataPointsUnitType;

// Element: definition=enum; name={urn:iso:std:iso:15118:-20:AC-DER}PowerDuringCessation; type={urn:iso:std:iso:15118:-20:AC-DER}powerDuringCessationType; base type=string; content type=simple;
//          abstract=False; final=False; derivation=restriction;
typedef enum {
    iso20_ac_der_powerDuringCessationType_ActivePower = 0,
    iso20_ac_der_powerDuringCessationType_ReactivePower = 1
} iso20_ac_der_powerDuringCessationType;

// Element: definition=enum; name={urn:iso:std:iso:15118:-20:AC-DER}DERFunctionName; type={urn:iso:std:iso:15118:-20:AC-DER}derFunctionNameType; base type=string; content type=simple;
//          abstract=False; final=False; derivation=restriction;
typedef enum {
    iso20_ac_der_derFunctionNameType_EnterService = 0,
    iso20_ac_der_derFunctionNameType_HFTrip = 1,
    iso20_ac_der_derFunctionNameType_LFTrip = 2,
    iso20_ac_der_derFunctionNameType_HVTrip = 3,
    iso20_ac_der_derFunctionNameType_LVTrip = 4,
    iso20_ac_der_derFunctionNameType_FrequencyDroop = 5,
    iso20_ac_der_derFunctionNameType_FrequencyWatt = 6,
    iso20_ac_der_derFunctionNameType_VoltWatt = 7,
    iso20_ac_der_derFunctionNameType_LimitMaxPower = 8,
    iso20_ac_der_derFunctionNameType_ConstantPFInjection = 9,
    iso20_ac_der_derFunctionNameType_ConstantPFAbsorption = 10,
    iso20_ac_der_derFunctionNameType_ConstantVarInjection = 11,
    iso20_ac_der_derFunctionNameType_ConstantVarAbsorption = 12,
    iso20_ac_der_derFunctionNameType_VoltVar = 13,
    iso20_ac_der_derFunctionNameType_WattVar = 14,
    iso20_ac_der_derFunctionNameType_WattCosPhi = 15
} iso20_ac_der_derFunctionNameType;

// Element: definition=enum; name={urn:iso:std:iso:15118:-20:CommonTypes}EVSENotification; type={urn:iso:std:iso:15118:-20:CommonTypes}evseNotificationType; base type=string; content type=simple;
//          abstract=False; final=False; derivation=restriction;
typedef enum {
    iso20_ac_der_evseNotificationType_Pause = 0,
    iso20_ac_der_evseNotificationType_ExitStandby = 1,
    iso20_ac_der_evseNotificationType_Terminate = 2,
    iso20_ac_der_evseNotificationType_ScheduleRenegotiation = 3,
    iso20_ac_der_evseNotificationType_ServiceRenegotiation = 4,
    iso20_ac_der_evseNotificationType_MeteringConfirmation = 5
} iso20_ac_der_evseNotificationType;

// Element: definition=enum; name={urn:iso:std:iso:15118:-20:AC-DER}GridEventFault; type={urn:iso:std:iso:15118:-20:AC-DER}gridEventFaultType; base type=string; content type=simple;
//          abstract=False; final=False; derivation=restriction;
typedef enum {
    iso20_ac_der_gridEventFaultType_OverCurrent = 0,
    iso20_ac_der_gridEventFaultType_OverVoltage = 1,
    iso20_ac_der_gridEventFaultType_UnderVoltage = 2,
    iso20_ac_der_gridEventFaultType_OverFrequency = 3,
    iso20_ac_der_gridEventFaultType_UnderFrequency = 4,
    iso20_ac_der_gridEventFaultType_VoltageImbalance = 5,
    iso20_ac_der_gridEventFaultType_CurrentImbalance = 6,
    iso20_ac_der_gridEventFaultType_EmergencyLocal = 7,
    iso20_ac_der_gridEventFaultType_LowPowerInput = 8,
    iso20_ac_der_gridEventFaultType_PhaseRotation = 9
} iso20_ac_der_gridEventFaultType;

// Element: definition=enum; name={urn:iso:std:iso:15118:-20:CommonTypes}EVProcessing; type={urn:iso:std:iso:15118:-20:CommonTypes}processingType; base type=string; content type=simple;
//          abstract=False; final=False; derivation=restriction;
typedef enum {
    iso20_ac_der_processingType_Finished = 0,
    iso20_ac_der_processingType_Ongoing = 1,
    iso20_ac_der_processingType_Ongoing_WaitingForCustomerInteraction = 2
} iso20_ac_der_processingType;

// Element: definition=enum; name={urn:iso:std:iso:15118:-20:CommonTypes}ResponseCode; type={urn:iso:std:iso:15118:-20:CommonTypes}responseCodeType; base type=string; content type=simple;
//          abstract=False; final=False; derivation=restriction;
typedef enum {
    iso20_ac_der_responseCodeType_OK = 0,
    iso20_ac_der_responseCodeType_OK_CertificateExpiresSoon = 1,
    iso20_ac_der_responseCodeType_OK_NewSessionEstablished = 2,
    iso20_ac_der_responseCodeType_OK_OldSessionJoined = 3,
    iso20_ac_der_responseCodeType_OK_PowerToleranceConfirmed = 4,
    iso20_ac_der_responseCodeType_WARNING_AuthorizationSelectionInvalid = 5,
    iso20_ac_der_responseCodeType_WARNING_CertificateExpired = 6,
    iso20_ac_der_responseCodeType_WARNING_CertificateNotYetValid = 7,
    iso20_ac_der_responseCodeType_WARNING_CertificateRevoked = 8,
    iso20_ac_der_responseCodeType_WARNING_CertificateValidationError = 9,
    iso20_ac_der_responseCodeType_WARNING_ChallengeInvalid = 10,
    iso20_ac_der_responseCodeType_WARNING_EIMAuthorizationFailure = 11,
    iso20_ac_der_responseCodeType_WARNING_eMSPUnknown = 12,
    iso20_ac_der_responseCodeType_WARNING_EVPowerProfileViolation = 13,
    iso20_ac_der_responseCodeType_WARNING_GeneralPnCAuthorizationError = 14,
    iso20_ac_der_responseCodeType_WARNING_NoCertificateAvailable = 15,
    iso20_ac_der_responseCodeType_WARNING_NoContractMatchingPCIDFound = 16,
    iso20_ac_der_responseCodeType_WARNING_PowerToleranceNotConfirmed = 17,
    iso20_ac_der_responseCodeType_WARNING_ScheduleRenegotiationFailed = 18,
    iso20_ac_der_responseCodeType_WARNING_StandbyNotAllowed = 19,
    iso20_ac_der_responseCodeType_WARNING_WPT = 20,
    iso20_ac_der_responseCodeType_FAILED = 21,
    iso20_ac_der_responseCodeType_FAILED_AssociationError = 22,
    iso20_ac_der_responseCodeType_FAILED_ContactorError = 23,
    iso20_ac_der_responseCodeType_FAILED_EVPowerProfileInvalid = 24,
    iso20_ac_der_responseCodeType_FAILED_EVPowerProfileViolation = 25,
    iso20_ac_der_responseCodeType_FAILED_MeteringSignatureNotValid = 26,
    iso20_ac_der_responseCodeType_FAILED_NoEnergyTransferServiceSelected = 27,
    iso20_ac_der_responseCodeType_FAILED_NoServiceRenegotiationSupported = 28,
    iso20_ac_der_responseCodeType_FAILED_PauseNotAllowed = 29,
    iso20_ac_der_responseCodeType_FAILED_PowerDeliveryNotApplied = 30,
    iso20_ac_der_responseCodeType_FAILED_PowerToleranceNotConfirmed = 31,
    iso20_ac_der_responseCodeType_FAILED_ScheduleRenegotiation = 32,
    iso20_ac_der_responseCodeType_FAILED_ScheduleSelectionInvalid = 33,
    iso20_ac_der_responseCodeType_FAILED_SequenceError = 34,
    iso20_ac_der_responseCodeType_FAILED_ServiceIDInvalid = 35,
    iso20_ac_der_responseCodeType_FAILED_ServiceSelectionInvalid = 36,
    iso20_ac_der_responseCodeType_FAILED_SignatureError = 37,
    iso20_ac_der_responseCodeType_FAILED_UnknownSession = 38,
    iso20_ac_der_responseCodeType_FAILED_WrongChargeParameter = 39
} iso20_ac_der_responseCodeType;

// Element: definition=complex; name={http://www.w3.org/2000/09/xmldsig#}Transform; type={http://www.w3.org/2000/09/xmldsig#}TransformType; base type=; content type=mixed;
//          abstract=False; final=False; choice=True;
// Particle: Algorithm, anyURI (1, 1); ANY, anyType (0, 1); XPath, string (0, 1);
struct iso20_ac_der_TransformType {
    // Attribute: Algorithm, anyURI
    struct {
        char characters[iso20_ac_der_Algorithm_CHARACTER_SIZE];
        uint16_t charactersLen;
    } Algorithm;
    // ANY, anyType (base: base64Binary)
    struct {
        uint8_t bytes[iso20_ac_der_anyType_BYTES_SIZE];
        uint16_t bytesLen;
    } ANY;
    unsigned int ANY_isUsed:1;

    // XPath, string
    struct {
        char characters[iso20_ac_der_XPath_CHARACTER_SIZE];
        uint16_t charactersLen;
    } XPath;
    unsigned int XPath_isUsed:1;

};

// Element: definition=complex; name={http://www.w3.org/2000/09/xmldsig#}DSAKeyValue; type={http://www.w3.org/2000/09/xmldsig#}DSAKeyValueType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: P, CryptoBinary (0, 1) (was 1, 1) (seq. ['P', 'Q']); Q, CryptoBinary (0, 1) (was 1, 1) (seq. ['P', 'Q']); G, CryptoBinary (0, 1); Y, CryptoBinary (1, 1); J, CryptoBinary (0, 1); Seed, CryptoBinary (0, 1) (was 1, 1) (seq. ['Seed', 'PgenCounter']); PgenCounter, CryptoBinary (0, 1) (was 1, 1) (seq. ['Seed', 'PgenCounter']);
struct iso20_ac_der_DSAKeyValueType {
    // P, CryptoBinary (base: base64Binary)
    struct {
        uint8_t bytes[iso20_ac_der_CryptoBinary_BYTES_SIZE];
        uint16_t bytesLen;
    } P;
    unsigned int P_isUsed:1;

    // Q, CryptoBinary (base: base64Binary)
    struct {
        uint8_t bytes[iso20_ac_der_CryptoBinary_BYTES_SIZE];
        uint16_t bytesLen;
    } Q;
    unsigned int Q_isUsed:1;

    // G, CryptoBinary (base: base64Binary)
    struct {
        uint8_t bytes[iso20_ac_der_CryptoBinary_BYTES_SIZE];
        uint16_t bytesLen;
    } G;
    unsigned int G_isUsed:1;

    // Y, CryptoBinary (base: base64Binary)
    struct {
        uint8_t bytes[iso20_ac_der_CryptoBinary_BYTES_SIZE];
        uint16_t bytesLen;
    } Y;

    // J, CryptoBinary (base: base64Binary)
    struct {
        uint8_t bytes[iso20_ac_der_CryptoBinary_BYTES_SIZE];
        uint16_t bytesLen;
    } J;
    unsigned int J_isUsed:1;

    // Seed, CryptoBinary (base: base64Binary)
    struct {
        uint8_t bytes[iso20_ac_der_CryptoBinary_BYTES_SIZE];
        uint16_t bytesLen;
    } Seed;
    unsigned int Seed_isUsed:1;

    // PgenCounter, CryptoBinary (base: base64Binary)
    struct {
        uint8_t bytes[iso20_ac_der_CryptoBinary_BYTES_SIZE];
        uint16_t bytesLen;
    } PgenCounter;
    unsigned int PgenCounter_isUsed:1;


};

// Element: definition=complex; name={http://www.w3.org/2000/09/xmldsig#}DigestMethod; type={http://www.w3.org/2000/09/xmldsig#}DigestMethodType; base type=; content type=mixed;
//          abstract=False; final=False;
// Particle: Algorithm, anyURI (1, 1); ANY, anyType (0, 1);
struct iso20_ac_der_DigestMethodType {
    // Attribute: Algorithm, anyURI
    struct {
        char characters[iso20_ac_der_Algorithm_CHARACTER_SIZE];
        uint16_t charactersLen;
    } Algorithm;
    // ANY, anyType (base: base64Binary)
    struct {
        uint8_t bytes[iso20_ac_der_anyType_BYTES_SIZE];
        uint16_t bytesLen;
    } ANY;
    unsigned int ANY_isUsed:1;


};

// Element: definition=complex; name={http://www.w3.org/2000/09/xmldsig#}RSAKeyValue; type={http://www.w3.org/2000/09/xmldsig#}RSAKeyValueType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: Modulus, CryptoBinary (1, 1); Exponent, CryptoBinary (1, 1);
struct iso20_ac_der_RSAKeyValueType {
    // Modulus, CryptoBinary (base: base64Binary)
    struct {
        uint8_t bytes[iso20_ac_der_CryptoBinary_BYTES_SIZE];
        uint16_t bytesLen;
    } Modulus;

    // Exponent, CryptoBinary (base: base64Binary)
    struct {
        uint8_t bytes[iso20_ac_der_CryptoBinary_BYTES_SIZE];
        uint16_t bytesLen;
    } Exponent;


};

// Element: definition=complex; name={http://www.w3.org/2000/09/xmldsig#}Transforms; type={http://www.w3.org/2000/09/xmldsig#}TransformsType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: Transform, TransformType (1, 1) (original max unbounded);
struct iso20_ac_der_TransformsType {
    // Transform, TransformType
    struct iso20_ac_der_TransformType Transform;

};

// Element: definition=complex; name={http://www.w3.org/2000/09/xmldsig#}X509IssuerSerial; type={http://www.w3.org/2000/09/xmldsig#}X509IssuerSerialType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: X509IssuerName, string (1, 1); X509SerialNumber, integer (1, 1);
struct iso20_ac_der_X509IssuerSerialType {
    // X509IssuerName, string
    struct {
        char characters[iso20_ac_der_X509IssuerName_CHARACTER_SIZE];
        uint16_t charactersLen;
    } X509IssuerName;
    // X509SerialNumber, integer (base: decimal)
    exi_signed_t X509SerialNumber;

};

// Element: definition=complex; name={http://www.w3.org/2000/09/xmldsig#}CanonicalizationMethod; type={http://www.w3.org/2000/09/xmldsig#}CanonicalizationMethodType; base type=; content type=mixed;
//          abstract=False; final=False;
// Particle: Algorithm, anyURI (1, 1); ANY, anyType (0, 1);
struct iso20_ac_der_CanonicalizationMethodType {
    // Attribute: Algorithm, anyURI
    struct {
        char characters[iso20_ac_der_Algorithm_CHARACTER_SIZE];
        uint16_t charactersLen;
    } Algorithm;
    // ANY, anyType (base: base64Binary)
    struct {
        uint8_t bytes[iso20_ac_der_anyType_BYTES_SIZE];
        uint16_t bytesLen;
    } ANY;
    unsigned int ANY_isUsed:1;


};

// Element: definition=complex; name={http://www.w3.org/2000/09/xmldsig#}KeyValue; type={http://www.w3.org/2000/09/xmldsig#}KeyValueType; base type=; content type=mixed;
//          abstract=False; final=False; choice=True;
// Particle: DSAKeyValue, DSAKeyValueType (0, 1); RSAKeyValue, RSAKeyValueType (0, 1); ANY, anyType (0, 1);
struct iso20_ac_der_KeyValueType {
    // DSAKeyValue, DSAKeyValueType
    struct iso20_ac_der_DSAKeyValueType DSAKeyValue;
    unsigned int DSAKeyValue_isUsed:1;
    // RSAKeyValue, RSAKeyValueType
    struct iso20_ac_der_RSAKeyValueType RSAKeyValue;
    unsigned int RSAKeyValue_isUsed:1;
    // ANY, anyType (base: base64Binary)
    struct {
        uint8_t bytes[iso20_ac_der_anyType_BYTES_SIZE];
        uint16_t bytesLen;
    } ANY;
    unsigned int ANY_isUsed:1;


};

// Element: definition=complex; name={http://www.w3.org/2000/09/xmldsig#}PGPData; type={http://www.w3.org/2000/09/xmldsig#}PGPDataType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False; choice=True; sequence=True (2;
// Particle: PGPKeyID, base64Binary (1, 1); PGPKeyPacket, base64Binary (0, 1); ANY, anyType (0, 1); PGPKeyPacket, base64Binary (1, 1); ANY, anyType (0, 1);
struct iso20_ac_der_PGPDataType {
    union {
        // sequence of choice 1
        struct {
            // PGPKeyID, base64Binary
            struct {
                uint8_t bytes[iso20_ac_der_base64Binary_BYTES_SIZE];
                uint16_t bytesLen;
            } PGPKeyID;

            // PGPKeyPacket, base64Binary
            struct {
                uint8_t bytes[iso20_ac_der_base64Binary_BYTES_SIZE];
                uint16_t bytesLen;
            } PGPKeyPacket;
            unsigned int PGPKeyPacket_isUsed:1;

            // ANY, anyType (base: base64Binary)
            struct {
                uint8_t bytes[iso20_ac_der_anyType_BYTES_SIZE];
                uint16_t bytesLen;
            } ANY;
            unsigned int ANY_isUsed:1;


        } choice_1;
        unsigned int choice_1_isUsed:1;

        // sequence of choice 2
        struct {
            // PGPKeyPacket, base64Binary
            struct {
                uint8_t bytes[iso20_ac_der_base64Binary_BYTES_SIZE];
                uint16_t bytesLen;
            } PGPKeyPacket;

            // ANY, anyType (base: base64Binary)
            struct {
                uint8_t bytes[iso20_ac_der_anyType_BYTES_SIZE];
                uint16_t bytesLen;
            } ANY;
            unsigned int ANY_isUsed:1;


        } choice_2;
        unsigned int choice_2_isUsed:1;


    };
};

// Element: definition=complex; name={http://www.w3.org/2000/09/xmldsig#}Reference; type={http://www.w3.org/2000/09/xmldsig#}ReferenceType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: Id, ID (0, 1); Type, anyURI (0, 1); URI, anyURI (0, 1); Transforms, TransformsType (0, 1); DigestMethod, DigestMethodType (1, 1); DigestValue, DigestValueType (1, 1);
struct iso20_ac_der_ReferenceType {
    // Attribute: Id, ID (base: NCName)
    struct {
        char characters[iso20_ac_der_Id_CHARACTER_SIZE];
        uint16_t charactersLen;
    } Id;
    unsigned int Id_isUsed:1;
    // Attribute: Type, anyURI
    struct {
        char characters[iso20_ac_der_Type_CHARACTER_SIZE];
        uint16_t charactersLen;
    } Type;
    unsigned int Type_isUsed:1;
    // Attribute: URI, anyURI
    struct {
        char characters[iso20_ac_der_URI_CHARACTER_SIZE];
        uint16_t charactersLen;
    } URI;
    unsigned int URI_isUsed:1;
    // Transforms, TransformsType
    struct iso20_ac_der_TransformsType Transforms;
    unsigned int Transforms_isUsed:1;
    // DigestMethod, DigestMethodType
    struct iso20_ac_der_DigestMethodType DigestMethod;
    // DigestValue, DigestValueType (base: base64Binary)
    struct {
        uint8_t bytes[iso20_ac_der_DigestValueType_BYTES_SIZE];
        uint16_t bytesLen;
    } DigestValue;


};

// Element: definition=complex; name={http://www.w3.org/2000/09/xmldsig#}RetrievalMethod; type={http://www.w3.org/2000/09/xmldsig#}RetrievalMethodType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: Type, anyURI (0, 1); URI, anyURI (0, 1); Transforms, TransformsType (0, 1);
struct iso20_ac_der_RetrievalMethodType {
    // Attribute: Type, anyURI
    struct {
        char characters[iso20_ac_der_Type_CHARACTER_SIZE];
        uint16_t charactersLen;
    } Type;
    unsigned int Type_isUsed:1;
    // Attribute: URI, anyURI
    struct {
        char characters[iso20_ac_der_URI_CHARACTER_SIZE];
        uint16_t charactersLen;
    } URI;
    unsigned int URI_isUsed:1;
    // Transforms, TransformsType
    struct iso20_ac_der_TransformsType Transforms;
    unsigned int Transforms_isUsed:1;

};

// Element: definition=complex; name={http://www.w3.org/2000/09/xmldsig#}SPKIData; type={http://www.w3.org/2000/09/xmldsig#}SPKIDataType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: SPKISexp, base64Binary (1, 1); ANY, anyType (0, 1);
struct iso20_ac_der_SPKIDataType {
    // SPKISexp, base64Binary
    struct {
        uint8_t bytes[iso20_ac_der_base64Binary_BYTES_SIZE];
        uint16_t bytesLen;
    } SPKISexp;

    // ANY, anyType (base: base64Binary)
    struct {
        uint8_t bytes[iso20_ac_der_anyType_BYTES_SIZE];
        uint16_t bytesLen;
    } ANY;
    unsigned int ANY_isUsed:1;


};

// Element: definition=complex; name={http://www.w3.org/2000/09/xmldsig#}SignatureMethod; type={http://www.w3.org/2000/09/xmldsig#}SignatureMethodType; base type=; content type=mixed;
//          abstract=False; final=False;
// Particle: Algorithm, anyURI (1, 1); HMACOutputLength, HMACOutputLengthType (0, 1); ANY, anyType (0, 1);
struct iso20_ac_der_SignatureMethodType {
    // Attribute: Algorithm, anyURI
    struct {
        char characters[iso20_ac_der_Algorithm_CHARACTER_SIZE];
        uint16_t charactersLen;
    } Algorithm;
    // HMACOutputLength, HMACOutputLengthType (base: integer)
    exi_signed_t HMACOutputLength;
    unsigned int HMACOutputLength_isUsed:1;
    // ANY, anyType (base: base64Binary)
    struct {
        uint8_t bytes[iso20_ac_der_anyType_BYTES_SIZE];
        uint16_t bytesLen;
    } ANY;
    unsigned int ANY_isUsed:1;


};

// Element: definition=complex; name={http://www.w3.org/2000/09/xmldsig#}X509Data; type={http://www.w3.org/2000/09/xmldsig#}X509DataType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: X509IssuerSerial, X509IssuerSerialType (0, 1); X509SKI, base64Binary (0, 1); X509SubjectName, string (0, 1); X509Certificate, base64Binary (0, 1); X509CRL, base64Binary (0, 1); ANY, anyType (0, 1);
struct iso20_ac_der_X509DataType {
    // X509IssuerSerial, X509IssuerSerialType
    struct iso20_ac_der_X509IssuerSerialType X509IssuerSerial;
    unsigned int X509IssuerSerial_isUsed:1;
    // X509SKI, base64Binary
    struct {
        uint8_t bytes[iso20_ac_der_base64Binary_BYTES_SIZE];
        uint16_t bytesLen;
    } X509SKI;
    unsigned int X509SKI_isUsed:1;

    // X509SubjectName, string
    struct {
        char characters[iso20_ac_der_X509SubjectName_CHARACTER_SIZE];
        uint16_t charactersLen;
    } X509SubjectName;
    unsigned int X509SubjectName_isUsed:1;
    // X509Certificate, base64Binary
    struct {
        uint8_t bytes[iso20_ac_der_base64Binary_BYTES_SIZE];
        uint16_t bytesLen;
    } X509Certificate;
    unsigned int X509Certificate_isUsed:1;

    // X509CRL, base64Binary
    struct {
        uint8_t bytes[iso20_ac_der_base64Binary_BYTES_SIZE];
        uint16_t bytesLen;
    } X509CRL;
    unsigned int X509CRL_isUsed:1;

    // ANY, anyType (base: base64Binary)
    struct {
        uint8_t bytes[iso20_ac_der_anyType_BYTES_SIZE];
        uint16_t bytesLen;
    } ANY;
    unsigned int ANY_isUsed:1;


};

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:AC-DER}DERGridSupportActiveInfo; type={urn:iso:std:iso:15118:-20:AC-DER}DERGridSupportActiveInfoType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: DERFunctionName, derFunctionNameType (0, 1); GridEventFault, gridEventFaultType (0, 1); ExtraInfo, extraInfoType (0, 1); EventCondition, boolean (1, 1);
struct iso20_ac_der_DERGridSupportActiveInfoType {
    // DERFunctionName, derFunctionNameType (base: string)
    iso20_ac_der_derFunctionNameType DERFunctionName;
    unsigned int DERFunctionName_isUsed:1;
    // GridEventFault, gridEventFaultType (base: string)
    iso20_ac_der_gridEventFaultType GridEventFault;
    unsigned int GridEventFault_isUsed:1;
    // ExtraInfo, extraInfoType (base: string)
    struct {
        char characters[iso20_ac_der_ExtraInfo_CHARACTER_SIZE];
        uint16_t charactersLen;
    } ExtraInfo;
    unsigned int ExtraInfo_isUsed:1;
    // EventCondition, boolean
    int EventCondition;

};

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:AC-DER}EVInverterDetails; type={urn:iso:std:iso:15118:-20:AC-DER}EVInverterDetailsType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: EVInverterSwVersion, evInverterSwVersionType (0, 1); EVInverterHwVersion, evInverterHwVersionType (0, 1); EVInverterManufacturer, evInverterManufacturerType (0, 1); EVInverterModel, evInverterModelType (0, 1); EVInverterSerialNumber, evInverterSerialNumberType (0, 1);
struct iso20_ac_der_EVInverterDetailsType {
    // EVInverterSwVersion, evInverterSwVersionType (base: string)
    struct {
        char characters[iso20_ac_der_EVInverterSwVersion_CHARACTER_SIZE];
        uint16_t charactersLen;
    } EVInverterSwVersion;
    unsigned int EVInverterSwVersion_isUsed:1;
    // EVInverterHwVersion, evInverterHwVersionType (base: string)
    struct {
        char characters[iso20_ac_der_EVInverterHwVersion_CHARACTER_SIZE];
        uint16_t charactersLen;
    } EVInverterHwVersion;
    unsigned int EVInverterHwVersion_isUsed:1;
    // EVInverterManufacturer, evInverterManufacturerType (base: string)
    struct {
        char characters[iso20_ac_der_EVInverterManufacturer_CHARACTER_SIZE];
        uint16_t charactersLen;
    } EVInverterManufacturer;
    unsigned int EVInverterManufacturer_isUsed:1;
    // EVInverterModel, evInverterModelType (base: string)
    struct {
        char characters[iso20_ac_der_EVInverterModel_CHARACTER_SIZE];
        uint16_t charactersLen;
    } EVInverterModel;
    unsigned int EVInverterModel_isUsed:1;
    // EVInverterSerialNumber, evInverterSerialNumberType (base: string)
    struct {
        char characters[iso20_ac_der_EVInverterSerialNumber_CHARACTER_SIZE];
        uint16_t charactersLen;
    } EVInverterSerialNumber;
    unsigned int EVInverterSerialNumber_isUsed:1;

};

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:CommonTypes}EVMaximumChargePower; type={urn:iso:std:iso:15118:-20:CommonTypes}RationalNumberType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: Exponent, byte (1, 1); Value, short (1, 1);
struct iso20_ac_der_RationalNumberType {
    // Exponent, byte (base: short)
    int8_t Exponent;
    // Value, short (base: int)
    int16_t Value;

};

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:AC-DER}CurveDataPoint; type={urn:iso:std:iso:15118:-20:AC-DER}DataTupleType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: x, RationalNumberType (1, 1); y, RationalNumberType (1, 1);
struct iso20_ac_der_DataTupleType {
    // x, RationalNumberType
    struct iso20_ac_der_RationalNumberType x;
    // y, RationalNumberType
    struct iso20_ac_der_RationalNumberType y;

};

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:AC-DER}CurveDataPoints; type={urn:iso:std:iso:15118:-20:AC-DER}CurveDataPointsListType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: CurveDataPoint, DataTupleType (2, 10);
struct iso20_ac_der_CurveDataPointsListType {
    // CurveDataPoint, DataTupleType
    struct {
        struct iso20_ac_der_DataTupleType array[iso20_ac_der_DataTupleType_10_ARRAY_SIZE];
        uint16_t arrayLen;
    } CurveDataPoint;
};

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:AC-DER}HysteresisControl; type={urn:iso:std:iso:15118:-20:AC-DER}HysteresisControlType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: Fstop, RationalNumberType (1, 1); PowerUpRamp, unsignedShort (1, 1); IntentionalDelayFstop, RationalNumberType (0, 1);
struct iso20_ac_der_HysteresisControlType {
    // Fstop, RationalNumberType
    struct iso20_ac_der_RationalNumberType Fstop;
    // PowerUpRamp, unsignedShort (base: unsignedInt)
    uint16_t PowerUpRamp;
    // IntentionalDelayFstop, RationalNumberType
    struct iso20_ac_der_RationalNumberType IntentionalDelayFstop;
    unsigned int IntentionalDelayFstop_isUsed:1;

};

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:AC-DER}ConstantPowerFactor; type={urn:iso:std:iso:15118:-20:AC-DER}ConstantPowerFactorType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: Enable, boolean (0, 1); Priority, unsignedShort (0, 1); PowerFactorValue, RationalNumberType (1, 1); PowerFactorExcitation, powerFactorExcitationType (1, 1);
struct iso20_ac_der_ConstantPowerFactorType {
    // Enable, boolean
    int Enable;
    unsigned int Enable_isUsed:1;
    // Priority, unsignedShort (base: unsignedInt)
    uint16_t Priority;
    unsigned int Priority_isUsed:1;
    // PowerFactorValue, RationalNumberType
    struct iso20_ac_der_RationalNumberType PowerFactorValue;
    // PowerFactorExcitation, powerFactorExcitationType (base: string)
    iso20_ac_der_powerFactorExcitationType PowerFactorExcitation;

};

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:AC-DER}ConstantVar; type={urn:iso:std:iso:15118:-20:AC-DER}ConstantVarType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: Enable, boolean (0, 1); Priority, unsignedShort (0, 1); Setpoint, RationalNumberType (1, 1); Unit, curveDataPointsUnitType (1, 1);
struct iso20_ac_der_ConstantVarType {
    // Enable, boolean
    int Enable;
    unsigned int Enable_isUsed:1;
    // Priority, unsignedShort (base: unsignedInt)
    uint16_t Priority;
    unsigned int Priority_isUsed:1;
    // Setpoint, RationalNumberType
    struct iso20_ac_der_RationalNumberType Setpoint;
    // Unit, curveDataPointsUnitType (base: string)
    iso20_ac_der_curveDataPointsUnitType Unit;

};

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:AC-DER}DeadBand; type={urn:iso:std:iso:15118:-20:AC-DER}DeadBandType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: MidLow, RationalNumberType (1, 1); MidHigh, RationalNumberType (1, 1); Low, RationalNumberType (0, 1); High, RationalNumberType (0, 1);
struct iso20_ac_der_DeadBandType {
    // MidLow, RationalNumberType
    struct iso20_ac_der_RationalNumberType MidLow;
    // MidHigh, RationalNumberType
    struct iso20_ac_der_RationalNumberType MidHigh;
    // Low, RationalNumberType
    struct iso20_ac_der_RationalNumberType Low;
    unsigned int Low_isUsed:1;
    // High, RationalNumberType
    struct iso20_ac_der_RationalNumberType High;
    unsigned int High_isUsed:1;

};

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:AC-DER}FrequencyWatt; type={urn:iso:std:iso:15118:-20:AC-DER}FrequencyWattCurveType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: Enable, boolean (0, 1); Priority, unsignedShort (0, 1); xUnit, curveDataPointsUnitType (1, 1); yUnit, curveDataPointsUnitType (1, 1); CurveDataPoints, CurveDataPointsListType (1, 1); OpenLoopResponseTime, RationalNumberType (0, 1); HysteresisHigh, RationalNumberType (0, 1); HysteresisLow, RationalNumberType (0, 1); HysteresisDelay, RationalNumberType (0, 1); HysteresisGradient, RationalNumberType (0, 1);
struct iso20_ac_der_FrequencyWattCurveType {
    // Enable, boolean
    int Enable;
    unsigned int Enable_isUsed:1;
    // Priority, unsignedShort (base: unsignedInt)
    uint16_t Priority;
    unsigned int Priority_isUsed:1;
    // xUnit, curveDataPointsUnitType (base: string)
    iso20_ac_der_curveDataPointsUnitType xUnit;
    // yUnit, curveDataPointsUnitType (base: string)
    iso20_ac_der_curveDataPointsUnitType yUnit;
    // CurveDataPoints, CurveDataPointsListType
    struct iso20_ac_der_CurveDataPointsListType CurveDataPoints;
    // OpenLoopResponseTime, RationalNumberType
    struct iso20_ac_der_RationalNumberType OpenLoopResponseTime;
    unsigned int OpenLoopResponseTime_isUsed:1;
    // HysteresisHigh, RationalNumberType
    struct iso20_ac_der_RationalNumberType HysteresisHigh;
    unsigned int HysteresisHigh_isUsed:1;
    // HysteresisLow, RationalNumberType
    struct iso20_ac_der_RationalNumberType HysteresisLow;
    unsigned int HysteresisLow_isUsed:1;
    // HysteresisDelay, RationalNumberType
    struct iso20_ac_der_RationalNumberType HysteresisDelay;
    unsigned int HysteresisDelay_isUsed:1;
    // HysteresisGradient, RationalNumberType
    struct iso20_ac_der_RationalNumberType HysteresisGradient;
    unsigned int HysteresisGradient_isUsed:1;

};

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:AC-DER}OverFrequencyDroop; type={urn:iso:std:iso:15118:-20:AC-DER}EU_FrequencyDroopSettingsType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: Fstart, RationalNumberType (1, 1); s, RationalNumberType (1, 1); DeactivationTime, RationalNumberType (0, 1); IntentionalDelayPowerControl, RationalNumberType (0, 1); PowerReference, powerReferenceType (1, 1); HysteresisControl, HysteresisControlType (0, 1); MaxReactionTime, RationalNumberType (0, 1);
struct iso20_ac_der_EU_FrequencyDroopSettingsType {
    // Fstart, RationalNumberType
    struct iso20_ac_der_RationalNumberType Fstart;
    // s, RationalNumberType
    struct iso20_ac_der_RationalNumberType s;
    // DeactivationTime, RationalNumberType
    struct iso20_ac_der_RationalNumberType DeactivationTime;
    unsigned int DeactivationTime_isUsed:1;
    // IntentionalDelayPowerControl, RationalNumberType
    struct iso20_ac_der_RationalNumberType IntentionalDelayPowerControl;
    unsigned int IntentionalDelayPowerControl_isUsed:1;
    // PowerReference, powerReferenceType (base: string)
    iso20_ac_der_powerReferenceType PowerReference;
    // HysteresisControl, HysteresisControlType
    struct iso20_ac_der_HysteresisControlType HysteresisControl;
    unsigned int HysteresisControl_isUsed:1;
    // MaxReactionTime, RationalNumberType
    struct iso20_ac_der_RationalNumberType MaxReactionTime;
    unsigned int MaxReactionTime_isUsed:1;

};

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:AC-DER}OverFrequencyDroop; type={urn:iso:std:iso:15118:-20:AC-DER}US_FrequencyDroopSettingsType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: db, RationalNumberType (1, 1); k, RationalNumberType (1, 1); PowerReference, powerReferenceType (1, 1); OpenLoopResponseTime, RationalNumberType (0, 1);
struct iso20_ac_der_US_FrequencyDroopSettingsType {
    // db, RationalNumberType
    struct iso20_ac_der_RationalNumberType db;
    // k, RationalNumberType
    struct iso20_ac_der_RationalNumberType k;
    // PowerReference, powerReferenceType (base: string)
    iso20_ac_der_powerReferenceType PowerReference;
    // OpenLoopResponseTime, RationalNumberType
    struct iso20_ac_der_RationalNumberType OpenLoopResponseTime;
    unsigned int OpenLoopResponseTime_isUsed:1;

};

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:AC-DER}OverVoltageMustTripCurve; type={urn:iso:std:iso:15118:-20:AC-DER}DERCurveType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: Enable, boolean (0, 1); Priority, unsignedShort (0, 1); xUnit, curveDataPointsUnitType (1, 1); yUnit, curveDataPointsUnitType (1, 1); CurveDataPoints, CurveDataPointsListType (1, 1); LockInValue, lockValueUnitType (0, 1); LockOutValue, lockValueUnitType (0, 1); OpenLoopResponseTime, RationalNumberType (0, 1); TimeConstantPT1, int (0, 1); IntentionalDelay, RationalNumberType (0, 1);
struct iso20_ac_der_DERCurveType {
    // Enable, boolean
    int Enable;
    unsigned int Enable_isUsed:1;
    // Priority, unsignedShort (base: unsignedInt)
    uint16_t Priority;
    unsigned int Priority_isUsed:1;
    // xUnit, curveDataPointsUnitType (base: string)
    iso20_ac_der_curveDataPointsUnitType xUnit;
    // yUnit, curveDataPointsUnitType (base: string)
    iso20_ac_der_curveDataPointsUnitType yUnit;
    // CurveDataPoints, CurveDataPointsListType
    struct iso20_ac_der_CurveDataPointsListType CurveDataPoints;
    // LockInValue, lockValueUnitType (base: string)
    iso20_ac_der_lockValueUnitType LockInValue;
    unsigned int LockInValue_isUsed:1;
    // LockOutValue, lockValueUnitType (base: string)
    iso20_ac_der_lockValueUnitType LockOutValue;
    unsigned int LockOutValue_isUsed:1;
    // OpenLoopResponseTime, RationalNumberType
    struct iso20_ac_der_RationalNumberType OpenLoopResponseTime;
    unsigned int OpenLoopResponseTime_isUsed:1;
    // TimeConstantPT1, int (base: long)
    int32_t TimeConstantPT1;
    unsigned int TimeConstantPT1_isUsed:1;
    // IntentionalDelay, RationalNumberType
    struct iso20_ac_der_RationalNumberType IntentionalDelay;
    unsigned int IntentionalDelay_isUsed:1;

};

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:AC-DER}LimitMaxDischargePower; type={urn:iso:std:iso:15118:-20:AC-DER}LimitMaxDischargePowerType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: Enable, boolean (0, 1); Priority, unsignedShort (0, 1); PercentageValue, unsignedShort (1, 1); PowerMonitoringMustTripCurve, DERCurveType (0, 1);
struct iso20_ac_der_LimitMaxDischargePowerType {
    // Enable, boolean
    int Enable;
    unsigned int Enable_isUsed:1;
    // Priority, unsignedShort (base: unsignedInt)
    uint16_t Priority;
    unsigned int Priority_isUsed:1;
    // PercentageValue, unsignedShort (base: unsignedInt)
    uint16_t PercentageValue;
    // PowerMonitoringMustTripCurve, DERCurveType
    struct iso20_ac_der_DERCurveType PowerMonitoringMustTripCurve;
    unsigned int PowerMonitoringMustTripCurve_isUsed:1;

};

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:AC-DER}EU_FrequencyDroop; type={urn:iso:std:iso:15118:-20:AC-DER}EU_FrequencyDroopType; base type=FrequencyDroopType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: Enable, boolean (0, 1); Priority, unsignedShort (0, 1); OverFrequencyDroop, EU_FrequencyDroopSettingsType (0, 1); UnderFrequencyDroop, EU_FrequencyDroopSettingsType (0, 1);
struct iso20_ac_der_EU_FrequencyDroopType {
    // Enable, boolean
    int Enable;
    unsigned int Enable_isUsed:1;
    // Priority, unsignedShort (base: unsignedInt)
    uint16_t Priority;
    unsigned int Priority_isUsed:1;
    // OverFrequencyDroop, EU_FrequencyDroopSettingsType
    struct iso20_ac_der_EU_FrequencyDroopSettingsType OverFrequencyDroop;
    unsigned int OverFrequencyDroop_isUsed:1;
    // UnderFrequencyDroop, EU_FrequencyDroopSettingsType
    struct iso20_ac_der_EU_FrequencyDroopSettingsType UnderFrequencyDroop;
    unsigned int UnderFrequencyDroop_isUsed:1;

};

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:CommonTypes}EnergyCosts; type={urn:iso:std:iso:15118:-20:CommonTypes}DetailedCostType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: Amount, RationalNumberType (1, 1); CostPerUnit, RationalNumberType (1, 1);
struct iso20_ac_der_DetailedCostType {
    // Amount, RationalNumberType
    struct iso20_ac_der_RationalNumberType Amount;
    // CostPerUnit, RationalNumberType
    struct iso20_ac_der_RationalNumberType CostPerUnit;

};

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:AC-DER}EnterService; type={urn:iso:std:iso:15118:-20:AC-DER}EnterServiceType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: PermitService, boolean (0, 1); EnterServiceVoltageHigh, RationalNumberType (1, 1); EnterServiceVoltageLow, RationalNumberType (1, 1); EnterServiceFrequencyHigh, RationalNumberType (1, 1); EnterServiceFrequencyLow, RationalNumberType (1, 1); EnterServiceDelay, RationalNumberType (1, 1); EnterServiceRandomizedDelay, RationalNumberType (1, 1); EnterServiceRampTime, RationalNumberType (1, 1); EnterServiceGradient, RationalNumberType (0, 1);
struct iso20_ac_der_EnterServiceType {
    // PermitService, boolean
    int PermitService;
    unsigned int PermitService_isUsed:1;
    // EnterServiceVoltageHigh, RationalNumberType
    struct iso20_ac_der_RationalNumberType EnterServiceVoltageHigh;
    // EnterServiceVoltageLow, RationalNumberType
    struct iso20_ac_der_RationalNumberType EnterServiceVoltageLow;
    // EnterServiceFrequencyHigh, RationalNumberType
    struct iso20_ac_der_RationalNumberType EnterServiceFrequencyHigh;
    // EnterServiceFrequencyLow, RationalNumberType
    struct iso20_ac_der_RationalNumberType EnterServiceFrequencyLow;
    // EnterServiceDelay, RationalNumberType
    struct iso20_ac_der_RationalNumberType EnterServiceDelay;
    // EnterServiceRandomizedDelay, RationalNumberType
    struct iso20_ac_der_RationalNumberType EnterServiceRandomizedDelay;
    // EnterServiceRampTime, RationalNumberType
    struct iso20_ac_der_RationalNumberType EnterServiceRampTime;
    // EnterServiceGradient, RationalNumberType
    struct iso20_ac_der_RationalNumberType EnterServiceGradient;
    unsigned int EnterServiceGradient_isUsed:1;

};

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:AC-DER}FaultRideThrough; type={urn:iso:std:iso:15118:-20:AC-DER}FaultRideThroughType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: OverVoltageRideThroughPositiveCurveKFactor, RationalNumberType (0, 1); OverVoltageRideThroughNegativeCurveKFactor, RationalNumberType (0, 1); UnderVoltageRideThroughPositiveCurveKFactor, RationalNumberType (0, 1); UnderVoltageRideThroughNegativeCurveKFactor, RationalNumberType (0, 1); DeadBand, DeadBandType (0, 1);
struct iso20_ac_der_FaultRideThroughType {
    // OverVoltageRideThroughPositiveCurveKFactor, RationalNumberType
    struct iso20_ac_der_RationalNumberType OverVoltageRideThroughPositiveCurveKFactor;
    unsigned int OverVoltageRideThroughPositiveCurveKFactor_isUsed:1;
    // OverVoltageRideThroughNegativeCurveKFactor, RationalNumberType
    struct iso20_ac_der_RationalNumberType OverVoltageRideThroughNegativeCurveKFactor;
    unsigned int OverVoltageRideThroughNegativeCurveKFactor_isUsed:1;
    // UnderVoltageRideThroughPositiveCurveKFactor, RationalNumberType
    struct iso20_ac_der_RationalNumberType UnderVoltageRideThroughPositiveCurveKFactor;
    unsigned int UnderVoltageRideThroughPositiveCurveKFactor_isUsed:1;
    // UnderVoltageRideThroughNegativeCurveKFactor, RationalNumberType
    struct iso20_ac_der_RationalNumberType UnderVoltageRideThroughNegativeCurveKFactor;
    unsigned int UnderVoltageRideThroughNegativeCurveKFactor_isUsed:1;
    // DeadBand, DeadBandType
    struct iso20_ac_der_DeadBandType DeadBand;
    unsigned int DeadBand_isUsed:1;

};

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:AC-DER}FrequencyTrip; type={urn:iso:std:iso:15118:-20:AC-DER}FrequencyTripType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: OverFrequencyMustTripCurve, DERCurveType (1, 1); UnderFrequencyMustTripCurve, DERCurveType (1, 1); OverFrequencyMayTripCurve, DERCurveType (0, 1); UnderFrequencyMayTripCurve, DERCurveType (0, 1);
struct iso20_ac_der_FrequencyTripType {
    // OverFrequencyMustTripCurve, DERCurveType
    struct iso20_ac_der_DERCurveType OverFrequencyMustTripCurve;
    // UnderFrequencyMustTripCurve, DERCurveType
    struct iso20_ac_der_DERCurveType UnderFrequencyMustTripCurve;
    // OverFrequencyMayTripCurve, DERCurveType
    struct iso20_ac_der_DERCurveType OverFrequencyMayTripCurve;
    unsigned int OverFrequencyMayTripCurve_isUsed:1;
    // UnderFrequencyMayTripCurve, DERCurveType
    struct iso20_ac_der_DERCurveType UnderFrequencyMayTripCurve;
    unsigned int UnderFrequencyMayTripCurve_isUsed:1;

};

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:AC-DER}ReactivePowerSupport; type={urn:iso:std:iso:15118:-20:AC-DER}ReactivePowerSupportType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: ConstantPowerFactor, ConstantPowerFactorType (0, 1); VoltVar, DERCurveType (0, 1); WattVar, DERCurveType (0, 1); ConstantVar, ConstantVarType (0, 1); WattCosPhi, DERCurveType (0, 1);
struct iso20_ac_der_ReactivePowerSupportType {
    // ConstantPowerFactor, ConstantPowerFactorType
    struct iso20_ac_der_ConstantPowerFactorType ConstantPowerFactor;
    unsigned int ConstantPowerFactor_isUsed:1;
    // VoltVar, DERCurveType
    struct iso20_ac_der_DERCurveType VoltVar;
    unsigned int VoltVar_isUsed:1;
    // WattVar, DERCurveType
    struct iso20_ac_der_DERCurveType WattVar;
    unsigned int WattVar_isUsed:1;
    // ConstantVar, ConstantVarType
    struct iso20_ac_der_ConstantVarType ConstantVar;
    unsigned int ConstantVar_isUsed:1;
    // WattCosPhi, DERCurveType
    struct iso20_ac_der_DERCurveType WattCosPhi;
    unsigned int WattCosPhi_isUsed:1;

};

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:CommonTypes}TaxCosts; type={urn:iso:std:iso:15118:-20:CommonTypes}DetailedTaxType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: TaxRuleID, numericIDType (1, 1); Amount, RationalNumberType (1, 1);
struct iso20_ac_der_DetailedTaxType {
    // TaxRuleID, numericIDType (base: unsignedInt)
    uint32_t TaxRuleID;
    // Amount, RationalNumberType
    struct iso20_ac_der_RationalNumberType Amount;

};

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:AC-DER}ThreePhase; type={urn:iso:std:iso:15118:-20:AC-DER}ThreePhaseType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: PhaseL1, RationalNumberType (1, 1); PhaseL2, RationalNumberType (1, 1); PhaseL3, RationalNumberType (1, 1);
struct iso20_ac_der_ThreePhaseType {
    // PhaseL1, RationalNumberType
    struct iso20_ac_der_RationalNumberType PhaseL1;
    // PhaseL2, RationalNumberType
    struct iso20_ac_der_RationalNumberType PhaseL2;
    // PhaseL3, RationalNumberType
    struct iso20_ac_der_RationalNumberType PhaseL3;

};

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:AC-DER}US_FrequencyDroop; type={urn:iso:std:iso:15118:-20:AC-DER}US_FrequencyDroopType; base type=FrequencyDroopType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: Enable, boolean (0, 1); Priority, unsignedShort (0, 1); OverFrequencyDroop, US_FrequencyDroopSettingsType (0, 1); UnderFrequencyDroop, US_FrequencyDroopSettingsType (0, 1);
struct iso20_ac_der_US_FrequencyDroopType {
    // Enable, boolean
    int Enable;
    unsigned int Enable_isUsed:1;
    // Priority, unsignedShort (base: unsignedInt)
    uint16_t Priority;
    unsigned int Priority_isUsed:1;
    // OverFrequencyDroop, US_FrequencyDroopSettingsType
    struct iso20_ac_der_US_FrequencyDroopSettingsType OverFrequencyDroop;
    unsigned int OverFrequencyDroop_isUsed:1;
    // UnderFrequencyDroop, US_FrequencyDroopSettingsType
    struct iso20_ac_der_US_FrequencyDroopSettingsType UnderFrequencyDroop;
    unsigned int UnderFrequencyDroop_isUsed:1;

};

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:AC-DER}FrequencyDroop; type={urn:iso:std:iso:15118:-20:AC-DER}FrequencyDroopType; base type=; content type=ELEMENT-ONLY;
//          abstract=True; final=False;
// Particle: Enable, boolean (0, 1); Priority, unsignedShort (0, 1); EU_FrequencyDroop, EU_FrequencyDroopType (0, 1); US_FrequencyDroop, US_FrequencyDroopType (0, 1);
struct iso20_ac_der_FrequencyDroopType {
    // Enable, boolean
    int Enable;
    unsigned int Enable_isUsed:1;
    // Priority, unsignedShort (base: unsignedInt)
    uint16_t Priority;
    unsigned int Priority_isUsed:1;
    union {
        struct iso20_ac_der_EU_FrequencyDroopType EU_FrequencyDroop;
        struct iso20_ac_der_US_FrequencyDroopType US_FrequencyDroop;
    };
    unsigned int EU_FrequencyDroop_isUsed:1;
    unsigned int US_FrequencyDroop_isUsed:1;
};

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:AC-DER}ActivePowerSupport; type={urn:iso:std:iso:15118:-20:AC-DER}ActivePowerSupportType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: FrequencyWatt, FrequencyWattCurveType (0, 1); VoltWatt, DERCurveType (0, 1); LimitMaxDischargePower, LimitMaxDischargePowerType (0, 1); EU_FrequencyDroop, EU_FrequencyDroopType (0, 1); FrequencyDroop, FrequencyDroopType (0, 1); US_FrequencyDroop, US_FrequencyDroopType (0, 1);
struct iso20_ac_der_ActivePowerSupportType {
    // FrequencyWatt, FrequencyWattCurveType
    struct iso20_ac_der_FrequencyWattCurveType FrequencyWatt;
    unsigned int FrequencyWatt_isUsed:1;
    // VoltWatt, DERCurveType
    struct iso20_ac_der_DERCurveType VoltWatt;
    unsigned int VoltWatt_isUsed:1;
    // LimitMaxDischargePower, LimitMaxDischargePowerType
    struct iso20_ac_der_LimitMaxDischargePowerType LimitMaxDischargePower;
    unsigned int LimitMaxDischargePower_isUsed:1;
    // EU_FrequencyDroop, EU_FrequencyDroopType (base: FrequencyDroopType)
    struct iso20_ac_der_EU_FrequencyDroopType EU_FrequencyDroop;
    unsigned int EU_FrequencyDroop_isUsed:1;
    // FrequencyDroop, FrequencyDroopType
    struct iso20_ac_der_FrequencyDroopType FrequencyDroop;
    unsigned int FrequencyDroop_isUsed:1;
    // US_FrequencyDroop, US_FrequencyDroopType (base: FrequencyDroopType)
    struct iso20_ac_der_US_FrequencyDroopType US_FrequencyDroop;
    unsigned int US_FrequencyDroop_isUsed:1;

};

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:AC-DER}VoltageTrip; type={urn:iso:std:iso:15118:-20:AC-DER}VoltageTripType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: OverVoltageMustTripCurve, DERCurveType (1, 1); UnderVoltageMustTripCurve, DERCurveType (1, 1); OverVoltageMomentaryCessationTripCurve, DERCurveType (1, 1); UnderVoltageMomentaryCessationTripCurve, DERCurveType (1, 1); OverVoltageMayTripCurve, DERCurveType (0, 1); UnderVoltageMayTripCurve, DERCurveType (0, 1); OverVoltageMeanValue10min, RationalNumberType (0, 1); OverVoltage10MinMeanTripDelay, RationalNumberType (0, 1); PowerDuringCessation, powerDuringCessationType (0, 1);
struct iso20_ac_der_VoltageTripType {
    // OverVoltageMustTripCurve, DERCurveType
    struct iso20_ac_der_DERCurveType OverVoltageMustTripCurve;
    // UnderVoltageMustTripCurve, DERCurveType
    struct iso20_ac_der_DERCurveType UnderVoltageMustTripCurve;
    // OverVoltageMomentaryCessationTripCurve, DERCurveType
    struct iso20_ac_der_DERCurveType OverVoltageMomentaryCessationTripCurve;
    // UnderVoltageMomentaryCessationTripCurve, DERCurveType
    struct iso20_ac_der_DERCurveType UnderVoltageMomentaryCessationTripCurve;
    // OverVoltageMayTripCurve, DERCurveType
    struct iso20_ac_der_DERCurveType OverVoltageMayTripCurve;
    unsigned int OverVoltageMayTripCurve_isUsed:1;
    // UnderVoltageMayTripCurve, DERCurveType
    struct iso20_ac_der_DERCurveType UnderVoltageMayTripCurve;
    unsigned int UnderVoltageMayTripCurve_isUsed:1;
    // OverVoltageMeanValue10min, RationalNumberType
    struct iso20_ac_der_RationalNumberType OverVoltageMeanValue10min;
    unsigned int OverVoltageMeanValue10min_isUsed:1;
    // OverVoltage10MinMeanTripDelay, RationalNumberType
    struct iso20_ac_der_RationalNumberType OverVoltage10MinMeanTripDelay;
    unsigned int OverVoltage10MinMeanTripDelay_isUsed:1;
    // PowerDuringCessation, powerDuringCessationType (base: string)
    iso20_ac_der_powerDuringCessationType PowerDuringCessation;
    unsigned int PowerDuringCessation_isUsed:1;

};

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:AC-DER}DERControl; type={urn:iso:std:iso:15118:-20:AC-DER}DERControlType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: VoltageTrip, VoltageTripType (0, 1); FrequencyTrip, FrequencyTripType (0, 1); FaultRideThrough, FaultRideThroughType (0, 1); EnterService, EnterServiceType (0, 1); ReactivePowerSupport, ReactivePowerSupportType (0, 1); ActivePowerSupport, ActivePowerSupportType (0, 1); MaximumLevel1DCInjection, RationalNumberType (0, 1); MaximumLevel2DCInjection, RationalNumberType (0, 1); SCRatPOC, RationalNumberType (0, 1);
struct iso20_ac_der_DERControlType {
    // VoltageTrip, VoltageTripType
    struct iso20_ac_der_VoltageTripType VoltageTrip;
    unsigned int VoltageTrip_isUsed:1;
    // FrequencyTrip, FrequencyTripType
    struct iso20_ac_der_FrequencyTripType FrequencyTrip;
    unsigned int FrequencyTrip_isUsed:1;
    // FaultRideThrough, FaultRideThroughType
    struct iso20_ac_der_FaultRideThroughType FaultRideThrough;
    unsigned int FaultRideThrough_isUsed:1;
    // EnterService, EnterServiceType
    struct iso20_ac_der_EnterServiceType EnterService;
    unsigned int EnterService_isUsed:1;
    // ReactivePowerSupport, ReactivePowerSupportType
    struct iso20_ac_der_ReactivePowerSupportType ReactivePowerSupport;
    unsigned int ReactivePowerSupport_isUsed:1;
    // ActivePowerSupport, ActivePowerSupportType
    struct iso20_ac_der_ActivePowerSupportType ActivePowerSupport;
    unsigned int ActivePowerSupport_isUsed:1;
    // MaximumLevel1DCInjection, RationalNumberType
    struct iso20_ac_der_RationalNumberType MaximumLevel1DCInjection;
    unsigned int MaximumLevel1DCInjection_isUsed:1;
    // MaximumLevel2DCInjection, RationalNumberType
    struct iso20_ac_der_RationalNumberType MaximumLevel2DCInjection;
    unsigned int MaximumLevel2DCInjection_isUsed:1;
    // SCRatPOC, RationalNumberType
    struct iso20_ac_der_RationalNumberType SCRatPOC;
    unsigned int SCRatPOC_isUsed:1;

};

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:CommonTypes}DisplayParameters; type={urn:iso:std:iso:15118:-20:CommonTypes}DisplayParametersType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: PresentSOC, percentValueType (0, 1); MinimumSOC, percentValueType (0, 1); TargetSOC, percentValueType (0, 1); MaximumSOC, percentValueType (0, 1); RemainingTimeToMinimumSOC, unsignedInt (0, 1); RemainingTimeToTargetSOC, unsignedInt (0, 1); RemainingTimeToMaximumSOC, unsignedInt (0, 1); ChargingComplete, boolean (0, 1); BatteryEnergyCapacity, RationalNumberType (0, 1); InletHot, boolean (0, 1);
struct iso20_ac_der_DisplayParametersType {
    // PresentSOC, percentValueType (base: byte)
    int8_t PresentSOC;
    unsigned int PresentSOC_isUsed:1;
    // MinimumSOC, percentValueType (base: byte)
    int8_t MinimumSOC;
    unsigned int MinimumSOC_isUsed:1;
    // TargetSOC, percentValueType (base: byte)
    int8_t TargetSOC;
    unsigned int TargetSOC_isUsed:1;
    // MaximumSOC, percentValueType (base: byte)
    int8_t MaximumSOC;
    unsigned int MaximumSOC_isUsed:1;
    // RemainingTimeToMinimumSOC, unsignedInt (base: unsignedLong)
    uint32_t RemainingTimeToMinimumSOC;
    unsigned int RemainingTimeToMinimumSOC_isUsed:1;
    // RemainingTimeToTargetSOC, unsignedInt (base: unsignedLong)
    uint32_t RemainingTimeToTargetSOC;
    unsigned int RemainingTimeToTargetSOC_isUsed:1;
    // RemainingTimeToMaximumSOC, unsignedInt (base: unsignedLong)
    uint32_t RemainingTimeToMaximumSOC;
    unsigned int RemainingTimeToMaximumSOC_isUsed:1;
    // ChargingComplete, boolean
    int ChargingComplete;
    unsigned int ChargingComplete_isUsed:1;
    // BatteryEnergyCapacity, RationalNumberType
    struct iso20_ac_der_RationalNumberType BatteryEnergyCapacity;
    unsigned int BatteryEnergyCapacity_isUsed:1;
    // InletHot, boolean
    int InletHot;
    unsigned int InletHot_isUsed:1;

};

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:AC-DER}EVExcitation; type={urn:iso:std:iso:15118:-20:AC-DER}EVExcitationType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: EVOverExcitedMaximumDischargePower, RationalNumberType (0, 1); EVOverExcitedPowerFactor, RationalNumberType (0, 1); EVUnderExcitedMaximumDischargePower, RationalNumberType (0, 1); EVUnderExcitedPowerFactor, RationalNumberType (0, 1);
struct iso20_ac_der_EVExcitationType {
    // EVOverExcitedMaximumDischargePower, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVOverExcitedMaximumDischargePower;
    unsigned int EVOverExcitedMaximumDischargePower_isUsed:1;
    // EVOverExcitedPowerFactor, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVOverExcitedPowerFactor;
    unsigned int EVOverExcitedPowerFactor_isUsed:1;
    // EVUnderExcitedMaximumDischargePower, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVUnderExcitedMaximumDischargePower;
    unsigned int EVUnderExcitedMaximumDischargePower_isUsed:1;
    // EVUnderExcitedPowerFactor, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVUnderExcitedPowerFactor;
    unsigned int EVUnderExcitedPowerFactor_isUsed:1;

};

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:AC-DER}EVExcitationLimits; type={urn:iso:std:iso:15118:-20:AC-DER}EVExcitationLimitsType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: EVOverExcitedMaximumPowerFactor, RationalNumberType (0, 1); EVOverExcitedMaximumDischargePower, RationalNumberType (0, 1); EVUnderExcitedMaximumPowerFactor, RationalNumberType (0, 1); EVUnderExcitedMaximumDischargePower, RationalNumberType (0, 1);
struct iso20_ac_der_EVExcitationLimitsType {
    // EVOverExcitedMaximumPowerFactor, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVOverExcitedMaximumPowerFactor;
    unsigned int EVOverExcitedMaximumPowerFactor_isUsed:1;
    // EVOverExcitedMaximumDischargePower, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVOverExcitedMaximumDischargePower;
    unsigned int EVOverExcitedMaximumDischargePower_isUsed:1;
    // EVUnderExcitedMaximumPowerFactor, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVUnderExcitedMaximumPowerFactor;
    unsigned int EVUnderExcitedMaximumPowerFactor_isUsed:1;
    // EVUnderExcitedMaximumDischargePower, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVUnderExcitedMaximumDischargePower;
    unsigned int EVUnderExcitedMaximumDischargePower_isUsed:1;

};

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:AC-DER}EVMaximumDischargePower; type={urn:iso:std:iso:15118:-20:AC-DER}PhaseType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False; choice=True;
// Particle: AnyPhase, RationalNumberType (0, 1); ThreePhase, ThreePhaseType (0, 1);
struct iso20_ac_der_PhaseType {
    // AnyPhase, RationalNumberType
    struct iso20_ac_der_RationalNumberType AnyPhase;
    unsigned int AnyPhase_isUsed:1;
    // ThreePhase, ThreePhaseType
    struct iso20_ac_der_ThreePhaseType ThreePhase;
    unsigned int ThreePhase_isUsed:1;

};

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:AC-DER}EVApparentPower; type={urn:iso:std:iso:15118:-20:AC-DER}EVApparentPowerType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: EVMaximumChargeApparentPower, PhaseType (0, 1); EVMaximumDischargeApparentPower, PhaseType (0, 1);
struct iso20_ac_der_EVApparentPowerType {
    // EVMaximumChargeApparentPower, PhaseType
    struct iso20_ac_der_PhaseType EVMaximumChargeApparentPower;
    unsigned int EVMaximumChargeApparentPower_isUsed:1;
    // EVMaximumDischargeApparentPower, PhaseType
    struct iso20_ac_der_PhaseType EVMaximumDischargeApparentPower;
    unsigned int EVMaximumDischargeApparentPower_isUsed:1;

};

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:AC-DER}EVApparentPowerLimits; type={urn:iso:std:iso:15118:-20:AC-DER}EVApparentPowerLimitsType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: EVMaximumChargeApparentPower, PhaseType (0, 1); EVMaximumDischargeApparentPower, PhaseType (0, 1); EVMaximumApparentPower, RationalNumberType (0, 1);
struct iso20_ac_der_EVApparentPowerLimitsType {
    // EVMaximumChargeApparentPower, PhaseType
    struct iso20_ac_der_PhaseType EVMaximumChargeApparentPower;
    unsigned int EVMaximumChargeApparentPower_isUsed:1;
    // EVMaximumDischargeApparentPower, PhaseType
    struct iso20_ac_der_PhaseType EVMaximumDischargeApparentPower;
    unsigned int EVMaximumDischargeApparentPower_isUsed:1;
    // EVMaximumApparentPower, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVMaximumApparentPower;
    unsigned int EVMaximumApparentPower_isUsed:1;

};

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:AC-DER}EVReactivePower; type={urn:iso:std:iso:15118:-20:AC-DER}EVReactivePowerType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: EVMaximumChargeReactivePower, PhaseType (0, 1); EVMinimumChargeReactivePower, PhaseType (0, 1); EVMaximumDischargeReactivePower, PhaseType (0, 1); EVMinimumDischargeReactivePower, PhaseType (0, 1);
struct iso20_ac_der_EVReactivePowerType {
    // EVMaximumChargeReactivePower, PhaseType
    struct iso20_ac_der_PhaseType EVMaximumChargeReactivePower;
    unsigned int EVMaximumChargeReactivePower_isUsed:1;
    // EVMinimumChargeReactivePower, PhaseType
    struct iso20_ac_der_PhaseType EVMinimumChargeReactivePower;
    unsigned int EVMinimumChargeReactivePower_isUsed:1;
    // EVMaximumDischargeReactivePower, PhaseType
    struct iso20_ac_der_PhaseType EVMaximumDischargeReactivePower;
    unsigned int EVMaximumDischargeReactivePower_isUsed:1;
    // EVMinimumDischargeReactivePower, PhaseType
    struct iso20_ac_der_PhaseType EVMinimumDischargeReactivePower;
    unsigned int EVMinimumDischargeReactivePower_isUsed:1;

};

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:AC-DER}EVReactivePowerLimits; type={urn:iso:std:iso:15118:-20:AC-DER}EVReactivePowerLimitsType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: EVMaximumChargeReactivePower, RationalNumberType (0, 1); EVMinimumChargeReactivePower, RationalNumberType (0, 1); EVMaximumDischargeReactivePower, RationalNumberType (0, 1); EVMinimumDischargeReactivePower, RationalNumberType (0, 1); EVReactiveSusceptance, RationalNumberType (0, 1);
struct iso20_ac_der_EVReactivePowerLimitsType {
    // EVMaximumChargeReactivePower, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVMaximumChargeReactivePower;
    unsigned int EVMaximumChargeReactivePower_isUsed:1;
    // EVMinimumChargeReactivePower, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVMinimumChargeReactivePower;
    unsigned int EVMinimumChargeReactivePower_isUsed:1;
    // EVMaximumDischargeReactivePower, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVMaximumDischargeReactivePower;
    unsigned int EVMaximumDischargeReactivePower_isUsed:1;
    // EVMinimumDischargeReactivePower, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVMinimumDischargeReactivePower;
    unsigned int EVMinimumDischargeReactivePower_isUsed:1;
    // EVReactiveSusceptance, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVReactiveSusceptance;
    unsigned int EVReactiveSusceptance_isUsed:1;

};

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:CommonTypes}EVSEStatus; type={urn:iso:std:iso:15118:-20:CommonTypes}EVSEStatusType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: NotificationMaxDelay, unsignedShort (1, 1); EVSENotification, evseNotificationType (1, 1);
struct iso20_ac_der_EVSEStatusType {
    // NotificationMaxDelay, unsignedShort (base: unsignedInt)
    uint16_t NotificationMaxDelay;
    // EVSENotification, evseNotificationType (base: string)
    iso20_ac_der_evseNotificationType EVSENotification;

};

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:AC-DER}EVSetPoints; type={urn:iso:std:iso:15118:-20:AC-DER}EVSetPointsType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: EVSetNominalVoltage, RationalNumberType (0, 1); EVSetNominalVoltageOffset, RationalNumberType (0, 1); EVSetMaximumNominalVoltage, RationalNumberType (0, 1); EVSetMinimumNominalVoltage, RationalNumberType (0, 1);
struct iso20_ac_der_EVSetPointsType {
    // EVSetNominalVoltage, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVSetNominalVoltage;
    unsigned int EVSetNominalVoltage_isUsed:1;
    // EVSetNominalVoltageOffset, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVSetNominalVoltageOffset;
    unsigned int EVSetNominalVoltageOffset_isUsed:1;
    // EVSetMaximumNominalVoltage, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVSetMaximumNominalVoltage;
    unsigned int EVSetMaximumNominalVoltage_isUsed:1;
    // EVSetMinimumNominalVoltage, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVSetMinimumNominalVoltage;
    unsigned int EVSetMinimumNominalVoltage_isUsed:1;

};

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:AC-DER}GridLimits; type={urn:iso:std:iso:15118:-20:AC-DER}GridLimitsType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: GridNominalFrequency, RationalNumberType (1, 1); GridNominalVoltage, RationalNumberType (1, 1); GridNominalVoltageOffset, RationalNumberType (0, 1); GridMinFrequency, RationalNumberType (0, 1); GridMaxFrequency, RationalNumberType (0, 1); GridMaximumVoltage, RationalNumberType (0, 1); GridMinimumVoltage, RationalNumberType (0, 1);
struct iso20_ac_der_GridLimitsType {
    // GridNominalFrequency, RationalNumberType
    struct iso20_ac_der_RationalNumberType GridNominalFrequency;
    // GridNominalVoltage, RationalNumberType
    struct iso20_ac_der_RationalNumberType GridNominalVoltage;
    // GridNominalVoltageOffset, RationalNumberType
    struct iso20_ac_der_RationalNumberType GridNominalVoltageOffset;
    unsigned int GridNominalVoltageOffset_isUsed:1;
    // GridMinFrequency, RationalNumberType
    struct iso20_ac_der_RationalNumberType GridMinFrequency;
    unsigned int GridMinFrequency_isUsed:1;
    // GridMaxFrequency, RationalNumberType
    struct iso20_ac_der_RationalNumberType GridMaxFrequency;
    unsigned int GridMaxFrequency_isUsed:1;
    // GridMaximumVoltage, RationalNumberType
    struct iso20_ac_der_RationalNumberType GridMaximumVoltage;
    unsigned int GridMaximumVoltage_isUsed:1;
    // GridMinimumVoltage, RationalNumberType
    struct iso20_ac_der_RationalNumberType GridMinimumVoltage;
    unsigned int GridMinimumVoltage_isUsed:1;

};

// Element: definition=complex; name={http://www.w3.org/2000/09/xmldsig#}KeyInfo; type={http://www.w3.org/2000/09/xmldsig#}KeyInfoType; base type=; content type=mixed;
//          abstract=False; final=False; choice=True;
// Particle: Id, ID (0, 1); KeyName, string (0, 1); KeyValue, KeyValueType (0, 1); RetrievalMethod, RetrievalMethodType (0, 1); X509Data, X509DataType (0, 1); PGPData, PGPDataType (0, 1); SPKIData, SPKIDataType (0, 1); MgmtData, string (0, 1); ANY, anyType (0, 1);
struct iso20_ac_der_KeyInfoType {
    // Attribute: Id, ID (base: NCName)
    struct {
        char characters[iso20_ac_der_Id_CHARACTER_SIZE];
        uint16_t charactersLen;
    } Id;
    unsigned int Id_isUsed:1;
    // KeyName, string
    struct {
        char characters[iso20_ac_der_KeyName_CHARACTER_SIZE];
        uint16_t charactersLen;
    } KeyName;
    unsigned int KeyName_isUsed:1;
    // KeyValue, KeyValueType
    struct iso20_ac_der_KeyValueType KeyValue;
    unsigned int KeyValue_isUsed:1;
    // RetrievalMethod, RetrievalMethodType
    struct iso20_ac_der_RetrievalMethodType RetrievalMethod;
    unsigned int RetrievalMethod_isUsed:1;
    // X509Data, X509DataType
    struct iso20_ac_der_X509DataType X509Data;
    unsigned int X509Data_isUsed:1;
    // PGPData, PGPDataType
    struct iso20_ac_der_PGPDataType PGPData;
    unsigned int PGPData_isUsed:1;
    // SPKIData, SPKIDataType
    struct iso20_ac_der_SPKIDataType SPKIData;
    unsigned int SPKIData_isUsed:1;
    // MgmtData, string
    struct {
        char characters[iso20_ac_der_MgmtData_CHARACTER_SIZE];
        uint16_t charactersLen;
    } MgmtData;
    unsigned int MgmtData_isUsed:1;
    // ANY, anyType (base: base64Binary)
    struct {
        uint8_t bytes[iso20_ac_der_anyType_BYTES_SIZE];
        uint16_t bytesLen;
    } ANY;
    unsigned int ANY_isUsed:1;


};

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:CommonTypes}MeterInfo; type={urn:iso:std:iso:15118:-20:CommonTypes}MeterInfoType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: MeterID, meterIDType (1, 1); ChargedEnergyReadingWh, unsignedLong (1, 1); BPT_DischargedEnergyReadingWh, unsignedLong (0, 1); CapacitiveEnergyReadingVARh, unsignedLong (0, 1); BPT_InductiveEnergyReadingVARh, unsignedLong (0, 1); MeterSignature, meterSignatureType (0, 1); MeterStatus, short (0, 1); MeterTimestamp, unsignedLong (0, 1);
struct iso20_ac_der_MeterInfoType {
    // MeterID, meterIDType (base: string)
    struct {
        char characters[iso20_ac_der_MeterID_CHARACTER_SIZE];
        uint16_t charactersLen;
    } MeterID;
    // ChargedEnergyReadingWh, unsignedLong (base: nonNegativeInteger)
    uint64_t ChargedEnergyReadingWh;
    // BPT_DischargedEnergyReadingWh, unsignedLong (base: nonNegativeInteger)
    uint64_t BPT_DischargedEnergyReadingWh;
    unsigned int BPT_DischargedEnergyReadingWh_isUsed:1;
    // CapacitiveEnergyReadingVARh, unsignedLong (base: nonNegativeInteger)
    uint64_t CapacitiveEnergyReadingVARh;
    unsigned int CapacitiveEnergyReadingVARh_isUsed:1;
    // BPT_InductiveEnergyReadingVARh, unsignedLong (base: nonNegativeInteger)
    uint64_t BPT_InductiveEnergyReadingVARh;
    unsigned int BPT_InductiveEnergyReadingVARh_isUsed:1;
    // MeterSignature, meterSignatureType (base: base64Binary)
    struct {
        uint8_t bytes[iso20_ac_der_meterSignatureType_BYTES_SIZE];
        uint16_t bytesLen;
    } MeterSignature;
    unsigned int MeterSignature_isUsed:1;

    // MeterStatus, short (base: int)
    int16_t MeterStatus;
    unsigned int MeterStatus_isUsed:1;
    // MeterTimestamp, unsignedLong (base: nonNegativeInteger)
    uint64_t MeterTimestamp;
    unsigned int MeterTimestamp_isUsed:1;

};

// Element: definition=complex; name={http://www.w3.org/2000/09/xmldsig#}Object; type={http://www.w3.org/2000/09/xmldsig#}ObjectType; base type=; content type=mixed;
//          abstract=False; final=False;
// Particle: Encoding, anyURI (0, 1); Id, ID (0, 1); MimeType, string (0, 1); ANY, anyType (0, 1) (old 1, 1);
struct iso20_ac_der_ObjectType {
    // Attribute: Encoding, anyURI
    struct {
        char characters[iso20_ac_der_Encoding_CHARACTER_SIZE];
        uint16_t charactersLen;
    } Encoding;
    unsigned int Encoding_isUsed:1;
    // Attribute: Id, ID (base: NCName)
    struct {
        char characters[iso20_ac_der_Id_CHARACTER_SIZE];
        uint16_t charactersLen;
    } Id;
    unsigned int Id_isUsed:1;
    // Attribute: MimeType, string
    struct {
        char characters[iso20_ac_der_MimeType_CHARACTER_SIZE];
        uint16_t charactersLen;
    } MimeType;
    unsigned int MimeType_isUsed:1;
    // ANY, anyType (base: base64Binary)
    struct {
        uint8_t bytes[iso20_ac_der_anyType_BYTES_SIZE];
        uint16_t bytesLen;
    } ANY;
    unsigned int ANY_isUsed:1;


};

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:CommonTypes}Receipt; type={urn:iso:std:iso:15118:-20:CommonTypes}ReceiptType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: TimeAnchor, unsignedLong (1, 1); EnergyCosts, DetailedCostType (0, 1); OccupancyCosts, DetailedCostType (0, 1); AdditionalServicesCosts, DetailedCostType (0, 1); OverstayCosts, DetailedCostType (0, 1); TaxCosts, DetailedTaxType (0, 10);
struct iso20_ac_der_ReceiptType {
    // TimeAnchor, unsignedLong (base: nonNegativeInteger)
    uint64_t TimeAnchor;
    // EnergyCosts, DetailedCostType
    struct iso20_ac_der_DetailedCostType EnergyCosts;
    unsigned int EnergyCosts_isUsed:1;
    // OccupancyCosts, DetailedCostType
    struct iso20_ac_der_DetailedCostType OccupancyCosts;
    unsigned int OccupancyCosts_isUsed:1;
    // AdditionalServicesCosts, DetailedCostType
    struct iso20_ac_der_DetailedCostType AdditionalServicesCosts;
    unsigned int AdditionalServicesCosts_isUsed:1;
    // OverstayCosts, DetailedCostType
    struct iso20_ac_der_DetailedCostType OverstayCosts;
    unsigned int OverstayCosts_isUsed:1;
    // TaxCosts, DetailedTaxType
    struct {
        struct iso20_ac_der_DetailedTaxType array[iso20_ac_der_DetailedTaxType_10_ARRAY_SIZE];
        uint16_t arrayLen;
    } TaxCosts;
};

// Element: definition=complex; name={http://www.w3.org/2000/09/xmldsig#}SignatureProperty; type={http://www.w3.org/2000/09/xmldsig#}SignaturePropertyType; base type=; content type=mixed;
//          abstract=False; final=False; choice=True;
// Particle: Id, ID (0, 1); Target, anyURI (1, 1); ANY, anyType (0, 1);
struct iso20_ac_der_SignaturePropertyType {
    // Attribute: Id, ID (base: NCName)
    struct {
        char characters[iso20_ac_der_Id_CHARACTER_SIZE];
        uint16_t charactersLen;
    } Id;
    unsigned int Id_isUsed:1;
    // Attribute: Target, anyURI
    struct {
        char characters[iso20_ac_der_Target_CHARACTER_SIZE];
        uint16_t charactersLen;
    } Target;
    // ANY, anyType (base: base64Binary)
    struct {
        uint8_t bytes[iso20_ac_der_anyType_BYTES_SIZE];
        uint16_t bytesLen;
    } ANY;
    unsigned int ANY_isUsed:1;


};

// Element: definition=complex; name={http://www.w3.org/2000/09/xmldsig#}SignatureValue; type={http://www.w3.org/2000/09/xmldsig#}SignatureValueType; base type=base64Binary; content type=simple;
//          abstract=False; final=False; derivation=extension;
// Particle: Id, ID (0, 1); CONTENT, SignatureValueType (1, 1);
struct iso20_ac_der_SignatureValueType {
    // Attribute: Id, ID (base: NCName)
    struct {
        char characters[iso20_ac_der_Id_CHARACTER_SIZE];
        uint16_t charactersLen;
    } Id;
    unsigned int Id_isUsed:1;
    // CONTENT, SignatureValueType (base: base64Binary)
    struct {
        uint8_t bytes[iso20_ac_der_SignatureValueType_BYTES_SIZE];
        uint16_t bytesLen;
    } CONTENT;


};

// Element: definition=complex; name={http://www.w3.org/2000/09/xmldsig#}SignedInfo; type={http://www.w3.org/2000/09/xmldsig#}SignedInfoType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: Id, ID (0, 1); CanonicalizationMethod, CanonicalizationMethodType (1, 1); SignatureMethod, SignatureMethodType (1, 1); Reference, ReferenceType (1, 4) (original max unbounded);
struct iso20_ac_der_SignedInfoType {
    // Attribute: Id, ID (base: NCName)
    struct {
        char characters[iso20_ac_der_Id_CHARACTER_SIZE];
        uint16_t charactersLen;
    } Id;
    unsigned int Id_isUsed:1;
    // CanonicalizationMethod, CanonicalizationMethodType
    struct iso20_ac_der_CanonicalizationMethodType CanonicalizationMethod;
    // SignatureMethod, SignatureMethodType
    struct iso20_ac_der_SignatureMethodType SignatureMethod;
    // Reference, ReferenceType
    struct {
        struct iso20_ac_der_ReferenceType array[iso20_ac_der_ReferenceType_4_ARRAY_SIZE];
        uint16_t arrayLen;
    } Reference;
};

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:AC}AC_CPDReqEnergyTransferMode; type={urn:iso:std:iso:15118:-20:AC}AC_CPDReqEnergyTransferModeType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: EVMaximumChargePower, RationalNumberType (1, 1); EVMaximumChargePower_L2, RationalNumberType (0, 1); EVMaximumChargePower_L3, RationalNumberType (0, 1); EVMinimumChargePower, RationalNumberType (1, 1); EVMinimumChargePower_L2, RationalNumberType (0, 1); EVMinimumChargePower_L3, RationalNumberType (0, 1);
struct iso20_ac_der_AC_CPDReqEnergyTransferModeType {
    // EVMaximumChargePower, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVMaximumChargePower;
    // EVMaximumChargePower_L2, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVMaximumChargePower_L2;
    unsigned int EVMaximumChargePower_L2_isUsed:1;
    // EVMaximumChargePower_L3, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVMaximumChargePower_L3;
    unsigned int EVMaximumChargePower_L3_isUsed:1;
    // EVMinimumChargePower, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVMinimumChargePower;
    // EVMinimumChargePower_L2, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVMinimumChargePower_L2;
    unsigned int EVMinimumChargePower_L2_isUsed:1;
    // EVMinimumChargePower_L3, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVMinimumChargePower_L3;
    unsigned int EVMinimumChargePower_L3_isUsed:1;

};

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:AC}AC_CPDResEnergyTransferMode; type={urn:iso:std:iso:15118:-20:AC}AC_CPDResEnergyTransferModeType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: EVSEMaximumChargePower, RationalNumberType (1, 1); EVSEMaximumChargePower_L2, RationalNumberType (0, 1); EVSEMaximumChargePower_L3, RationalNumberType (0, 1); EVSEMinimumChargePower, RationalNumberType (1, 1); EVSEMinimumChargePower_L2, RationalNumberType (0, 1); EVSEMinimumChargePower_L3, RationalNumberType (0, 1); EVSENominalFrequency, RationalNumberType (1, 1); MaximumPowerAsymmetry, RationalNumberType (0, 1); EVSEPowerRampLimitation, RationalNumberType (0, 1); EVSEPresentActivePower, RationalNumberType (0, 1); EVSEPresentActivePower_L2, RationalNumberType (0, 1); EVSEPresentActivePower_L3, RationalNumberType (0, 1);
struct iso20_ac_der_AC_CPDResEnergyTransferModeType {
    // EVSEMaximumChargePower, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVSEMaximumChargePower;
    // EVSEMaximumChargePower_L2, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVSEMaximumChargePower_L2;
    unsigned int EVSEMaximumChargePower_L2_isUsed:1;
    // EVSEMaximumChargePower_L3, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVSEMaximumChargePower_L3;
    unsigned int EVSEMaximumChargePower_L3_isUsed:1;
    // EVSEMinimumChargePower, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVSEMinimumChargePower;
    // EVSEMinimumChargePower_L2, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVSEMinimumChargePower_L2;
    unsigned int EVSEMinimumChargePower_L2_isUsed:1;
    // EVSEMinimumChargePower_L3, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVSEMinimumChargePower_L3;
    unsigned int EVSEMinimumChargePower_L3_isUsed:1;
    // EVSENominalFrequency, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVSENominalFrequency;
    // MaximumPowerAsymmetry, RationalNumberType
    struct iso20_ac_der_RationalNumberType MaximumPowerAsymmetry;
    unsigned int MaximumPowerAsymmetry_isUsed:1;
    // EVSEPowerRampLimitation, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVSEPowerRampLimitation;
    unsigned int EVSEPowerRampLimitation_isUsed:1;
    // EVSEPresentActivePower, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVSEPresentActivePower;
    unsigned int EVSEPresentActivePower_isUsed:1;
    // EVSEPresentActivePower_L2, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVSEPresentActivePower_L2;
    unsigned int EVSEPresentActivePower_L2_isUsed:1;
    // EVSEPresentActivePower_L3, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVSEPresentActivePower_L3;
    unsigned int EVSEPresentActivePower_L3_isUsed:1;

};

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:AC}BPT_AC_CPDReqEnergyTransferMode; type={urn:iso:std:iso:15118:-20:AC}BPT_AC_CPDReqEnergyTransferModeType; base type=AC_CPDReqEnergyTransferModeType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: EVMaximumChargePower, RationalNumberType (1, 1); EVMaximumChargePower_L2, RationalNumberType (0, 1); EVMaximumChargePower_L3, RationalNumberType (0, 1); EVMinimumChargePower, RationalNumberType (1, 1); EVMinimumChargePower_L2, RationalNumberType (0, 1); EVMinimumChargePower_L3, RationalNumberType (0, 1); EVMaximumDischargePower, RationalNumberType (1, 1); EVMaximumDischargePower_L2, RationalNumberType (0, 1); EVMaximumDischargePower_L3, RationalNumberType (0, 1); EVMinimumDischargePower, RationalNumberType (1, 1); EVMinimumDischargePower_L2, RationalNumberType (0, 1); EVMinimumDischargePower_L3, RationalNumberType (0, 1);
struct iso20_ac_der_BPT_AC_CPDReqEnergyTransferModeType {
    // EVMaximumChargePower, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVMaximumChargePower;
    // EVMaximumChargePower_L2, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVMaximumChargePower_L2;
    unsigned int EVMaximumChargePower_L2_isUsed:1;
    // EVMaximumChargePower_L3, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVMaximumChargePower_L3;
    unsigned int EVMaximumChargePower_L3_isUsed:1;
    // EVMinimumChargePower, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVMinimumChargePower;
    // EVMinimumChargePower_L2, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVMinimumChargePower_L2;
    unsigned int EVMinimumChargePower_L2_isUsed:1;
    // EVMinimumChargePower_L3, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVMinimumChargePower_L3;
    unsigned int EVMinimumChargePower_L3_isUsed:1;
    // EVMaximumDischargePower, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVMaximumDischargePower;
    // EVMaximumDischargePower_L2, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVMaximumDischargePower_L2;
    unsigned int EVMaximumDischargePower_L2_isUsed:1;
    // EVMaximumDischargePower_L3, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVMaximumDischargePower_L3;
    unsigned int EVMaximumDischargePower_L3_isUsed:1;
    // EVMinimumDischargePower, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVMinimumDischargePower;
    // EVMinimumDischargePower_L2, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVMinimumDischargePower_L2;
    unsigned int EVMinimumDischargePower_L2_isUsed:1;
    // EVMinimumDischargePower_L3, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVMinimumDischargePower_L3;
    unsigned int EVMinimumDischargePower_L3_isUsed:1;

};

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:AC}BPT_AC_CPDResEnergyTransferMode; type={urn:iso:std:iso:15118:-20:AC}BPT_AC_CPDResEnergyTransferModeType; base type=AC_CPDResEnergyTransferModeType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: EVSEMaximumChargePower, RationalNumberType (1, 1); EVSEMaximumChargePower_L2, RationalNumberType (0, 1); EVSEMaximumChargePower_L3, RationalNumberType (0, 1); EVSEMinimumChargePower, RationalNumberType (1, 1); EVSEMinimumChargePower_L2, RationalNumberType (0, 1); EVSEMinimumChargePower_L3, RationalNumberType (0, 1); EVSENominalFrequency, RationalNumberType (1, 1); MaximumPowerAsymmetry, RationalNumberType (0, 1); EVSEPowerRampLimitation, RationalNumberType (0, 1); EVSEPresentActivePower, RationalNumberType (0, 1); EVSEPresentActivePower_L2, RationalNumberType (0, 1); EVSEPresentActivePower_L3, RationalNumberType (0, 1); EVSEMaximumDischargePower, RationalNumberType (1, 1); EVSEMaximumDischargePower_L2, RationalNumberType (0, 1); EVSEMaximumDischargePower_L3, RationalNumberType (0, 1); EVSEMinimumDischargePower, RationalNumberType (1, 1); EVSEMinimumDischargePower_L2, RationalNumberType (0, 1); EVSEMinimumDischargePower_L3, RationalNumberType (0, 1);
struct iso20_ac_der_BPT_AC_CPDResEnergyTransferModeType {
    // EVSEMaximumChargePower, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVSEMaximumChargePower;
    // EVSEMaximumChargePower_L2, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVSEMaximumChargePower_L2;
    unsigned int EVSEMaximumChargePower_L2_isUsed:1;
    // EVSEMaximumChargePower_L3, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVSEMaximumChargePower_L3;
    unsigned int EVSEMaximumChargePower_L3_isUsed:1;
    // EVSEMinimumChargePower, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVSEMinimumChargePower;
    // EVSEMinimumChargePower_L2, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVSEMinimumChargePower_L2;
    unsigned int EVSEMinimumChargePower_L2_isUsed:1;
    // EVSEMinimumChargePower_L3, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVSEMinimumChargePower_L3;
    unsigned int EVSEMinimumChargePower_L3_isUsed:1;
    // EVSENominalFrequency, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVSENominalFrequency;
    // MaximumPowerAsymmetry, RationalNumberType
    struct iso20_ac_der_RationalNumberType MaximumPowerAsymmetry;
    unsigned int MaximumPowerAsymmetry_isUsed:1;
    // EVSEPowerRampLimitation, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVSEPowerRampLimitation;
    unsigned int EVSEPowerRampLimitation_isUsed:1;
    // EVSEPresentActivePower, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVSEPresentActivePower;
    unsigned int EVSEPresentActivePower_isUsed:1;
    // EVSEPresentActivePower_L2, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVSEPresentActivePower_L2;
    unsigned int EVSEPresentActivePower_L2_isUsed:1;
    // EVSEPresentActivePower_L3, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVSEPresentActivePower_L3;
    unsigned int EVSEPresentActivePower_L3_isUsed:1;
    // EVSEMaximumDischargePower, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVSEMaximumDischargePower;
    // EVSEMaximumDischargePower_L2, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVSEMaximumDischargePower_L2;
    unsigned int EVSEMaximumDischargePower_L2_isUsed:1;
    // EVSEMaximumDischargePower_L3, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVSEMaximumDischargePower_L3;
    unsigned int EVSEMaximumDischargePower_L3_isUsed:1;
    // EVSEMinimumDischargePower, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVSEMinimumDischargePower;
    // EVSEMinimumDischargePower_L2, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVSEMinimumDischargePower_L2;
    unsigned int EVSEMinimumDischargePower_L2_isUsed:1;
    // EVSEMinimumDischargePower_L3, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVSEMinimumDischargePower_L3;
    unsigned int EVSEMinimumDischargePower_L3_isUsed:1;

};

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:AC}BPT_Dynamic_AC_CLReqControlMode; type={urn:iso:std:iso:15118:-20:AC}BPT_Dynamic_AC_CLReqControlModeType; base type=Dynamic_AC_CLReqControlModeType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: DepartureTime, unsignedInt (0, 1); EVTargetEnergyRequest, RationalNumberType (1, 1); EVMaximumEnergyRequest, RationalNumberType (1, 1); EVMinimumEnergyRequest, RationalNumberType (1, 1); EVMaximumChargePower, RationalNumberType (1, 1); EVMaximumChargePower_L2, RationalNumberType (0, 1); EVMaximumChargePower_L3, RationalNumberType (0, 1); EVMinimumChargePower, RationalNumberType (1, 1); EVMinimumChargePower_L2, RationalNumberType (0, 1); EVMinimumChargePower_L3, RationalNumberType (0, 1); EVPresentActivePower, RationalNumberType (1, 1); EVPresentActivePower_L2, RationalNumberType (0, 1); EVPresentActivePower_L3, RationalNumberType (0, 1); EVPresentReactivePower, RationalNumberType (1, 1); EVPresentReactivePower_L2, RationalNumberType (0, 1); EVPresentReactivePower_L3, RationalNumberType (0, 1); EVMaximumDischargePower, RationalNumberType (1, 1); EVMaximumDischargePower_L2, RationalNumberType (0, 1); EVMaximumDischargePower_L3, RationalNumberType (0, 1); EVMinimumDischargePower, RationalNumberType (1, 1); EVMinimumDischargePower_L2, RationalNumberType (0, 1); EVMinimumDischargePower_L3, RationalNumberType (0, 1); EVMaximumV2XEnergyRequest, RationalNumberType (0, 1); EVMinimumV2XEnergyRequest, RationalNumberType (0, 1);
struct iso20_ac_der_BPT_Dynamic_AC_CLReqControlModeType {
    // DepartureTime, unsignedInt (base: unsignedLong)
    uint32_t DepartureTime;
    unsigned int DepartureTime_isUsed:1;
    // EVTargetEnergyRequest, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVTargetEnergyRequest;
    // EVMaximumEnergyRequest, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVMaximumEnergyRequest;
    // EVMinimumEnergyRequest, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVMinimumEnergyRequest;
    // EVMaximumChargePower, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVMaximumChargePower;
    // EVMaximumChargePower_L2, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVMaximumChargePower_L2;
    unsigned int EVMaximumChargePower_L2_isUsed:1;
    // EVMaximumChargePower_L3, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVMaximumChargePower_L3;
    unsigned int EVMaximumChargePower_L3_isUsed:1;
    // EVMinimumChargePower, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVMinimumChargePower;
    // EVMinimumChargePower_L2, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVMinimumChargePower_L2;
    unsigned int EVMinimumChargePower_L2_isUsed:1;
    // EVMinimumChargePower_L3, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVMinimumChargePower_L3;
    unsigned int EVMinimumChargePower_L3_isUsed:1;
    // EVPresentActivePower, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVPresentActivePower;
    // EVPresentActivePower_L2, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVPresentActivePower_L2;
    unsigned int EVPresentActivePower_L2_isUsed:1;
    // EVPresentActivePower_L3, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVPresentActivePower_L3;
    unsigned int EVPresentActivePower_L3_isUsed:1;
    // EVPresentReactivePower, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVPresentReactivePower;
    // EVPresentReactivePower_L2, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVPresentReactivePower_L2;
    unsigned int EVPresentReactivePower_L2_isUsed:1;
    // EVPresentReactivePower_L3, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVPresentReactivePower_L3;
    unsigned int EVPresentReactivePower_L3_isUsed:1;
    // EVMaximumDischargePower, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVMaximumDischargePower;
    // EVMaximumDischargePower_L2, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVMaximumDischargePower_L2;
    unsigned int EVMaximumDischargePower_L2_isUsed:1;
    // EVMaximumDischargePower_L3, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVMaximumDischargePower_L3;
    unsigned int EVMaximumDischargePower_L3_isUsed:1;
    // EVMinimumDischargePower, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVMinimumDischargePower;
    // EVMinimumDischargePower_L2, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVMinimumDischargePower_L2;
    unsigned int EVMinimumDischargePower_L2_isUsed:1;
    // EVMinimumDischargePower_L3, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVMinimumDischargePower_L3;
    unsigned int EVMinimumDischargePower_L3_isUsed:1;
    // EVMaximumV2XEnergyRequest, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVMaximumV2XEnergyRequest;
    unsigned int EVMaximumV2XEnergyRequest_isUsed:1;
    // EVMinimumV2XEnergyRequest, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVMinimumV2XEnergyRequest;
    unsigned int EVMinimumV2XEnergyRequest_isUsed:1;

};

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:AC}BPT_Dynamic_AC_CLResControlMode; type={urn:iso:std:iso:15118:-20:AC}BPT_Dynamic_AC_CLResControlModeType; base type=Dynamic_AC_CLResControlModeType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: DepartureTime, unsignedInt (0, 1); MinimumSOC, percentValueType (0, 1); TargetSOC, percentValueType (0, 1); AckMaxDelay, unsignedShort (0, 1); EVSETargetActivePower, RationalNumberType (1, 1); EVSETargetActivePower_L2, RationalNumberType (0, 1); EVSETargetActivePower_L3, RationalNumberType (0, 1); EVSETargetReactivePower, RationalNumberType (0, 1); EVSETargetReactivePower_L2, RationalNumberType (0, 1); EVSETargetReactivePower_L3, RationalNumberType (0, 1); EVSEPresentActivePower, RationalNumberType (0, 1); EVSEPresentActivePower_L2, RationalNumberType (0, 1); EVSEPresentActivePower_L3, RationalNumberType (0, 1);
struct iso20_ac_der_BPT_Dynamic_AC_CLResControlModeType {
    // DepartureTime, unsignedInt (base: unsignedLong)
    uint32_t DepartureTime;
    unsigned int DepartureTime_isUsed:1;
    // MinimumSOC, percentValueType (base: byte)
    int8_t MinimumSOC;
    unsigned int MinimumSOC_isUsed:1;
    // TargetSOC, percentValueType (base: byte)
    int8_t TargetSOC;
    unsigned int TargetSOC_isUsed:1;
    // AckMaxDelay, unsignedShort (base: unsignedInt)
    uint16_t AckMaxDelay;
    unsigned int AckMaxDelay_isUsed:1;
    // EVSETargetActivePower, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVSETargetActivePower;
    // EVSETargetActivePower_L2, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVSETargetActivePower_L2;
    unsigned int EVSETargetActivePower_L2_isUsed:1;
    // EVSETargetActivePower_L3, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVSETargetActivePower_L3;
    unsigned int EVSETargetActivePower_L3_isUsed:1;
    // EVSETargetReactivePower, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVSETargetReactivePower;
    unsigned int EVSETargetReactivePower_isUsed:1;
    // EVSETargetReactivePower_L2, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVSETargetReactivePower_L2;
    unsigned int EVSETargetReactivePower_L2_isUsed:1;
    // EVSETargetReactivePower_L3, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVSETargetReactivePower_L3;
    unsigned int EVSETargetReactivePower_L3_isUsed:1;
    // EVSEPresentActivePower, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVSEPresentActivePower;
    unsigned int EVSEPresentActivePower_isUsed:1;
    // EVSEPresentActivePower_L2, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVSEPresentActivePower_L2;
    unsigned int EVSEPresentActivePower_L2_isUsed:1;
    // EVSEPresentActivePower_L3, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVSEPresentActivePower_L3;
    unsigned int EVSEPresentActivePower_L3_isUsed:1;

};

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:AC}BPT_Scheduled_AC_CLReqControlMode; type={urn:iso:std:iso:15118:-20:AC}BPT_Scheduled_AC_CLReqControlModeType; base type=Scheduled_AC_CLReqControlModeType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: EVTargetEnergyRequest, RationalNumberType (0, 1); EVMaximumEnergyRequest, RationalNumberType (0, 1); EVMinimumEnergyRequest, RationalNumberType (0, 1); EVMaximumChargePower, RationalNumberType (0, 1); EVMaximumChargePower_L2, RationalNumberType (0, 1); EVMaximumChargePower_L3, RationalNumberType (0, 1); EVMinimumChargePower, RationalNumberType (0, 1); EVMinimumChargePower_L2, RationalNumberType (0, 1); EVMinimumChargePower_L3, RationalNumberType (0, 1); EVPresentActivePower, RationalNumberType (1, 1); EVPresentActivePower_L2, RationalNumberType (0, 1); EVPresentActivePower_L3, RationalNumberType (0, 1); EVPresentReactivePower, RationalNumberType (0, 1); EVPresentReactivePower_L2, RationalNumberType (0, 1); EVPresentReactivePower_L3, RationalNumberType (0, 1); EVMaximumDischargePower, RationalNumberType (0, 1); EVMaximumDischargePower_L2, RationalNumberType (0, 1); EVMaximumDischargePower_L3, RationalNumberType (0, 1); EVMinimumDischargePower, RationalNumberType (0, 1); EVMinimumDischargePower_L2, RationalNumberType (0, 1); EVMinimumDischargePower_L3, RationalNumberType (0, 1);
struct iso20_ac_der_BPT_Scheduled_AC_CLReqControlModeType {
    // EVTargetEnergyRequest, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVTargetEnergyRequest;
    unsigned int EVTargetEnergyRequest_isUsed:1;
    // EVMaximumEnergyRequest, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVMaximumEnergyRequest;
    unsigned int EVMaximumEnergyRequest_isUsed:1;
    // EVMinimumEnergyRequest, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVMinimumEnergyRequest;
    unsigned int EVMinimumEnergyRequest_isUsed:1;
    // EVMaximumChargePower, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVMaximumChargePower;
    unsigned int EVMaximumChargePower_isUsed:1;
    // EVMaximumChargePower_L2, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVMaximumChargePower_L2;
    unsigned int EVMaximumChargePower_L2_isUsed:1;
    // EVMaximumChargePower_L3, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVMaximumChargePower_L3;
    unsigned int EVMaximumChargePower_L3_isUsed:1;
    // EVMinimumChargePower, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVMinimumChargePower;
    unsigned int EVMinimumChargePower_isUsed:1;
    // EVMinimumChargePower_L2, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVMinimumChargePower_L2;
    unsigned int EVMinimumChargePower_L2_isUsed:1;
    // EVMinimumChargePower_L3, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVMinimumChargePower_L3;
    unsigned int EVMinimumChargePower_L3_isUsed:1;
    // EVPresentActivePower, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVPresentActivePower;
    // EVPresentActivePower_L2, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVPresentActivePower_L2;
    unsigned int EVPresentActivePower_L2_isUsed:1;
    // EVPresentActivePower_L3, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVPresentActivePower_L3;
    unsigned int EVPresentActivePower_L3_isUsed:1;
    // EVPresentReactivePower, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVPresentReactivePower;
    unsigned int EVPresentReactivePower_isUsed:1;
    // EVPresentReactivePower_L2, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVPresentReactivePower_L2;
    unsigned int EVPresentReactivePower_L2_isUsed:1;
    // EVPresentReactivePower_L3, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVPresentReactivePower_L3;
    unsigned int EVPresentReactivePower_L3_isUsed:1;
    // EVMaximumDischargePower, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVMaximumDischargePower;
    unsigned int EVMaximumDischargePower_isUsed:1;
    // EVMaximumDischargePower_L2, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVMaximumDischargePower_L2;
    unsigned int EVMaximumDischargePower_L2_isUsed:1;
    // EVMaximumDischargePower_L3, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVMaximumDischargePower_L3;
    unsigned int EVMaximumDischargePower_L3_isUsed:1;
    // EVMinimumDischargePower, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVMinimumDischargePower;
    unsigned int EVMinimumDischargePower_isUsed:1;
    // EVMinimumDischargePower_L2, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVMinimumDischargePower_L2;
    unsigned int EVMinimumDischargePower_L2_isUsed:1;
    // EVMinimumDischargePower_L3, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVMinimumDischargePower_L3;
    unsigned int EVMinimumDischargePower_L3_isUsed:1;

};

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:AC}BPT_Scheduled_AC_CLResControlMode; type={urn:iso:std:iso:15118:-20:AC}BPT_Scheduled_AC_CLResControlModeType; base type=Scheduled_AC_CLResControlModeType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: EVSETargetActivePower, RationalNumberType (0, 1); EVSETargetActivePower_L2, RationalNumberType (0, 1); EVSETargetActivePower_L3, RationalNumberType (0, 1); EVSETargetReactivePower, RationalNumberType (0, 1); EVSETargetReactivePower_L2, RationalNumberType (0, 1); EVSETargetReactivePower_L3, RationalNumberType (0, 1); EVSEPresentActivePower, RationalNumberType (0, 1); EVSEPresentActivePower_L2, RationalNumberType (0, 1); EVSEPresentActivePower_L3, RationalNumberType (0, 1);
struct iso20_ac_der_BPT_Scheduled_AC_CLResControlModeType {
    // EVSETargetActivePower, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVSETargetActivePower;
    unsigned int EVSETargetActivePower_isUsed:1;
    // EVSETargetActivePower_L2, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVSETargetActivePower_L2;
    unsigned int EVSETargetActivePower_L2_isUsed:1;
    // EVSETargetActivePower_L3, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVSETargetActivePower_L3;
    unsigned int EVSETargetActivePower_L3_isUsed:1;
    // EVSETargetReactivePower, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVSETargetReactivePower;
    unsigned int EVSETargetReactivePower_isUsed:1;
    // EVSETargetReactivePower_L2, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVSETargetReactivePower_L2;
    unsigned int EVSETargetReactivePower_L2_isUsed:1;
    // EVSETargetReactivePower_L3, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVSETargetReactivePower_L3;
    unsigned int EVSETargetReactivePower_L3_isUsed:1;
    // EVSEPresentActivePower, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVSEPresentActivePower;
    unsigned int EVSEPresentActivePower_isUsed:1;
    // EVSEPresentActivePower_L2, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVSEPresentActivePower_L2;
    unsigned int EVSEPresentActivePower_L2_isUsed:1;
    // EVSEPresentActivePower_L3, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVSEPresentActivePower_L3;
    unsigned int EVSEPresentActivePower_L3_isUsed:1;

};

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:CommonTypes}CLReqControlMode; type={urn:iso:std:iso:15118:-20:CommonTypes}CLReqControlModeType; base type=; content type=empty;
//          abstract=False; final=False;
// Particle: 
struct iso20_ac_der_CLReqControlModeType {
    int _unused;
};

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:CommonTypes}CLResControlMode; type={urn:iso:std:iso:15118:-20:CommonTypes}CLResControlModeType; base type=; content type=empty;
//          abstract=False; final=False;
// Particle: 
struct iso20_ac_der_CLResControlModeType {
    int _unused;
};

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:AC-DER}DER_AC_CPDReqEnergyTransferMode; type={urn:iso:std:iso:15118:-20:AC-DER}DER_AC_CPDReqEnergyTransferModeType; base type=AC_CPDReqEnergyTransferModeType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: EVMaximumChargePower, RationalNumberType (1, 1); EVMaximumChargePower_L2, RationalNumberType (0, 1); EVMaximumChargePower_L3, RationalNumberType (0, 1); EVMinimumChargePower, RationalNumberType (1, 1); EVMinimumChargePower_L2, RationalNumberType (0, 1); EVMinimumChargePower_L3, RationalNumberType (0, 1); EVProcessing, processingType (1, 1); EVMaximumDischargePower, PhaseType (1, 1); EVMinimumDischargePower, PhaseType (1, 1); EVSessionTotalDischargeEnergyAvailable, RationalNumberType (0, 1); EVApparentPowerLimits, EVApparentPowerLimitsType (0, 1); EVReactivePowerLimits, EVReactivePowerLimitsType (0, 1); EVExcitationLimits, EVExcitationLimitsType (0, 1); EVInverterDetails, EVInverterDetailsType (0, 1);
struct iso20_ac_der_DER_AC_CPDReqEnergyTransferModeType {
    // EVMaximumChargePower, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVMaximumChargePower;
    // EVMaximumChargePower_L2, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVMaximumChargePower_L2;
    unsigned int EVMaximumChargePower_L2_isUsed:1;
    // EVMaximumChargePower_L3, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVMaximumChargePower_L3;
    unsigned int EVMaximumChargePower_L3_isUsed:1;
    // EVMinimumChargePower, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVMinimumChargePower;
    // EVMinimumChargePower_L2, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVMinimumChargePower_L2;
    unsigned int EVMinimumChargePower_L2_isUsed:1;
    // EVMinimumChargePower_L3, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVMinimumChargePower_L3;
    unsigned int EVMinimumChargePower_L3_isUsed:1;
    // EVProcessing, processingType (base: string)
    iso20_ac_der_processingType EVProcessing;
    // EVMaximumDischargePower, PhaseType
    struct iso20_ac_der_PhaseType EVMaximumDischargePower;
    // EVMinimumDischargePower, PhaseType
    struct iso20_ac_der_PhaseType EVMinimumDischargePower;
    // EVSessionTotalDischargeEnergyAvailable, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVSessionTotalDischargeEnergyAvailable;
    unsigned int EVSessionTotalDischargeEnergyAvailable_isUsed:1;
    // EVApparentPowerLimits, EVApparentPowerLimitsType
    struct iso20_ac_der_EVApparentPowerLimitsType EVApparentPowerLimits;
    unsigned int EVApparentPowerLimits_isUsed:1;
    // EVReactivePowerLimits, EVReactivePowerLimitsType
    struct iso20_ac_der_EVReactivePowerLimitsType EVReactivePowerLimits;
    unsigned int EVReactivePowerLimits_isUsed:1;
    // EVExcitationLimits, EVExcitationLimitsType
    struct iso20_ac_der_EVExcitationLimitsType EVExcitationLimits;
    unsigned int EVExcitationLimits_isUsed:1;
    // EVInverterDetails, EVInverterDetailsType
    struct iso20_ac_der_EVInverterDetailsType EVInverterDetails;
    unsigned int EVInverterDetails_isUsed:1;

};

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:AC-DER}DER_AC_CPDResEnergyTransferMode; type={urn:iso:std:iso:15118:-20:AC-DER}DER_AC_CPDResEnergyTransferModeType; base type=AC_CPDResEnergyTransferModeType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: EVSEMaximumChargePower, RationalNumberType (1, 1); EVSEMaximumChargePower_L2, RationalNumberType (0, 1); EVSEMaximumChargePower_L3, RationalNumberType (0, 1); EVSEMinimumChargePower, RationalNumberType (1, 1); EVSEMinimumChargePower_L2, RationalNumberType (0, 1); EVSEMinimumChargePower_L3, RationalNumberType (0, 1); EVSENominalFrequency, RationalNumberType (1, 1); MaximumPowerAsymmetry, RationalNumberType (0, 1); EVSEPowerRampLimitation, RationalNumberType (0, 1); EVSEPresentActivePower, RationalNumberType (0, 1); EVSEPresentActivePower_L2, RationalNumberType (0, 1); EVSEPresentActivePower_L3, RationalNumberType (0, 1); EVSEStatus, EVSEStatusType (0, 1); DERControl, DERControlType (1, 1); EVSENominalPower, RationalNumberType (1, 1); EVSEMaximumDischargePower, PhaseType (0, 1); EVSEMaximumChargeReactivePower, PhaseType (0, 1); EVSEMaximumDischargeReactivePower, PhaseType (0, 1); GridLimits, GridLimitsType (1, 1);
struct iso20_ac_der_DER_AC_CPDResEnergyTransferModeType {
    // EVSEMaximumChargePower, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVSEMaximumChargePower;
    // EVSEMaximumChargePower_L2, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVSEMaximumChargePower_L2;
    unsigned int EVSEMaximumChargePower_L2_isUsed:1;
    // EVSEMaximumChargePower_L3, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVSEMaximumChargePower_L3;
    unsigned int EVSEMaximumChargePower_L3_isUsed:1;
    // EVSEMinimumChargePower, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVSEMinimumChargePower;
    // EVSEMinimumChargePower_L2, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVSEMinimumChargePower_L2;
    unsigned int EVSEMinimumChargePower_L2_isUsed:1;
    // EVSEMinimumChargePower_L3, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVSEMinimumChargePower_L3;
    unsigned int EVSEMinimumChargePower_L3_isUsed:1;
    // EVSENominalFrequency, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVSENominalFrequency;
    // MaximumPowerAsymmetry, RationalNumberType
    struct iso20_ac_der_RationalNumberType MaximumPowerAsymmetry;
    unsigned int MaximumPowerAsymmetry_isUsed:1;
    // EVSEPowerRampLimitation, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVSEPowerRampLimitation;
    unsigned int EVSEPowerRampLimitation_isUsed:1;
    // EVSEPresentActivePower, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVSEPresentActivePower;
    unsigned int EVSEPresentActivePower_isUsed:1;
    // EVSEPresentActivePower_L2, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVSEPresentActivePower_L2;
    unsigned int EVSEPresentActivePower_L2_isUsed:1;
    // EVSEPresentActivePower_L3, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVSEPresentActivePower_L3;
    unsigned int EVSEPresentActivePower_L3_isUsed:1;
    // EVSEStatus, EVSEStatusType
    struct iso20_ac_der_EVSEStatusType EVSEStatus;
    unsigned int EVSEStatus_isUsed:1;
    // DERControl, DERControlType
    struct iso20_ac_der_DERControlType DERControl;
    // EVSENominalPower, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVSENominalPower;
    // EVSEMaximumDischargePower, PhaseType
    struct iso20_ac_der_PhaseType EVSEMaximumDischargePower;
    unsigned int EVSEMaximumDischargePower_isUsed:1;
    // EVSEMaximumChargeReactivePower, PhaseType
    struct iso20_ac_der_PhaseType EVSEMaximumChargeReactivePower;
    unsigned int EVSEMaximumChargeReactivePower_isUsed:1;
    // EVSEMaximumDischargeReactivePower, PhaseType
    struct iso20_ac_der_PhaseType EVSEMaximumDischargeReactivePower;
    unsigned int EVSEMaximumDischargeReactivePower_isUsed:1;
    // GridLimits, GridLimitsType
    struct iso20_ac_der_GridLimitsType GridLimits;

};

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:AC-DER}DER_Dynamic_AC_CLReqControlMode; type={urn:iso:std:iso:15118:-20:AC-DER}DER_Dynamic_AC_CLReqControlModeType; base type=Dynamic_AC_CLReqControlModeType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: DepartureTime, unsignedInt (0, 1); EVTargetEnergyRequest, RationalNumberType (1, 1); EVMaximumEnergyRequest, RationalNumberType (1, 1); EVMinimumEnergyRequest, RationalNumberType (1, 1); EVMaximumChargePower, RationalNumberType (1, 1); EVMaximumChargePower_L2, RationalNumberType (0, 1); EVMaximumChargePower_L3, RationalNumberType (0, 1); EVMinimumChargePower, RationalNumberType (1, 1); EVMinimumChargePower_L2, RationalNumberType (0, 1); EVMinimumChargePower_L3, RationalNumberType (0, 1); EVPresentActivePower, RationalNumberType (1, 1); EVPresentActivePower_L2, RationalNumberType (0, 1); EVPresentActivePower_L3, RationalNumberType (0, 1); EVPresentReactivePower, RationalNumberType (1, 1); EVPresentReactivePower_L2, RationalNumberType (0, 1); EVPresentReactivePower_L3, RationalNumberType (0, 1); EVMaximumDischargePower, PhaseType (1, 1); EVMinimumDischargePower, PhaseType (1, 1); EVSessionTotalDischargeEnergyAvailable, RationalNumberType (0, 1); EVApparentPower, EVApparentPowerType (0, 1); EVReactivePower, EVReactivePowerType (0, 1); EVExcitation, EVExcitationType (0, 1); EVSetPoints, EVSetPointsType (0, 1); EVPresentVoltage, PhaseType (0, 1); EVPresentFrequency, PhaseType (0, 1); DERGridSupportActiveInfo, DERGridSupportActiveInfoType (0, 1);
struct iso20_ac_der_DER_Dynamic_AC_CLReqControlModeType {
    // DepartureTime, unsignedInt (base: unsignedLong)
    uint32_t DepartureTime;
    unsigned int DepartureTime_isUsed:1;
    // EVTargetEnergyRequest, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVTargetEnergyRequest;
    // EVMaximumEnergyRequest, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVMaximumEnergyRequest;
    // EVMinimumEnergyRequest, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVMinimumEnergyRequest;
    // EVMaximumChargePower, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVMaximumChargePower;
    // EVMaximumChargePower_L2, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVMaximumChargePower_L2;
    unsigned int EVMaximumChargePower_L2_isUsed:1;
    // EVMaximumChargePower_L3, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVMaximumChargePower_L3;
    unsigned int EVMaximumChargePower_L3_isUsed:1;
    // EVMinimumChargePower, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVMinimumChargePower;
    // EVMinimumChargePower_L2, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVMinimumChargePower_L2;
    unsigned int EVMinimumChargePower_L2_isUsed:1;
    // EVMinimumChargePower_L3, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVMinimumChargePower_L3;
    unsigned int EVMinimumChargePower_L3_isUsed:1;
    // EVPresentActivePower, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVPresentActivePower;
    // EVPresentActivePower_L2, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVPresentActivePower_L2;
    unsigned int EVPresentActivePower_L2_isUsed:1;
    // EVPresentActivePower_L3, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVPresentActivePower_L3;
    unsigned int EVPresentActivePower_L3_isUsed:1;
    // EVPresentReactivePower, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVPresentReactivePower;
    // EVPresentReactivePower_L2, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVPresentReactivePower_L2;
    unsigned int EVPresentReactivePower_L2_isUsed:1;
    // EVPresentReactivePower_L3, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVPresentReactivePower_L3;
    unsigned int EVPresentReactivePower_L3_isUsed:1;
    // EVMaximumDischargePower, PhaseType
    struct iso20_ac_der_PhaseType EVMaximumDischargePower;
    // EVMinimumDischargePower, PhaseType
    struct iso20_ac_der_PhaseType EVMinimumDischargePower;
    // EVSessionTotalDischargeEnergyAvailable, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVSessionTotalDischargeEnergyAvailable;
    unsigned int EVSessionTotalDischargeEnergyAvailable_isUsed:1;
    // EVApparentPower, EVApparentPowerType
    struct iso20_ac_der_EVApparentPowerType EVApparentPower;
    unsigned int EVApparentPower_isUsed:1;
    // EVReactivePower, EVReactivePowerType
    struct iso20_ac_der_EVReactivePowerType EVReactivePower;
    unsigned int EVReactivePower_isUsed:1;
    // EVExcitation, EVExcitationType
    struct iso20_ac_der_EVExcitationType EVExcitation;
    unsigned int EVExcitation_isUsed:1;
    // EVSetPoints, EVSetPointsType
    struct iso20_ac_der_EVSetPointsType EVSetPoints;
    unsigned int EVSetPoints_isUsed:1;
    // EVPresentVoltage, PhaseType
    struct iso20_ac_der_PhaseType EVPresentVoltage;
    unsigned int EVPresentVoltage_isUsed:1;
    // EVPresentFrequency, PhaseType
    struct iso20_ac_der_PhaseType EVPresentFrequency;
    unsigned int EVPresentFrequency_isUsed:1;
    // DERGridSupportActiveInfo, DERGridSupportActiveInfoType
    struct iso20_ac_der_DERGridSupportActiveInfoType DERGridSupportActiveInfo;
    unsigned int DERGridSupportActiveInfo_isUsed:1;

};

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:AC-DER}DER_Dynamic_AC_CLResControlMode; type={urn:iso:std:iso:15118:-20:AC-DER}DER_Dynamic_AC_CLResControlModeType; base type=Dynamic_AC_CLResControlModeType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: DepartureTime, unsignedInt (0, 1); MinimumSOC, percentValueType (0, 1); TargetSOC, percentValueType (0, 1); AckMaxDelay, unsignedShort (0, 1); EVSETargetActivePower, RationalNumberType (1, 1); EVSETargetActivePower_L2, RationalNumberType (0, 1); EVSETargetActivePower_L3, RationalNumberType (0, 1); EVSETargetReactivePower, RationalNumberType (0, 1); EVSETargetReactivePower_L2, RationalNumberType (0, 1); EVSETargetReactivePower_L3, RationalNumberType (0, 1); EVSEPresentActivePower, RationalNumberType (0, 1); EVSEPresentActivePower_L2, RationalNumberType (0, 1); EVSEPresentActivePower_L3, RationalNumberType (0, 1); DERControl, DERControlType (0, 1);
struct iso20_ac_der_DER_Dynamic_AC_CLResControlModeType {
    // DepartureTime, unsignedInt (base: unsignedLong)
    uint32_t DepartureTime;
    unsigned int DepartureTime_isUsed:1;
    // MinimumSOC, percentValueType (base: byte)
    int8_t MinimumSOC;
    unsigned int MinimumSOC_isUsed:1;
    // TargetSOC, percentValueType (base: byte)
    int8_t TargetSOC;
    unsigned int TargetSOC_isUsed:1;
    // AckMaxDelay, unsignedShort (base: unsignedInt)
    uint16_t AckMaxDelay;
    unsigned int AckMaxDelay_isUsed:1;
    // EVSETargetActivePower, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVSETargetActivePower;
    // EVSETargetActivePower_L2, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVSETargetActivePower_L2;
    unsigned int EVSETargetActivePower_L2_isUsed:1;
    // EVSETargetActivePower_L3, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVSETargetActivePower_L3;
    unsigned int EVSETargetActivePower_L3_isUsed:1;
    // EVSETargetReactivePower, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVSETargetReactivePower;
    unsigned int EVSETargetReactivePower_isUsed:1;
    // EVSETargetReactivePower_L2, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVSETargetReactivePower_L2;
    unsigned int EVSETargetReactivePower_L2_isUsed:1;
    // EVSETargetReactivePower_L3, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVSETargetReactivePower_L3;
    unsigned int EVSETargetReactivePower_L3_isUsed:1;
    // EVSEPresentActivePower, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVSEPresentActivePower;
    unsigned int EVSEPresentActivePower_isUsed:1;
    // EVSEPresentActivePower_L2, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVSEPresentActivePower_L2;
    unsigned int EVSEPresentActivePower_L2_isUsed:1;
    // EVSEPresentActivePower_L3, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVSEPresentActivePower_L3;
    unsigned int EVSEPresentActivePower_L3_isUsed:1;
    // DERControl, DERControlType
    struct iso20_ac_der_DERControlType DERControl;
    unsigned int DERControl_isUsed:1;

};

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:AC-DER}DER_Scheduled_AC_CLReqControlMode; type={urn:iso:std:iso:15118:-20:AC-DER}DER_Scheduled_AC_CLReqControlModeType; base type=Scheduled_AC_CLReqControlModeType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: EVTargetEnergyRequest, RationalNumberType (0, 1); EVMaximumEnergyRequest, RationalNumberType (0, 1); EVMinimumEnergyRequest, RationalNumberType (0, 1); EVMaximumChargePower, RationalNumberType (0, 1); EVMaximumChargePower_L2, RationalNumberType (0, 1); EVMaximumChargePower_L3, RationalNumberType (0, 1); EVMinimumChargePower, RationalNumberType (0, 1); EVMinimumChargePower_L2, RationalNumberType (0, 1); EVMinimumChargePower_L3, RationalNumberType (0, 1); EVPresentActivePower, RationalNumberType (1, 1); EVPresentActivePower_L2, RationalNumberType (0, 1); EVPresentActivePower_L3, RationalNumberType (0, 1); EVPresentReactivePower, RationalNumberType (0, 1); EVPresentReactivePower_L2, RationalNumberType (0, 1); EVPresentReactivePower_L3, RationalNumberType (0, 1); EVMaximumDischargePower, PhaseType (1, 1); EVMinimumDischargePower, PhaseType (1, 1); EVSessionTotalDischargeEnergyAvailable, RationalNumberType (0, 1); EVApparentPower, EVApparentPowerType (0, 1); EVReactivePower, EVReactivePowerType (0, 1); EVExcitation, EVExcitationType (0, 1); EVSetPoints, EVSetPointsType (0, 1); EVPresentVoltage, PhaseType (0, 1); EVPresentFrequency, PhaseType (0, 1); DERGridSupportActiveInfo, DERGridSupportActiveInfoType (0, 1);
struct iso20_ac_der_DER_Scheduled_AC_CLReqControlModeType {
    // EVTargetEnergyRequest, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVTargetEnergyRequest;
    unsigned int EVTargetEnergyRequest_isUsed:1;
    // EVMaximumEnergyRequest, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVMaximumEnergyRequest;
    unsigned int EVMaximumEnergyRequest_isUsed:1;
    // EVMinimumEnergyRequest, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVMinimumEnergyRequest;
    unsigned int EVMinimumEnergyRequest_isUsed:1;
    // EVMaximumChargePower, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVMaximumChargePower;
    unsigned int EVMaximumChargePower_isUsed:1;
    // EVMaximumChargePower_L2, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVMaximumChargePower_L2;
    unsigned int EVMaximumChargePower_L2_isUsed:1;
    // EVMaximumChargePower_L3, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVMaximumChargePower_L3;
    unsigned int EVMaximumChargePower_L3_isUsed:1;
    // EVMinimumChargePower, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVMinimumChargePower;
    unsigned int EVMinimumChargePower_isUsed:1;
    // EVMinimumChargePower_L2, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVMinimumChargePower_L2;
    unsigned int EVMinimumChargePower_L2_isUsed:1;
    // EVMinimumChargePower_L3, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVMinimumChargePower_L3;
    unsigned int EVMinimumChargePower_L3_isUsed:1;
    // EVPresentActivePower, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVPresentActivePower;
    // EVPresentActivePower_L2, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVPresentActivePower_L2;
    unsigned int EVPresentActivePower_L2_isUsed:1;
    // EVPresentActivePower_L3, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVPresentActivePower_L3;
    unsigned int EVPresentActivePower_L3_isUsed:1;
    // EVPresentReactivePower, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVPresentReactivePower;
    unsigned int EVPresentReactivePower_isUsed:1;
    // EVPresentReactivePower_L2, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVPresentReactivePower_L2;
    unsigned int EVPresentReactivePower_L2_isUsed:1;
    // EVPresentReactivePower_L3, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVPresentReactivePower_L3;
    unsigned int EVPresentReactivePower_L3_isUsed:1;
    // EVMaximumDischargePower, PhaseType
    struct iso20_ac_der_PhaseType EVMaximumDischargePower;
    // EVMinimumDischargePower, PhaseType
    struct iso20_ac_der_PhaseType EVMinimumDischargePower;
    // EVSessionTotalDischargeEnergyAvailable, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVSessionTotalDischargeEnergyAvailable;
    unsigned int EVSessionTotalDischargeEnergyAvailable_isUsed:1;
    // EVApparentPower, EVApparentPowerType
    struct iso20_ac_der_EVApparentPowerType EVApparentPower;
    unsigned int EVApparentPower_isUsed:1;
    // EVReactivePower, EVReactivePowerType
    struct iso20_ac_der_EVReactivePowerType EVReactivePower;
    unsigned int EVReactivePower_isUsed:1;
    // EVExcitation, EVExcitationType
    struct iso20_ac_der_EVExcitationType EVExcitation;
    unsigned int EVExcitation_isUsed:1;
    // EVSetPoints, EVSetPointsType
    struct iso20_ac_der_EVSetPointsType EVSetPoints;
    unsigned int EVSetPoints_isUsed:1;
    // EVPresentVoltage, PhaseType
    struct iso20_ac_der_PhaseType EVPresentVoltage;
    unsigned int EVPresentVoltage_isUsed:1;
    // EVPresentFrequency, PhaseType
    struct iso20_ac_der_PhaseType EVPresentFrequency;
    unsigned int EVPresentFrequency_isUsed:1;
    // DERGridSupportActiveInfo, DERGridSupportActiveInfoType
    struct iso20_ac_der_DERGridSupportActiveInfoType DERGridSupportActiveInfo;
    unsigned int DERGridSupportActiveInfo_isUsed:1;

};

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:AC-DER}DER_Scheduled_AC_CLResControlMode; type={urn:iso:std:iso:15118:-20:AC-DER}DER_Scheduled_AC_CLResControlModeType; base type=Scheduled_AC_CLResControlModeType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: EVSETargetActivePower, RationalNumberType (0, 1); EVSETargetActivePower_L2, RationalNumberType (0, 1); EVSETargetActivePower_L3, RationalNumberType (0, 1); EVSETargetReactivePower, RationalNumberType (0, 1); EVSETargetReactivePower_L2, RationalNumberType (0, 1); EVSETargetReactivePower_L3, RationalNumberType (0, 1); EVSEPresentActivePower, RationalNumberType (0, 1); EVSEPresentActivePower_L2, RationalNumberType (0, 1); EVSEPresentActivePower_L3, RationalNumberType (0, 1); DERControl, DERControlType (0, 1);
struct iso20_ac_der_DER_Scheduled_AC_CLResControlModeType {
    // EVSETargetActivePower, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVSETargetActivePower;
    unsigned int EVSETargetActivePower_isUsed:1;
    // EVSETargetActivePower_L2, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVSETargetActivePower_L2;
    unsigned int EVSETargetActivePower_L2_isUsed:1;
    // EVSETargetActivePower_L3, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVSETargetActivePower_L3;
    unsigned int EVSETargetActivePower_L3_isUsed:1;
    // EVSETargetReactivePower, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVSETargetReactivePower;
    unsigned int EVSETargetReactivePower_isUsed:1;
    // EVSETargetReactivePower_L2, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVSETargetReactivePower_L2;
    unsigned int EVSETargetReactivePower_L2_isUsed:1;
    // EVSETargetReactivePower_L3, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVSETargetReactivePower_L3;
    unsigned int EVSETargetReactivePower_L3_isUsed:1;
    // EVSEPresentActivePower, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVSEPresentActivePower;
    unsigned int EVSEPresentActivePower_isUsed:1;
    // EVSEPresentActivePower_L2, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVSEPresentActivePower_L2;
    unsigned int EVSEPresentActivePower_L2_isUsed:1;
    // EVSEPresentActivePower_L3, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVSEPresentActivePower_L3;
    unsigned int EVSEPresentActivePower_L3_isUsed:1;
    // DERControl, DERControlType
    struct iso20_ac_der_DERControlType DERControl;
    unsigned int DERControl_isUsed:1;

};

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:AC}Dynamic_AC_CLReqControlMode; type={urn:iso:std:iso:15118:-20:AC}Dynamic_AC_CLReqControlModeType; base type=Dynamic_CLReqControlModeType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: DepartureTime, unsignedInt (0, 1); EVTargetEnergyRequest, RationalNumberType (1, 1); EVMaximumEnergyRequest, RationalNumberType (1, 1); EVMinimumEnergyRequest, RationalNumberType (1, 1); EVMaximumChargePower, RationalNumberType (1, 1); EVMaximumChargePower_L2, RationalNumberType (0, 1); EVMaximumChargePower_L3, RationalNumberType (0, 1); EVMinimumChargePower, RationalNumberType (1, 1); EVMinimumChargePower_L2, RationalNumberType (0, 1); EVMinimumChargePower_L3, RationalNumberType (0, 1); EVPresentActivePower, RationalNumberType (1, 1); EVPresentActivePower_L2, RationalNumberType (0, 1); EVPresentActivePower_L3, RationalNumberType (0, 1); EVPresentReactivePower, RationalNumberType (1, 1); EVPresentReactivePower_L2, RationalNumberType (0, 1); EVPresentReactivePower_L3, RationalNumberType (0, 1);
struct iso20_ac_der_Dynamic_AC_CLReqControlModeType {
    // DepartureTime, unsignedInt (base: unsignedLong)
    uint32_t DepartureTime;
    unsigned int DepartureTime_isUsed:1;
    // EVTargetEnergyRequest, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVTargetEnergyRequest;
    // EVMaximumEnergyRequest, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVMaximumEnergyRequest;
    // EVMinimumEnergyRequest, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVMinimumEnergyRequest;
    // EVMaximumChargePower, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVMaximumChargePower;
    // EVMaximumChargePower_L2, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVMaximumChargePower_L2;
    unsigned int EVMaximumChargePower_L2_isUsed:1;
    // EVMaximumChargePower_L3, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVMaximumChargePower_L3;
    unsigned int EVMaximumChargePower_L3_isUsed:1;
    // EVMinimumChargePower, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVMinimumChargePower;
    // EVMinimumChargePower_L2, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVMinimumChargePower_L2;
    unsigned int EVMinimumChargePower_L2_isUsed:1;
    // EVMinimumChargePower_L3, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVMinimumChargePower_L3;
    unsigned int EVMinimumChargePower_L3_isUsed:1;
    // EVPresentActivePower, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVPresentActivePower;
    // EVPresentActivePower_L2, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVPresentActivePower_L2;
    unsigned int EVPresentActivePower_L2_isUsed:1;
    // EVPresentActivePower_L3, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVPresentActivePower_L3;
    unsigned int EVPresentActivePower_L3_isUsed:1;
    // EVPresentReactivePower, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVPresentReactivePower;
    // EVPresentReactivePower_L2, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVPresentReactivePower_L2;
    unsigned int EVPresentReactivePower_L2_isUsed:1;
    // EVPresentReactivePower_L3, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVPresentReactivePower_L3;
    unsigned int EVPresentReactivePower_L3_isUsed:1;

};

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:AC}Dynamic_AC_CLResControlMode; type={urn:iso:std:iso:15118:-20:AC}Dynamic_AC_CLResControlModeType; base type=Dynamic_CLResControlModeType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: DepartureTime, unsignedInt (0, 1); MinimumSOC, percentValueType (0, 1); TargetSOC, percentValueType (0, 1); AckMaxDelay, unsignedShort (0, 1); EVSETargetActivePower, RationalNumberType (1, 1); EVSETargetActivePower_L2, RationalNumberType (0, 1); EVSETargetActivePower_L3, RationalNumberType (0, 1); EVSETargetReactivePower, RationalNumberType (0, 1); EVSETargetReactivePower_L2, RationalNumberType (0, 1); EVSETargetReactivePower_L3, RationalNumberType (0, 1); EVSEPresentActivePower, RationalNumberType (0, 1); EVSEPresentActivePower_L2, RationalNumberType (0, 1); EVSEPresentActivePower_L3, RationalNumberType (0, 1);
struct iso20_ac_der_Dynamic_AC_CLResControlModeType {
    // DepartureTime, unsignedInt (base: unsignedLong)
    uint32_t DepartureTime;
    unsigned int DepartureTime_isUsed:1;
    // MinimumSOC, percentValueType (base: byte)
    int8_t MinimumSOC;
    unsigned int MinimumSOC_isUsed:1;
    // TargetSOC, percentValueType (base: byte)
    int8_t TargetSOC;
    unsigned int TargetSOC_isUsed:1;
    // AckMaxDelay, unsignedShort (base: unsignedInt)
    uint16_t AckMaxDelay;
    unsigned int AckMaxDelay_isUsed:1;
    // EVSETargetActivePower, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVSETargetActivePower;
    // EVSETargetActivePower_L2, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVSETargetActivePower_L2;
    unsigned int EVSETargetActivePower_L2_isUsed:1;
    // EVSETargetActivePower_L3, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVSETargetActivePower_L3;
    unsigned int EVSETargetActivePower_L3_isUsed:1;
    // EVSETargetReactivePower, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVSETargetReactivePower;
    unsigned int EVSETargetReactivePower_isUsed:1;
    // EVSETargetReactivePower_L2, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVSETargetReactivePower_L2;
    unsigned int EVSETargetReactivePower_L2_isUsed:1;
    // EVSETargetReactivePower_L3, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVSETargetReactivePower_L3;
    unsigned int EVSETargetReactivePower_L3_isUsed:1;
    // EVSEPresentActivePower, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVSEPresentActivePower;
    unsigned int EVSEPresentActivePower_isUsed:1;
    // EVSEPresentActivePower_L2, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVSEPresentActivePower_L2;
    unsigned int EVSEPresentActivePower_L2_isUsed:1;
    // EVSEPresentActivePower_L3, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVSEPresentActivePower_L3;
    unsigned int EVSEPresentActivePower_L3_isUsed:1;

};

// Element: definition=complex; name={http://www.w3.org/2000/09/xmldsig#}Manifest; type={http://www.w3.org/2000/09/xmldsig#}ManifestType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: Id, ID (0, 1); Reference, ReferenceType (1, 4) (original max unbounded);
struct iso20_ac_der_ManifestType {
    // Attribute: Id, ID (base: NCName)
    struct {
        char characters[iso20_ac_der_Id_CHARACTER_SIZE];
        uint16_t charactersLen;
    } Id;
    unsigned int Id_isUsed:1;
    // Reference, ReferenceType
    struct {
        struct iso20_ac_der_ReferenceType array[iso20_ac_der_ReferenceType_4_ARRAY_SIZE];
        uint16_t arrayLen;
    } Reference;
};

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:AC}Scheduled_AC_CLReqControlMode; type={urn:iso:std:iso:15118:-20:AC}Scheduled_AC_CLReqControlModeType; base type=Scheduled_CLReqControlModeType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: EVTargetEnergyRequest, RationalNumberType (0, 1); EVMaximumEnergyRequest, RationalNumberType (0, 1); EVMinimumEnergyRequest, RationalNumberType (0, 1); EVMaximumChargePower, RationalNumberType (0, 1); EVMaximumChargePower_L2, RationalNumberType (0, 1); EVMaximumChargePower_L3, RationalNumberType (0, 1); EVMinimumChargePower, RationalNumberType (0, 1); EVMinimumChargePower_L2, RationalNumberType (0, 1); EVMinimumChargePower_L3, RationalNumberType (0, 1); EVPresentActivePower, RationalNumberType (1, 1); EVPresentActivePower_L2, RationalNumberType (0, 1); EVPresentActivePower_L3, RationalNumberType (0, 1); EVPresentReactivePower, RationalNumberType (0, 1); EVPresentReactivePower_L2, RationalNumberType (0, 1); EVPresentReactivePower_L3, RationalNumberType (0, 1);
struct iso20_ac_der_Scheduled_AC_CLReqControlModeType {
    // EVTargetEnergyRequest, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVTargetEnergyRequest;
    unsigned int EVTargetEnergyRequest_isUsed:1;
    // EVMaximumEnergyRequest, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVMaximumEnergyRequest;
    unsigned int EVMaximumEnergyRequest_isUsed:1;
    // EVMinimumEnergyRequest, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVMinimumEnergyRequest;
    unsigned int EVMinimumEnergyRequest_isUsed:1;
    // EVMaximumChargePower, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVMaximumChargePower;
    unsigned int EVMaximumChargePower_isUsed:1;
    // EVMaximumChargePower_L2, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVMaximumChargePower_L2;
    unsigned int EVMaximumChargePower_L2_isUsed:1;
    // EVMaximumChargePower_L3, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVMaximumChargePower_L3;
    unsigned int EVMaximumChargePower_L3_isUsed:1;
    // EVMinimumChargePower, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVMinimumChargePower;
    unsigned int EVMinimumChargePower_isUsed:1;
    // EVMinimumChargePower_L2, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVMinimumChargePower_L2;
    unsigned int EVMinimumChargePower_L2_isUsed:1;
    // EVMinimumChargePower_L3, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVMinimumChargePower_L3;
    unsigned int EVMinimumChargePower_L3_isUsed:1;
    // EVPresentActivePower, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVPresentActivePower;
    // EVPresentActivePower_L2, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVPresentActivePower_L2;
    unsigned int EVPresentActivePower_L2_isUsed:1;
    // EVPresentActivePower_L3, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVPresentActivePower_L3;
    unsigned int EVPresentActivePower_L3_isUsed:1;
    // EVPresentReactivePower, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVPresentReactivePower;
    unsigned int EVPresentReactivePower_isUsed:1;
    // EVPresentReactivePower_L2, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVPresentReactivePower_L2;
    unsigned int EVPresentReactivePower_L2_isUsed:1;
    // EVPresentReactivePower_L3, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVPresentReactivePower_L3;
    unsigned int EVPresentReactivePower_L3_isUsed:1;

};

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:AC}Scheduled_AC_CLResControlMode; type={urn:iso:std:iso:15118:-20:AC}Scheduled_AC_CLResControlModeType; base type=Scheduled_CLResControlModeType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: EVSETargetActivePower, RationalNumberType (0, 1); EVSETargetActivePower_L2, RationalNumberType (0, 1); EVSETargetActivePower_L3, RationalNumberType (0, 1); EVSETargetReactivePower, RationalNumberType (0, 1); EVSETargetReactivePower_L2, RationalNumberType (0, 1); EVSETargetReactivePower_L3, RationalNumberType (0, 1); EVSEPresentActivePower, RationalNumberType (0, 1); EVSEPresentActivePower_L2, RationalNumberType (0, 1); EVSEPresentActivePower_L3, RationalNumberType (0, 1);
struct iso20_ac_der_Scheduled_AC_CLResControlModeType {
    // EVSETargetActivePower, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVSETargetActivePower;
    unsigned int EVSETargetActivePower_isUsed:1;
    // EVSETargetActivePower_L2, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVSETargetActivePower_L2;
    unsigned int EVSETargetActivePower_L2_isUsed:1;
    // EVSETargetActivePower_L3, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVSETargetActivePower_L3;
    unsigned int EVSETargetActivePower_L3_isUsed:1;
    // EVSETargetReactivePower, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVSETargetReactivePower;
    unsigned int EVSETargetReactivePower_isUsed:1;
    // EVSETargetReactivePower_L2, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVSETargetReactivePower_L2;
    unsigned int EVSETargetReactivePower_L2_isUsed:1;
    // EVSETargetReactivePower_L3, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVSETargetReactivePower_L3;
    unsigned int EVSETargetReactivePower_L3_isUsed:1;
    // EVSEPresentActivePower, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVSEPresentActivePower;
    unsigned int EVSEPresentActivePower_isUsed:1;
    // EVSEPresentActivePower_L2, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVSEPresentActivePower_L2;
    unsigned int EVSEPresentActivePower_L2_isUsed:1;
    // EVSEPresentActivePower_L3, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVSEPresentActivePower_L3;
    unsigned int EVSEPresentActivePower_L3_isUsed:1;

};

// Element: definition=complex; name={http://www.w3.org/2000/09/xmldsig#}Signature; type={http://www.w3.org/2000/09/xmldsig#}SignatureType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: Id, ID (0, 1); SignedInfo, SignedInfoType (1, 1); SignatureValue, SignatureValueType (1, 1); KeyInfo, KeyInfoType (0, 1); Object, ObjectType (0, 1) (original max unbounded);
struct iso20_ac_der_SignatureType {
    // Attribute: Id, ID (base: NCName)
    struct {
        char characters[iso20_ac_der_Id_CHARACTER_SIZE];
        uint16_t charactersLen;
    } Id;
    unsigned int Id_isUsed:1;
    // SignedInfo, SignedInfoType
    struct iso20_ac_der_SignedInfoType SignedInfo;
    // SignatureValue, SignatureValueType (base: base64Binary)
    struct iso20_ac_der_SignatureValueType SignatureValue;
    // KeyInfo, KeyInfoType
    struct iso20_ac_der_KeyInfoType KeyInfo;
    unsigned int KeyInfo_isUsed:1;
    // Object, ObjectType
    struct iso20_ac_der_ObjectType Object;
    unsigned int Object_isUsed:1;

};

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:CommonTypes}Header; type={urn:iso:std:iso:15118:-20:CommonTypes}MessageHeaderType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: SessionID, sessionIDType (1, 1); TimeStamp, unsignedLong (1, 1); Signature, SignatureType (0, 1);
struct iso20_ac_der_MessageHeaderType {
    // SessionID, sessionIDType (base: hexBinary)
    struct {
        uint8_t bytes[iso20_ac_der_sessionIDType_BYTES_SIZE];
        uint16_t bytesLen;
    } SessionID;

    // TimeStamp, unsignedLong (base: nonNegativeInteger)
    uint64_t TimeStamp;
    // Signature, SignatureType
    struct iso20_ac_der_SignatureType Signature;
    unsigned int Signature_isUsed:1;

};

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:AC}AC_ChargeLoopReq; type={urn:iso:std:iso:15118:-20:AC}AC_ChargeLoopReqType; base type=ChargeLoopReqType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: Header, MessageHeaderType (1, 1); DisplayParameters, DisplayParametersType (0, 1); MeterInfoRequested, boolean (1, 1); BPT_Dynamic_AC_CLReqControlMode, BPT_Dynamic_AC_CLReqControlModeType (0, 1); BPT_Scheduled_AC_CLReqControlMode, BPT_Scheduled_AC_CLReqControlModeType (0, 1); CLReqControlMode, CLReqControlModeType (0, 1); DER_Dynamic_AC_CLReqControlMode, DER_Dynamic_AC_CLReqControlModeType (0, 1); DER_Scheduled_AC_CLReqControlMode, DER_Scheduled_AC_CLReqControlModeType (0, 1); Dynamic_AC_CLReqControlMode, Dynamic_AC_CLReqControlModeType (0, 1); Scheduled_AC_CLReqControlMode, Scheduled_AC_CLReqControlModeType (0, 1);
struct iso20_ac_der_AC_ChargeLoopReqType {
    // Header, MessageHeaderType
    struct iso20_ac_der_MessageHeaderType Header;
    // DisplayParameters, DisplayParametersType
    struct iso20_ac_der_DisplayParametersType DisplayParameters;
    unsigned int DisplayParameters_isUsed:1;
    // MeterInfoRequested, boolean
    int MeterInfoRequested;
    // BPT_Dynamic_AC_CLReqControlMode, BPT_Dynamic_AC_CLReqControlModeType (base: Dynamic_AC_CLReqControlModeType)
    struct iso20_ac_der_BPT_Dynamic_AC_CLReqControlModeType BPT_Dynamic_AC_CLReqControlMode;
    unsigned int BPT_Dynamic_AC_CLReqControlMode_isUsed:1;
    // BPT_Scheduled_AC_CLReqControlMode, BPT_Scheduled_AC_CLReqControlModeType (base: Scheduled_AC_CLReqControlModeType)
    struct iso20_ac_der_BPT_Scheduled_AC_CLReqControlModeType BPT_Scheduled_AC_CLReqControlMode;
    unsigned int BPT_Scheduled_AC_CLReqControlMode_isUsed:1;
    // CLReqControlMode, CLReqControlModeType
    struct iso20_ac_der_CLReqControlModeType CLReqControlMode;
    unsigned int CLReqControlMode_isUsed:1;
    // DER_Dynamic_AC_CLReqControlMode, DER_Dynamic_AC_CLReqControlModeType (base: Dynamic_AC_CLReqControlModeType)
    struct iso20_ac_der_DER_Dynamic_AC_CLReqControlModeType DER_Dynamic_AC_CLReqControlMode;
    unsigned int DER_Dynamic_AC_CLReqControlMode_isUsed:1;
    // DER_Scheduled_AC_CLReqControlMode, DER_Scheduled_AC_CLReqControlModeType (base: Scheduled_AC_CLReqControlModeType)
    struct iso20_ac_der_DER_Scheduled_AC_CLReqControlModeType DER_Scheduled_AC_CLReqControlMode;
    unsigned int DER_Scheduled_AC_CLReqControlMode_isUsed:1;
    // Dynamic_AC_CLReqControlMode, Dynamic_AC_CLReqControlModeType (base: Dynamic_CLReqControlModeType)
    struct iso20_ac_der_Dynamic_AC_CLReqControlModeType Dynamic_AC_CLReqControlMode;
    unsigned int Dynamic_AC_CLReqControlMode_isUsed:1;
    // Scheduled_AC_CLReqControlMode, Scheduled_AC_CLReqControlModeType (base: Scheduled_CLReqControlModeType)
    struct iso20_ac_der_Scheduled_AC_CLReqControlModeType Scheduled_AC_CLReqControlMode;
    unsigned int Scheduled_AC_CLReqControlMode_isUsed:1;

};

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:AC}AC_ChargeLoopRes; type={urn:iso:std:iso:15118:-20:AC}AC_ChargeLoopResType; base type=ChargeLoopResType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: Header, MessageHeaderType (1, 1); ResponseCode, responseCodeType (1, 1); EVSEStatus, EVSEStatusType (0, 1); MeterInfo, MeterInfoType (0, 1); Receipt, ReceiptType (0, 1); EVSETargetFrequency, RationalNumberType (0, 1); BPT_Dynamic_AC_CLResControlMode, BPT_Dynamic_AC_CLResControlModeType (0, 1); BPT_Scheduled_AC_CLResControlMode, BPT_Scheduled_AC_CLResControlModeType (0, 1); CLResControlMode, CLResControlModeType (0, 1); DER_Dynamic_AC_CLResControlMode, DER_Dynamic_AC_CLResControlModeType (0, 1); DER_Scheduled_AC_CLResControlMode, DER_Scheduled_AC_CLResControlModeType (0, 1); Dynamic_AC_CLResControlMode, Dynamic_AC_CLResControlModeType (0, 1); Scheduled_AC_CLResControlMode, Scheduled_AC_CLResControlModeType (0, 1);
struct iso20_ac_der_AC_ChargeLoopResType {
    // Header, MessageHeaderType
    struct iso20_ac_der_MessageHeaderType Header;
    // ResponseCode, responseCodeType (base: string)
    iso20_ac_der_responseCodeType ResponseCode;
    // EVSEStatus, EVSEStatusType
    struct iso20_ac_der_EVSEStatusType EVSEStatus;
    unsigned int EVSEStatus_isUsed:1;
    // MeterInfo, MeterInfoType
    struct iso20_ac_der_MeterInfoType MeterInfo;
    unsigned int MeterInfo_isUsed:1;
    // Receipt, ReceiptType
    struct iso20_ac_der_ReceiptType Receipt;
    unsigned int Receipt_isUsed:1;
    // EVSETargetFrequency, RationalNumberType
    struct iso20_ac_der_RationalNumberType EVSETargetFrequency;
    unsigned int EVSETargetFrequency_isUsed:1;
    // BPT_Dynamic_AC_CLResControlMode, BPT_Dynamic_AC_CLResControlModeType (base: Dynamic_AC_CLResControlModeType)
    struct iso20_ac_der_BPT_Dynamic_AC_CLResControlModeType BPT_Dynamic_AC_CLResControlMode;
    unsigned int BPT_Dynamic_AC_CLResControlMode_isUsed:1;
    // BPT_Scheduled_AC_CLResControlMode, BPT_Scheduled_AC_CLResControlModeType (base: Scheduled_AC_CLResControlModeType)
    struct iso20_ac_der_BPT_Scheduled_AC_CLResControlModeType BPT_Scheduled_AC_CLResControlMode;
    unsigned int BPT_Scheduled_AC_CLResControlMode_isUsed:1;
    // CLResControlMode, CLResControlModeType
    struct iso20_ac_der_CLResControlModeType CLResControlMode;
    unsigned int CLResControlMode_isUsed:1;
    // DER_Dynamic_AC_CLResControlMode, DER_Dynamic_AC_CLResControlModeType (base: Dynamic_AC_CLResControlModeType)
    struct iso20_ac_der_DER_Dynamic_AC_CLResControlModeType DER_Dynamic_AC_CLResControlMode;
    unsigned int DER_Dynamic_AC_CLResControlMode_isUsed:1;
    // DER_Scheduled_AC_CLResControlMode, DER_Scheduled_AC_CLResControlModeType (base: Scheduled_AC_CLResControlModeType)
    struct iso20_ac_der_DER_Scheduled_AC_CLResControlModeType DER_Scheduled_AC_CLResControlMode;
    unsigned int DER_Scheduled_AC_CLResControlMode_isUsed:1;
    // Dynamic_AC_CLResControlMode, Dynamic_AC_CLResControlModeType (base: Dynamic_CLResControlModeType)
    struct iso20_ac_der_Dynamic_AC_CLResControlModeType Dynamic_AC_CLResControlMode;
    unsigned int Dynamic_AC_CLResControlMode_isUsed:1;
    // Scheduled_AC_CLResControlMode, Scheduled_AC_CLResControlModeType (base: Scheduled_CLResControlModeType)
    struct iso20_ac_der_Scheduled_AC_CLResControlModeType Scheduled_AC_CLResControlMode;
    unsigned int Scheduled_AC_CLResControlMode_isUsed:1;

};

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:AC}AC_ChargeParameterDiscoveryReq; type={urn:iso:std:iso:15118:-20:AC}AC_ChargeParameterDiscoveryReqType; base type=ChargeParameterDiscoveryReqType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: Header, MessageHeaderType (1, 1); AC_CPDReqEnergyTransferMode, AC_CPDReqEnergyTransferModeType (0, 1); BPT_AC_CPDReqEnergyTransferMode, BPT_AC_CPDReqEnergyTransferModeType (0, 1); DER_AC_CPDReqEnergyTransferMode, DER_AC_CPDReqEnergyTransferModeType (0, 1);
struct iso20_ac_der_AC_ChargeParameterDiscoveryReqType {
    // Header, MessageHeaderType
    struct iso20_ac_der_MessageHeaderType Header;
    // AC_CPDReqEnergyTransferMode, AC_CPDReqEnergyTransferModeType
    struct iso20_ac_der_AC_CPDReqEnergyTransferModeType AC_CPDReqEnergyTransferMode;
    unsigned int AC_CPDReqEnergyTransferMode_isUsed:1;
    // BPT_AC_CPDReqEnergyTransferMode, BPT_AC_CPDReqEnergyTransferModeType (base: AC_CPDReqEnergyTransferModeType)
    struct iso20_ac_der_BPT_AC_CPDReqEnergyTransferModeType BPT_AC_CPDReqEnergyTransferMode;
    unsigned int BPT_AC_CPDReqEnergyTransferMode_isUsed:1;
    // DER_AC_CPDReqEnergyTransferMode, DER_AC_CPDReqEnergyTransferModeType (base: AC_CPDReqEnergyTransferModeType)
    struct iso20_ac_der_DER_AC_CPDReqEnergyTransferModeType DER_AC_CPDReqEnergyTransferMode;
    unsigned int DER_AC_CPDReqEnergyTransferMode_isUsed:1;

};

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:AC}AC_ChargeParameterDiscoveryRes; type={urn:iso:std:iso:15118:-20:AC}AC_ChargeParameterDiscoveryResType; base type=ChargeParameterDiscoveryResType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: Header, MessageHeaderType (1, 1); ResponseCode, responseCodeType (1, 1); AC_CPDResEnergyTransferMode, AC_CPDResEnergyTransferModeType (0, 1); BPT_AC_CPDResEnergyTransferMode, BPT_AC_CPDResEnergyTransferModeType (0, 1); DER_AC_CPDResEnergyTransferMode, DER_AC_CPDResEnergyTransferModeType (0, 1);
struct iso20_ac_der_AC_ChargeParameterDiscoveryResType {
    // Header, MessageHeaderType
    struct iso20_ac_der_MessageHeaderType Header;
    // ResponseCode, responseCodeType (base: string)
    iso20_ac_der_responseCodeType ResponseCode;
    // AC_CPDResEnergyTransferMode, AC_CPDResEnergyTransferModeType
    struct iso20_ac_der_AC_CPDResEnergyTransferModeType AC_CPDResEnergyTransferMode;
    unsigned int AC_CPDResEnergyTransferMode_isUsed:1;
    // BPT_AC_CPDResEnergyTransferMode, BPT_AC_CPDResEnergyTransferModeType (base: AC_CPDResEnergyTransferModeType)
    struct iso20_ac_der_BPT_AC_CPDResEnergyTransferModeType BPT_AC_CPDResEnergyTransferMode;
    unsigned int BPT_AC_CPDResEnergyTransferMode_isUsed:1;
    // DER_AC_CPDResEnergyTransferMode, DER_AC_CPDResEnergyTransferModeType (base: AC_CPDResEnergyTransferModeType)
    struct iso20_ac_der_DER_AC_CPDResEnergyTransferModeType DER_AC_CPDResEnergyTransferMode;
    unsigned int DER_AC_CPDResEnergyTransferMode_isUsed:1;

};

// Element: definition=complex; name={http://www.w3.org/2000/09/xmldsig#}SignatureProperties; type={http://www.w3.org/2000/09/xmldsig#}SignaturePropertiesType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: Id, ID (0, 1); SignatureProperty, SignaturePropertyType (1, 1) (original max unbounded);
struct iso20_ac_der_SignaturePropertiesType {
    // Attribute: Id, ID (base: NCName)
    struct {
        char characters[iso20_ac_der_Id_CHARACTER_SIZE];
        uint16_t charactersLen;
    } Id;
    unsigned int Id_isUsed:1;
    // SignatureProperty, SignaturePropertyType
    struct iso20_ac_der_SignaturePropertyType SignatureProperty;

};



// root elements of EXI doc
struct iso20_ac_der_exiDocument {
    union {
        struct iso20_ac_der_AC_CPDReqEnergyTransferModeType AC_CPDReqEnergyTransferMode;
        struct iso20_ac_der_DER_AC_CPDReqEnergyTransferModeType DER_AC_CPDReqEnergyTransferMode;
        struct iso20_ac_der_AC_CPDResEnergyTransferModeType AC_CPDResEnergyTransferMode;
        struct iso20_ac_der_DER_AC_CPDResEnergyTransferModeType DER_AC_CPDResEnergyTransferMode;
        struct iso20_ac_der_CLReqControlModeType CLReqControlMode;
        struct iso20_ac_der_Scheduled_AC_CLReqControlModeType Scheduled_AC_CLReqControlMode;
        struct iso20_ac_der_DER_Scheduled_AC_CLReqControlModeType DER_Scheduled_AC_CLReqControlMode;
        struct iso20_ac_der_CLResControlModeType CLResControlMode;
        struct iso20_ac_der_Scheduled_AC_CLResControlModeType Scheduled_AC_CLResControlMode;
        struct iso20_ac_der_DER_Scheduled_AC_CLResControlModeType DER_Scheduled_AC_CLResControlMode;
        struct iso20_ac_der_Dynamic_AC_CLReqControlModeType Dynamic_AC_CLReqControlMode;
        struct iso20_ac_der_DER_Dynamic_AC_CLReqControlModeType DER_Dynamic_AC_CLReqControlMode;
        struct iso20_ac_der_Dynamic_AC_CLResControlModeType Dynamic_AC_CLResControlMode;
        struct iso20_ac_der_DER_Dynamic_AC_CLResControlModeType DER_Dynamic_AC_CLResControlMode;
        struct iso20_ac_der_FrequencyDroopType FrequencyDroop;
        struct iso20_ac_der_EU_FrequencyDroopType EU_FrequencyDroop;
        struct iso20_ac_der_US_FrequencyDroopType US_FrequencyDroop;
        struct iso20_ac_der_SignatureType Signature;
        struct iso20_ac_der_SignatureValueType SignatureValue;
        struct iso20_ac_der_SignedInfoType SignedInfo;
        struct iso20_ac_der_CanonicalizationMethodType CanonicalizationMethod;
        struct iso20_ac_der_SignatureMethodType SignatureMethod;
        struct iso20_ac_der_ReferenceType Reference;
        struct iso20_ac_der_TransformsType Transforms;
        struct iso20_ac_der_TransformType Transform;
        struct iso20_ac_der_DigestMethodType DigestMethod;
        struct iso20_ac_der_KeyInfoType KeyInfo;
        struct iso20_ac_der_KeyValueType KeyValue;
        struct iso20_ac_der_RetrievalMethodType RetrievalMethod;
        struct iso20_ac_der_X509DataType X509Data;
        struct iso20_ac_der_PGPDataType PGPData;
        struct iso20_ac_der_SPKIDataType SPKIData;
        struct iso20_ac_der_ObjectType Object;
        struct iso20_ac_der_ManifestType Manifest;
        struct iso20_ac_der_SignaturePropertiesType SignatureProperties;
        struct iso20_ac_der_SignaturePropertyType SignatureProperty;
        struct iso20_ac_der_DSAKeyValueType DSAKeyValue;
        struct iso20_ac_der_RSAKeyValueType RSAKeyValue;
        struct iso20_ac_der_AC_ChargeParameterDiscoveryReqType AC_ChargeParameterDiscoveryReq;
        struct iso20_ac_der_AC_ChargeParameterDiscoveryResType AC_ChargeParameterDiscoveryRes;
        struct iso20_ac_der_AC_ChargeLoopReqType AC_ChargeLoopReq;
        struct iso20_ac_der_AC_ChargeLoopResType AC_ChargeLoopRes;
        struct iso20_ac_der_BPT_AC_CPDReqEnergyTransferModeType BPT_AC_CPDReqEnergyTransferMode;
        struct iso20_ac_der_BPT_AC_CPDResEnergyTransferModeType BPT_AC_CPDResEnergyTransferMode;
        struct iso20_ac_der_BPT_Scheduled_AC_CLReqControlModeType BPT_Scheduled_AC_CLReqControlMode;
        struct iso20_ac_der_BPT_Scheduled_AC_CLResControlModeType BPT_Scheduled_AC_CLResControlMode;
        struct iso20_ac_der_BPT_Dynamic_AC_CLReqControlModeType BPT_Dynamic_AC_CLReqControlMode;
        struct iso20_ac_der_BPT_Dynamic_AC_CLResControlModeType BPT_Dynamic_AC_CLResControlMode;
    };
    unsigned int AC_CPDReqEnergyTransferMode_isUsed:1;
    unsigned int DER_AC_CPDReqEnergyTransferMode_isUsed:1;
    unsigned int AC_CPDResEnergyTransferMode_isUsed:1;
    unsigned int DER_AC_CPDResEnergyTransferMode_isUsed:1;
    unsigned int CLReqControlMode_isUsed:1;
    unsigned int Scheduled_AC_CLReqControlMode_isUsed:1;
    unsigned int DER_Scheduled_AC_CLReqControlMode_isUsed:1;
    unsigned int CLResControlMode_isUsed:1;
    unsigned int Scheduled_AC_CLResControlMode_isUsed:1;
    unsigned int DER_Scheduled_AC_CLResControlMode_isUsed:1;
    unsigned int Dynamic_AC_CLReqControlMode_isUsed:1;
    unsigned int DER_Dynamic_AC_CLReqControlMode_isUsed:1;
    unsigned int Dynamic_AC_CLResControlMode_isUsed:1;
    unsigned int DER_Dynamic_AC_CLResControlMode_isUsed:1;
    unsigned int FrequencyDroop_isUsed:1;
    unsigned int EU_FrequencyDroop_isUsed:1;
    unsigned int US_FrequencyDroop_isUsed:1;
    unsigned int Signature_isUsed:1;
    unsigned int SignatureValue_isUsed:1;
    unsigned int SignedInfo_isUsed:1;
    unsigned int CanonicalizationMethod_isUsed:1;
    unsigned int SignatureMethod_isUsed:1;
    unsigned int Reference_isUsed:1;
    unsigned int Transforms_isUsed:1;
    unsigned int Transform_isUsed:1;
    unsigned int DigestMethod_isUsed:1;
    unsigned int KeyInfo_isUsed:1;
    unsigned int KeyValue_isUsed:1;
    unsigned int RetrievalMethod_isUsed:1;
    unsigned int X509Data_isUsed:1;
    unsigned int PGPData_isUsed:1;
    unsigned int SPKIData_isUsed:1;
    unsigned int Object_isUsed:1;
    unsigned int Manifest_isUsed:1;
    unsigned int SignatureProperties_isUsed:1;
    unsigned int SignatureProperty_isUsed:1;
    unsigned int DSAKeyValue_isUsed:1;
    unsigned int RSAKeyValue_isUsed:1;
    unsigned int AC_ChargeParameterDiscoveryReq_isUsed:1;
    unsigned int AC_ChargeParameterDiscoveryRes_isUsed:1;
    unsigned int AC_ChargeLoopReq_isUsed:1;
    unsigned int AC_ChargeLoopRes_isUsed:1;
    unsigned int BPT_AC_CPDReqEnergyTransferMode_isUsed:1;
    unsigned int BPT_AC_CPDResEnergyTransferMode_isUsed:1;
    unsigned int BPT_Scheduled_AC_CLReqControlMode_isUsed:1;
    unsigned int BPT_Scheduled_AC_CLResControlMode_isUsed:1;
    unsigned int BPT_Dynamic_AC_CLReqControlMode_isUsed:1;
    unsigned int BPT_Dynamic_AC_CLResControlMode_isUsed:1;
};

// elements of EXI fragment
struct iso20_ac_der_exiFragment {
    union {
        struct iso20_ac_der_AC_ChargeParameterDiscoveryResType AC_ChargeParameterDiscoveryRes;
        struct iso20_ac_der_SignedInfoType SignedInfo;
    };
    unsigned int AC_ChargeParameterDiscoveryRes_isUsed:1;
    unsigned int SignedInfo_isUsed:1;
};

// elements of xmldsig fragment
struct iso20_ac_der_xmldsigFragment {
    union {
        struct iso20_ac_der_CanonicalizationMethodType CanonicalizationMethod;
        struct iso20_ac_der_DSAKeyValueType DSAKeyValue;
        struct iso20_ac_der_DigestMethodType DigestMethod;
        struct iso20_ac_der_KeyInfoType KeyInfo;
        struct iso20_ac_der_KeyValueType KeyValue;
        struct iso20_ac_der_ManifestType Manifest;
        struct iso20_ac_der_ObjectType Object;
        struct iso20_ac_der_PGPDataType PGPData;
        struct iso20_ac_der_RSAKeyValueType RSAKeyValue;
        struct iso20_ac_der_ReferenceType Reference;
        struct iso20_ac_der_RetrievalMethodType RetrievalMethod;
        struct iso20_ac_der_SPKIDataType SPKIData;
        struct iso20_ac_der_SignatureType Signature;
        struct iso20_ac_der_SignatureMethodType SignatureMethod;
        struct iso20_ac_der_SignaturePropertiesType SignatureProperties;
        struct iso20_ac_der_SignaturePropertyType SignatureProperty;
        struct iso20_ac_der_SignatureValueType SignatureValue;
        struct iso20_ac_der_SignedInfoType SignedInfo;
        struct iso20_ac_der_TransformType Transform;
        struct iso20_ac_der_TransformsType Transforms;
        struct iso20_ac_der_X509DataType X509Data;
    };
    unsigned int CanonicalizationMethod_isUsed:1;
    unsigned int DSAKeyValue_isUsed:1;
    unsigned int DigestMethod_isUsed:1;
    unsigned int KeyInfo_isUsed:1;
    unsigned int KeyValue_isUsed:1;
    unsigned int Manifest_isUsed:1;
    unsigned int Object_isUsed:1;
    unsigned int PGPData_isUsed:1;
    unsigned int RSAKeyValue_isUsed:1;
    unsigned int Reference_isUsed:1;
    unsigned int RetrievalMethod_isUsed:1;
    unsigned int SPKIData_isUsed:1;
    unsigned int Signature_isUsed:1;
    unsigned int SignatureMethod_isUsed:1;
    unsigned int SignatureProperties_isUsed:1;
    unsigned int SignatureProperty_isUsed:1;
    unsigned int SignatureValue_isUsed:1;
    unsigned int SignedInfo_isUsed:1;
    unsigned int Transform_isUsed:1;
    unsigned int Transforms_isUsed:1;
    unsigned int X509Data_isUsed:1;
};

// init for structs
void init_iso20_ac_der_AC_CPDReqEnergyTransferModeType(struct iso20_ac_der_AC_CPDReqEnergyTransferModeType* AC_CPDReqEnergyTransferMode);
void init_iso20_ac_der_AC_CPDResEnergyTransferModeType(struct iso20_ac_der_AC_CPDResEnergyTransferModeType* AC_CPDResEnergyTransferMode);
void init_iso20_ac_der_AC_ChargeLoopReqType(struct iso20_ac_der_AC_ChargeLoopReqType* AC_ChargeLoopReq);
void init_iso20_ac_der_AC_ChargeLoopResType(struct iso20_ac_der_AC_ChargeLoopResType* AC_ChargeLoopRes);
void init_iso20_ac_der_AC_ChargeParameterDiscoveryReqType(struct iso20_ac_der_AC_ChargeParameterDiscoveryReqType* AC_ChargeParameterDiscoveryReq);
void init_iso20_ac_der_AC_ChargeParameterDiscoveryResType(struct iso20_ac_der_AC_ChargeParameterDiscoveryResType* AC_ChargeParameterDiscoveryRes);
void init_iso20_ac_der_ActivePowerSupportType(struct iso20_ac_der_ActivePowerSupportType* ActivePowerSupportType);
void init_iso20_ac_der_BPT_AC_CPDReqEnergyTransferModeType(struct iso20_ac_der_BPT_AC_CPDReqEnergyTransferModeType* BPT_AC_CPDReqEnergyTransferMode);
void init_iso20_ac_der_BPT_AC_CPDResEnergyTransferModeType(struct iso20_ac_der_BPT_AC_CPDResEnergyTransferModeType* BPT_AC_CPDResEnergyTransferMode);
void init_iso20_ac_der_BPT_Dynamic_AC_CLReqControlModeType(struct iso20_ac_der_BPT_Dynamic_AC_CLReqControlModeType* BPT_Dynamic_AC_CLReqControlMode);
void init_iso20_ac_der_BPT_Dynamic_AC_CLResControlModeType(struct iso20_ac_der_BPT_Dynamic_AC_CLResControlModeType* BPT_Dynamic_AC_CLResControlMode);
void init_iso20_ac_der_BPT_Scheduled_AC_CLReqControlModeType(struct iso20_ac_der_BPT_Scheduled_AC_CLReqControlModeType* BPT_Scheduled_AC_CLReqControlMode);
void init_iso20_ac_der_BPT_Scheduled_AC_CLResControlModeType(struct iso20_ac_der_BPT_Scheduled_AC_CLResControlModeType* BPT_Scheduled_AC_CLResControlMode);
void init_iso20_ac_der_CLReqControlModeType(struct iso20_ac_der_CLReqControlModeType* CLReqControlMode);
void init_iso20_ac_der_CLResControlModeType(struct iso20_ac_der_CLResControlModeType* CLResControlMode);
void init_iso20_ac_der_CanonicalizationMethodType(struct iso20_ac_der_CanonicalizationMethodType* CanonicalizationMethod);
void init_iso20_ac_der_ConstantPowerFactorType(struct iso20_ac_der_ConstantPowerFactorType* ConstantPowerFactorType);
void init_iso20_ac_der_ConstantVarType(struct iso20_ac_der_ConstantVarType* ConstantVarType);
void init_iso20_ac_der_CurveDataPointsListType(struct iso20_ac_der_CurveDataPointsListType* CurveDataPointsListType);
void init_iso20_ac_der_DERControlType(struct iso20_ac_der_DERControlType* DERControlType);
void init_iso20_ac_der_DERCurveType(struct iso20_ac_der_DERCurveType* DERCurveType);
void init_iso20_ac_der_DERGridSupportActiveInfoType(struct iso20_ac_der_DERGridSupportActiveInfoType* DERGridSupportActiveInfoType);
void init_iso20_ac_der_DER_AC_CPDReqEnergyTransferModeType(struct iso20_ac_der_DER_AC_CPDReqEnergyTransferModeType* DER_AC_CPDReqEnergyTransferMode);
void init_iso20_ac_der_DER_AC_CPDResEnergyTransferModeType(struct iso20_ac_der_DER_AC_CPDResEnergyTransferModeType* DER_AC_CPDResEnergyTransferMode);
void init_iso20_ac_der_DER_Dynamic_AC_CLReqControlModeType(struct iso20_ac_der_DER_Dynamic_AC_CLReqControlModeType* DER_Dynamic_AC_CLReqControlMode);
void init_iso20_ac_der_DER_Dynamic_AC_CLResControlModeType(struct iso20_ac_der_DER_Dynamic_AC_CLResControlModeType* DER_Dynamic_AC_CLResControlMode);
void init_iso20_ac_der_DER_Scheduled_AC_CLReqControlModeType(struct iso20_ac_der_DER_Scheduled_AC_CLReqControlModeType* DER_Scheduled_AC_CLReqControlMode);
void init_iso20_ac_der_DER_Scheduled_AC_CLResControlModeType(struct iso20_ac_der_DER_Scheduled_AC_CLResControlModeType* DER_Scheduled_AC_CLResControlMode);
void init_iso20_ac_der_DSAKeyValueType(struct iso20_ac_der_DSAKeyValueType* DSAKeyValue);
void init_iso20_ac_der_DataTupleType(struct iso20_ac_der_DataTupleType* DataTupleType);
void init_iso20_ac_der_DeadBandType(struct iso20_ac_der_DeadBandType* DeadBandType);
void init_iso20_ac_der_DetailedCostType(struct iso20_ac_der_DetailedCostType* DetailedCostType);
void init_iso20_ac_der_DetailedTaxType(struct iso20_ac_der_DetailedTaxType* DetailedTaxType);
void init_iso20_ac_der_DigestMethodType(struct iso20_ac_der_DigestMethodType* DigestMethod);
void init_iso20_ac_der_DisplayParametersType(struct iso20_ac_der_DisplayParametersType* DisplayParametersType);
void init_iso20_ac_der_Dynamic_AC_CLReqControlModeType(struct iso20_ac_der_Dynamic_AC_CLReqControlModeType* Dynamic_AC_CLReqControlMode);
void init_iso20_ac_der_Dynamic_AC_CLResControlModeType(struct iso20_ac_der_Dynamic_AC_CLResControlModeType* Dynamic_AC_CLResControlMode);
void init_iso20_ac_der_EU_FrequencyDroopSettingsType(struct iso20_ac_der_EU_FrequencyDroopSettingsType* EU_FrequencyDroopSettingsType);
void init_iso20_ac_der_EU_FrequencyDroopType(struct iso20_ac_der_EU_FrequencyDroopType* EU_FrequencyDroop);
void init_iso20_ac_der_EVApparentPowerLimitsType(struct iso20_ac_der_EVApparentPowerLimitsType* EVApparentPowerLimitsType);
void init_iso20_ac_der_EVApparentPowerType(struct iso20_ac_der_EVApparentPowerType* EVApparentPowerType);
void init_iso20_ac_der_EVExcitationLimitsType(struct iso20_ac_der_EVExcitationLimitsType* EVExcitationLimitsType);
void init_iso20_ac_der_EVExcitationType(struct iso20_ac_der_EVExcitationType* EVExcitationType);
void init_iso20_ac_der_EVInverterDetailsType(struct iso20_ac_der_EVInverterDetailsType* EVInverterDetailsType);
void init_iso20_ac_der_EVReactivePowerLimitsType(struct iso20_ac_der_EVReactivePowerLimitsType* EVReactivePowerLimitsType);
void init_iso20_ac_der_EVReactivePowerType(struct iso20_ac_der_EVReactivePowerType* EVReactivePowerType);
void init_iso20_ac_der_EVSEStatusType(struct iso20_ac_der_EVSEStatusType* EVSEStatusType);
void init_iso20_ac_der_EVSetPointsType(struct iso20_ac_der_EVSetPointsType* EVSetPointsType);
void init_iso20_ac_der_EnterServiceType(struct iso20_ac_der_EnterServiceType* EnterServiceType);
void init_iso20_ac_der_FaultRideThroughType(struct iso20_ac_der_FaultRideThroughType* FaultRideThroughType);
void init_iso20_ac_der_FrequencyDroopType(struct iso20_ac_der_FrequencyDroopType* FrequencyDroop);
void init_iso20_ac_der_FrequencyTripType(struct iso20_ac_der_FrequencyTripType* FrequencyTripType);
void init_iso20_ac_der_FrequencyWattCurveType(struct iso20_ac_der_FrequencyWattCurveType* FrequencyWattCurveType);
void init_iso20_ac_der_GridLimitsType(struct iso20_ac_der_GridLimitsType* GridLimitsType);
void init_iso20_ac_der_HysteresisControlType(struct iso20_ac_der_HysteresisControlType* HysteresisControlType);
void init_iso20_ac_der_KeyInfoType(struct iso20_ac_der_KeyInfoType* KeyInfo);
void init_iso20_ac_der_KeyValueType(struct iso20_ac_der_KeyValueType* KeyValue);
void init_iso20_ac_der_LimitMaxDischargePowerType(struct iso20_ac_der_LimitMaxDischargePowerType* LimitMaxDischargePowerType);
void init_iso20_ac_der_ManifestType(struct iso20_ac_der_ManifestType* Manifest);
void init_iso20_ac_der_MessageHeaderType(struct iso20_ac_der_MessageHeaderType* MessageHeaderType);
void init_iso20_ac_der_MeterInfoType(struct iso20_ac_der_MeterInfoType* MeterInfoType);
void init_iso20_ac_der_ObjectType(struct iso20_ac_der_ObjectType* Object);
void init_iso20_ac_der_PGPDataType(struct iso20_ac_der_PGPDataType* PGPData);
void init_iso20_ac_der_PhaseType(struct iso20_ac_der_PhaseType* PhaseType);
void init_iso20_ac_der_RSAKeyValueType(struct iso20_ac_der_RSAKeyValueType* RSAKeyValue);
void init_iso20_ac_der_RationalNumberType(struct iso20_ac_der_RationalNumberType* RationalNumberType);
void init_iso20_ac_der_ReactivePowerSupportType(struct iso20_ac_der_ReactivePowerSupportType* ReactivePowerSupportType);
void init_iso20_ac_der_ReceiptType(struct iso20_ac_der_ReceiptType* ReceiptType);
void init_iso20_ac_der_ReferenceType(struct iso20_ac_der_ReferenceType* Reference);
void init_iso20_ac_der_RetrievalMethodType(struct iso20_ac_der_RetrievalMethodType* RetrievalMethod);
void init_iso20_ac_der_SPKIDataType(struct iso20_ac_der_SPKIDataType* SPKIData);
void init_iso20_ac_der_Scheduled_AC_CLReqControlModeType(struct iso20_ac_der_Scheduled_AC_CLReqControlModeType* Scheduled_AC_CLReqControlMode);
void init_iso20_ac_der_Scheduled_AC_CLResControlModeType(struct iso20_ac_der_Scheduled_AC_CLResControlModeType* Scheduled_AC_CLResControlMode);
void init_iso20_ac_der_SignatureMethodType(struct iso20_ac_der_SignatureMethodType* SignatureMethod);
void init_iso20_ac_der_SignaturePropertiesType(struct iso20_ac_der_SignaturePropertiesType* SignatureProperties);
void init_iso20_ac_der_SignaturePropertyType(struct iso20_ac_der_SignaturePropertyType* SignatureProperty);
void init_iso20_ac_der_SignatureType(struct iso20_ac_der_SignatureType* Signature);
void init_iso20_ac_der_SignatureValueType(struct iso20_ac_der_SignatureValueType* SignatureValue);
void init_iso20_ac_der_SignedInfoType(struct iso20_ac_der_SignedInfoType* SignedInfo);
void init_iso20_ac_der_ThreePhaseType(struct iso20_ac_der_ThreePhaseType* ThreePhaseType);
void init_iso20_ac_der_TransformType(struct iso20_ac_der_TransformType* Transform);
void init_iso20_ac_der_TransformsType(struct iso20_ac_der_TransformsType* Transforms);
void init_iso20_ac_der_US_FrequencyDroopSettingsType(struct iso20_ac_der_US_FrequencyDroopSettingsType* US_FrequencyDroopSettingsType);
void init_iso20_ac_der_US_FrequencyDroopType(struct iso20_ac_der_US_FrequencyDroopType* US_FrequencyDroop);
void init_iso20_ac_der_VoltageTripType(struct iso20_ac_der_VoltageTripType* VoltageTripType);
void init_iso20_ac_der_X509DataType(struct iso20_ac_der_X509DataType* X509Data);
void init_iso20_ac_der_X509IssuerSerialType(struct iso20_ac_der_X509IssuerSerialType* X509IssuerSerialType);
void init_iso20_ac_der_exiDocument(struct iso20_ac_der_exiDocument* exiDoc);
void init_iso20_ac_der_exiFragment(struct iso20_ac_der_exiFragment* exiFrag);
void init_iso20_ac_der_xmldsigFragment(struct iso20_ac_der_xmldsigFragment* xmldsigFrag);


#ifdef __cplusplus
}
#endif

#endif /* ISO20_AC_DER_DATATYPES_H */

