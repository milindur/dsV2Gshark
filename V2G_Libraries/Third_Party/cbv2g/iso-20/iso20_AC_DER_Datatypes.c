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
  * @file iso20_AC_DER_Datatypes.c
  * @brief Description goes here
  *
  **/
#include "iso20_AC_DER_Datatypes.h"



// root elements of EXI doc
void init_iso20_ac_der_exiDocument(struct iso20_ac_der_exiDocument* exiDoc) {
    exiDoc->AC_CPDReqEnergyTransferMode_isUsed = 0u;
    exiDoc->AC_CPDResEnergyTransferMode_isUsed = 0u;
    exiDoc->AC_ChargeLoopReq_isUsed = 0u;
    exiDoc->AC_ChargeLoopRes_isUsed = 0u;
    exiDoc->AC_ChargeParameterDiscoveryReq_isUsed = 0u;
    exiDoc->AC_ChargeParameterDiscoveryRes_isUsed = 0u;
    exiDoc->BPT_AC_CPDReqEnergyTransferMode_isUsed = 0u;
    exiDoc->BPT_AC_CPDResEnergyTransferMode_isUsed = 0u;
    exiDoc->BPT_Dynamic_AC_CLReqControlMode_isUsed = 0u;
    exiDoc->BPT_Dynamic_AC_CLResControlMode_isUsed = 0u;
    exiDoc->BPT_Scheduled_AC_CLReqControlMode_isUsed = 0u;
    exiDoc->BPT_Scheduled_AC_CLResControlMode_isUsed = 0u;
    exiDoc->CLReqControlMode_isUsed = 0u;
    exiDoc->CLResControlMode_isUsed = 0u;
    exiDoc->CanonicalizationMethod_isUsed = 0u;
    exiDoc->DER_AC_CPDReqEnergyTransferMode_isUsed = 0u;
    exiDoc->DER_AC_CPDResEnergyTransferMode_isUsed = 0u;
    exiDoc->DER_Dynamic_AC_CLReqControlMode_isUsed = 0u;
    exiDoc->DER_Dynamic_AC_CLResControlMode_isUsed = 0u;
    exiDoc->DER_Scheduled_AC_CLReqControlMode_isUsed = 0u;
    exiDoc->DER_Scheduled_AC_CLResControlMode_isUsed = 0u;
    exiDoc->DSAKeyValue_isUsed = 0u;
    exiDoc->DigestMethod_isUsed = 0u;
    exiDoc->Dynamic_AC_CLReqControlMode_isUsed = 0u;
    exiDoc->Dynamic_AC_CLResControlMode_isUsed = 0u;
    exiDoc->EU_FrequencyDroop_isUsed = 0u;
    exiDoc->FrequencyDroop_isUsed = 0u;
    exiDoc->KeyInfo_isUsed = 0u;
    exiDoc->KeyValue_isUsed = 0u;
    exiDoc->Manifest_isUsed = 0u;
    exiDoc->Object_isUsed = 0u;
    exiDoc->PGPData_isUsed = 0u;
    exiDoc->RSAKeyValue_isUsed = 0u;
    exiDoc->Reference_isUsed = 0u;
    exiDoc->RetrievalMethod_isUsed = 0u;
    exiDoc->SPKIData_isUsed = 0u;
    exiDoc->Scheduled_AC_CLReqControlMode_isUsed = 0u;
    exiDoc->Scheduled_AC_CLResControlMode_isUsed = 0u;
    exiDoc->Signature_isUsed = 0u;
    exiDoc->SignatureMethod_isUsed = 0u;
    exiDoc->SignatureProperties_isUsed = 0u;
    exiDoc->SignatureProperty_isUsed = 0u;
    exiDoc->SignatureValue_isUsed = 0u;
    exiDoc->SignedInfo_isUsed = 0u;
    exiDoc->Transform_isUsed = 0u;
    exiDoc->Transforms_isUsed = 0u;
    exiDoc->US_FrequencyDroop_isUsed = 0u;
    exiDoc->X509Data_isUsed = 0u;
}
void init_iso20_ac_der_DataTupleType(struct iso20_ac_der_DataTupleType* DataTupleType) {
    (void) DataTupleType;
}

void init_iso20_ac_der_CurveDataPointsListType(struct iso20_ac_der_CurveDataPointsListType* CurveDataPointsListType) {
    CurveDataPointsListType->CurveDataPoint.arrayLen = 0u;
}

void init_iso20_ac_der_HysteresisControlType(struct iso20_ac_der_HysteresisControlType* HysteresisControlType) {
    HysteresisControlType->IntentionalDelayFstop_isUsed = 0u;
}

void init_iso20_ac_der_TransformType(struct iso20_ac_der_TransformType* TransformType) {
    TransformType->ANY_isUsed = 0u;
    TransformType->XPath_isUsed = 0u;
}

void init_iso20_ac_der_ConstantPowerFactorType(struct iso20_ac_der_ConstantPowerFactorType* ConstantPowerFactorType) {
    ConstantPowerFactorType->Enable_isUsed = 0u;
    ConstantPowerFactorType->Priority_isUsed = 0u;
}

void init_iso20_ac_der_ConstantVarType(struct iso20_ac_der_ConstantVarType* ConstantVarType) {
    ConstantVarType->Enable_isUsed = 0u;
    ConstantVarType->Priority_isUsed = 0u;
}

void init_iso20_ac_der_DSAKeyValueType(struct iso20_ac_der_DSAKeyValueType* DSAKeyValueType) {
    DSAKeyValueType->P_isUsed = 0u;
    DSAKeyValueType->Q_isUsed = 0u;
    DSAKeyValueType->G_isUsed = 0u;
    DSAKeyValueType->J_isUsed = 0u;
    DSAKeyValueType->Seed_isUsed = 0u;
    DSAKeyValueType->PgenCounter_isUsed = 0u;
}

void init_iso20_ac_der_DeadBandType(struct iso20_ac_der_DeadBandType* DeadBandType) {
    DeadBandType->Low_isUsed = 0u;
    DeadBandType->High_isUsed = 0u;
}

void init_iso20_ac_der_DigestMethodType(struct iso20_ac_der_DigestMethodType* DigestMethodType) {
    DigestMethodType->ANY_isUsed = 0u;
}

void init_iso20_ac_der_FrequencyDroopType(struct iso20_ac_der_FrequencyDroopType* FrequencyDroopType) {
    FrequencyDroopType->Enable_isUsed = 0u;
    FrequencyDroopType->Priority_isUsed = 0u;
    FrequencyDroopType->EU_FrequencyDroop_isUsed = 0u;
    FrequencyDroopType->US_FrequencyDroop_isUsed = 0u;
}

void init_iso20_ac_der_FrequencyWattCurveType(struct iso20_ac_der_FrequencyWattCurveType* FrequencyWattCurveType) {
    FrequencyWattCurveType->Enable_isUsed = 0u;
    FrequencyWattCurveType->Priority_isUsed = 0u;
    FrequencyWattCurveType->OpenLoopResponseTime_isUsed = 0u;
    FrequencyWattCurveType->HysteresisHigh_isUsed = 0u;
    FrequencyWattCurveType->HysteresisLow_isUsed = 0u;
    FrequencyWattCurveType->HysteresisDelay_isUsed = 0u;
    FrequencyWattCurveType->HysteresisGradient_isUsed = 0u;
}

void init_iso20_ac_der_LimitMaxDischargePowerType(struct iso20_ac_der_LimitMaxDischargePowerType* LimitMaxDischargePowerType) {
    LimitMaxDischargePowerType->Enable_isUsed = 0u;
    LimitMaxDischargePowerType->Priority_isUsed = 0u;
    LimitMaxDischargePowerType->PowerMonitoringMustTripCurve_isUsed = 0u;
}

void init_iso20_ac_der_EU_FrequencyDroopSettingsType(struct iso20_ac_der_EU_FrequencyDroopSettingsType* EU_FrequencyDroopSettingsType) {
    EU_FrequencyDroopSettingsType->DeactivationTime_isUsed = 0u;
    EU_FrequencyDroopSettingsType->IntentionalDelayPowerControl_isUsed = 0u;
    EU_FrequencyDroopSettingsType->HysteresisControl_isUsed = 0u;
    EU_FrequencyDroopSettingsType->MaxReactionTime_isUsed = 0u;
}

void init_iso20_ac_der_US_FrequencyDroopSettingsType(struct iso20_ac_der_US_FrequencyDroopSettingsType* US_FrequencyDroopSettingsType) {
    US_FrequencyDroopSettingsType->OpenLoopResponseTime_isUsed = 0u;
}

void init_iso20_ac_der_DERCurveType(struct iso20_ac_der_DERCurveType* DERCurveType) {
    DERCurveType->Enable_isUsed = 0u;
    DERCurveType->Priority_isUsed = 0u;
    DERCurveType->LockInValue_isUsed = 0u;
    DERCurveType->LockOutValue_isUsed = 0u;
    DERCurveType->OpenLoopResponseTime_isUsed = 0u;
    DERCurveType->TimeConstantPT1_isUsed = 0u;
    DERCurveType->IntentionalDelay_isUsed = 0u;
}

void init_iso20_ac_der_RSAKeyValueType(struct iso20_ac_der_RSAKeyValueType* RSAKeyValueType) {
    (void) RSAKeyValueType;
}

void init_iso20_ac_der_TransformsType(struct iso20_ac_der_TransformsType* TransformsType) {
    (void) TransformsType;
}

void init_iso20_ac_der_X509IssuerSerialType(struct iso20_ac_der_X509IssuerSerialType* X509IssuerSerialType) {
    (void) X509IssuerSerialType;
}

void init_iso20_ac_der_ActivePowerSupportType(struct iso20_ac_der_ActivePowerSupportType* ActivePowerSupportType) {
    ActivePowerSupportType->FrequencyWatt_isUsed = 0u;
    ActivePowerSupportType->VoltWatt_isUsed = 0u;
    ActivePowerSupportType->LimitMaxDischargePower_isUsed = 0u;
    ActivePowerSupportType->EU_FrequencyDroop_isUsed = 0u;
    ActivePowerSupportType->FrequencyDroop_isUsed = 0u;
    ActivePowerSupportType->US_FrequencyDroop_isUsed = 0u;
}

void init_iso20_ac_der_CanonicalizationMethodType(struct iso20_ac_der_CanonicalizationMethodType* CanonicalizationMethodType) {
    CanonicalizationMethodType->ANY_isUsed = 0u;
}

void init_iso20_ac_der_EU_FrequencyDroopType(struct iso20_ac_der_EU_FrequencyDroopType* EU_FrequencyDroopType) {
    EU_FrequencyDroopType->Enable_isUsed = 0u;
    EU_FrequencyDroopType->Priority_isUsed = 0u;
    EU_FrequencyDroopType->OverFrequencyDroop_isUsed = 0u;
    EU_FrequencyDroopType->UnderFrequencyDroop_isUsed = 0u;
}

void init_iso20_ac_der_DetailedCostType(struct iso20_ac_der_DetailedCostType* DetailedCostType) {
    (void) DetailedCostType;
}

void init_iso20_ac_der_EnterServiceType(struct iso20_ac_der_EnterServiceType* EnterServiceType) {
    EnterServiceType->PermitService_isUsed = 0u;
    EnterServiceType->EnterServiceGradient_isUsed = 0u;
}

void init_iso20_ac_der_FaultRideThroughType(struct iso20_ac_der_FaultRideThroughType* FaultRideThroughType) {
    FaultRideThroughType->OverVoltageRideThroughPositiveCurveKFactor_isUsed = 0u;
    FaultRideThroughType->OverVoltageRideThroughNegativeCurveKFactor_isUsed = 0u;
    FaultRideThroughType->UnderVoltageRideThroughPositiveCurveKFactor_isUsed = 0u;
    FaultRideThroughType->UnderVoltageRideThroughNegativeCurveKFactor_isUsed = 0u;
    FaultRideThroughType->DeadBand_isUsed = 0u;
}

void init_iso20_ac_der_FrequencyTripType(struct iso20_ac_der_FrequencyTripType* FrequencyTripType) {
    FrequencyTripType->OverFrequencyMayTripCurve_isUsed = 0u;
    FrequencyTripType->UnderFrequencyMayTripCurve_isUsed = 0u;
}

void init_iso20_ac_der_KeyValueType(struct iso20_ac_der_KeyValueType* KeyValueType) {
    KeyValueType->DSAKeyValue_isUsed = 0u;
    KeyValueType->RSAKeyValue_isUsed = 0u;
    KeyValueType->ANY_isUsed = 0u;
}

void init_iso20_ac_der_PGPDataType(struct iso20_ac_der_PGPDataType* PGPDataType) {
    PGPDataType->choice_1_isUsed = 0u;
    PGPDataType->choice_2_isUsed = 0u;
}

void init_iso20_ac_der_ReactivePowerSupportType(struct iso20_ac_der_ReactivePowerSupportType* ReactivePowerSupportType) {
    ReactivePowerSupportType->ConstantPowerFactor_isUsed = 0u;
    ReactivePowerSupportType->VoltVar_isUsed = 0u;
    ReactivePowerSupportType->WattVar_isUsed = 0u;
    ReactivePowerSupportType->ConstantVar_isUsed = 0u;
    ReactivePowerSupportType->WattCosPhi_isUsed = 0u;
}

void init_iso20_ac_der_ReferenceType(struct iso20_ac_der_ReferenceType* ReferenceType) {
    ReferenceType->Id_isUsed = 0u;
    ReferenceType->Type_isUsed = 0u;
    ReferenceType->URI_isUsed = 0u;
    ReferenceType->Transforms_isUsed = 0u;
}

void init_iso20_ac_der_RetrievalMethodType(struct iso20_ac_der_RetrievalMethodType* RetrievalMethodType) {
    RetrievalMethodType->Type_isUsed = 0u;
    RetrievalMethodType->URI_isUsed = 0u;
    RetrievalMethodType->Transforms_isUsed = 0u;
}

void init_iso20_ac_der_SPKIDataType(struct iso20_ac_der_SPKIDataType* SPKIDataType) {
    SPKIDataType->ANY_isUsed = 0u;
}

void init_iso20_ac_der_SignatureMethodType(struct iso20_ac_der_SignatureMethodType* SignatureMethodType) {
    SignatureMethodType->HMACOutputLength_isUsed = 0u;
    SignatureMethodType->ANY_isUsed = 0u;
}

void init_iso20_ac_der_DetailedTaxType(struct iso20_ac_der_DetailedTaxType* DetailedTaxType) {
    (void) DetailedTaxType;
}

void init_iso20_ac_der_ThreePhaseType(struct iso20_ac_der_ThreePhaseType* ThreePhaseType) {
    (void) ThreePhaseType;
}

void init_iso20_ac_der_US_FrequencyDroopType(struct iso20_ac_der_US_FrequencyDroopType* US_FrequencyDroopType) {
    US_FrequencyDroopType->Enable_isUsed = 0u;
    US_FrequencyDroopType->Priority_isUsed = 0u;
    US_FrequencyDroopType->OverFrequencyDroop_isUsed = 0u;
    US_FrequencyDroopType->UnderFrequencyDroop_isUsed = 0u;
}

void init_iso20_ac_der_VoltageTripType(struct iso20_ac_der_VoltageTripType* VoltageTripType) {
    VoltageTripType->OverVoltageMayTripCurve_isUsed = 0u;
    VoltageTripType->UnderVoltageMayTripCurve_isUsed = 0u;
    VoltageTripType->OverVoltageMeanValue10min_isUsed = 0u;
    VoltageTripType->OverVoltage10MinMeanTripDelay_isUsed = 0u;
    VoltageTripType->PowerDuringCessation_isUsed = 0u;
}

void init_iso20_ac_der_X509DataType(struct iso20_ac_der_X509DataType* X509DataType) {
    X509DataType->X509IssuerSerial_isUsed = 0u;
    X509DataType->X509SKI_isUsed = 0u;
    X509DataType->X509SubjectName_isUsed = 0u;
    X509DataType->X509Certificate_isUsed = 0u;
    X509DataType->X509CRL_isUsed = 0u;
    X509DataType->ANY_isUsed = 0u;
}

void init_iso20_ac_der_DERControlType(struct iso20_ac_der_DERControlType* DERControlType) {
    DERControlType->VoltageTrip_isUsed = 0u;
    DERControlType->FrequencyTrip_isUsed = 0u;
    DERControlType->FaultRideThrough_isUsed = 0u;
    DERControlType->EnterService_isUsed = 0u;
    DERControlType->ReactivePowerSupport_isUsed = 0u;
    DERControlType->ActivePowerSupport_isUsed = 0u;
    DERControlType->MaximumLevel1DCInjection_isUsed = 0u;
    DERControlType->MaximumLevel2DCInjection_isUsed = 0u;
    DERControlType->SCRatPOC_isUsed = 0u;
}

void init_iso20_ac_der_DERGridSupportActiveInfoType(struct iso20_ac_der_DERGridSupportActiveInfoType* DERGridSupportActiveInfoType) {
    DERGridSupportActiveInfoType->DERFunctionName_isUsed = 0u;
    DERGridSupportActiveInfoType->GridEventFault_isUsed = 0u;
    DERGridSupportActiveInfoType->ExtraInfo_isUsed = 0u;
}

void init_iso20_ac_der_DisplayParametersType(struct iso20_ac_der_DisplayParametersType* DisplayParametersType) {
    DisplayParametersType->PresentSOC_isUsed = 0u;
    DisplayParametersType->MinimumSOC_isUsed = 0u;
    DisplayParametersType->TargetSOC_isUsed = 0u;
    DisplayParametersType->MaximumSOC_isUsed = 0u;
    DisplayParametersType->RemainingTimeToMinimumSOC_isUsed = 0u;
    DisplayParametersType->RemainingTimeToTargetSOC_isUsed = 0u;
    DisplayParametersType->RemainingTimeToMaximumSOC_isUsed = 0u;
    DisplayParametersType->ChargingComplete_isUsed = 0u;
    DisplayParametersType->BatteryEnergyCapacity_isUsed = 0u;
    DisplayParametersType->InletHot_isUsed = 0u;
}

void init_iso20_ac_der_EVApparentPowerType(struct iso20_ac_der_EVApparentPowerType* EVApparentPowerType) {
    EVApparentPowerType->EVMaximumChargeApparentPower_isUsed = 0u;
    EVApparentPowerType->EVMaximumDischargeApparentPower_isUsed = 0u;
}

void init_iso20_ac_der_EVApparentPowerLimitsType(struct iso20_ac_der_EVApparentPowerLimitsType* EVApparentPowerLimitsType) {
    EVApparentPowerLimitsType->EVMaximumChargeApparentPower_isUsed = 0u;
    EVApparentPowerLimitsType->EVMaximumDischargeApparentPower_isUsed = 0u;
    EVApparentPowerLimitsType->EVMaximumApparentPower_isUsed = 0u;
}

void init_iso20_ac_der_EVExcitationType(struct iso20_ac_der_EVExcitationType* EVExcitationType) {
    EVExcitationType->EVOverExcitedMaximumDischargePower_isUsed = 0u;
    EVExcitationType->EVOverExcitedPowerFactor_isUsed = 0u;
    EVExcitationType->EVUnderExcitedMaximumDischargePower_isUsed = 0u;
    EVExcitationType->EVUnderExcitedPowerFactor_isUsed = 0u;
}

void init_iso20_ac_der_EVExcitationLimitsType(struct iso20_ac_der_EVExcitationLimitsType* EVExcitationLimitsType) {
    EVExcitationLimitsType->EVOverExcitedMaximumPowerFactor_isUsed = 0u;
    EVExcitationLimitsType->EVOverExcitedMaximumDischargePower_isUsed = 0u;
    EVExcitationLimitsType->EVUnderExcitedMaximumPowerFactor_isUsed = 0u;
    EVExcitationLimitsType->EVUnderExcitedMaximumDischargePower_isUsed = 0u;
}

void init_iso20_ac_der_EVInverterDetailsType(struct iso20_ac_der_EVInverterDetailsType* EVInverterDetailsType) {
    EVInverterDetailsType->EVInverterSwVersion_isUsed = 0u;
    EVInverterDetailsType->EVInverterHwVersion_isUsed = 0u;
    EVInverterDetailsType->EVInverterManufacturer_isUsed = 0u;
    EVInverterDetailsType->EVInverterModel_isUsed = 0u;
    EVInverterDetailsType->EVInverterSerialNumber_isUsed = 0u;
}

void init_iso20_ac_der_RationalNumberType(struct iso20_ac_der_RationalNumberType* RationalNumberType) {
    (void) RationalNumberType;
}

void init_iso20_ac_der_PhaseType(struct iso20_ac_der_PhaseType* PhaseType) {
    PhaseType->AnyPhase_isUsed = 0u;
    PhaseType->ThreePhase_isUsed = 0u;
}

void init_iso20_ac_der_EVReactivePowerType(struct iso20_ac_der_EVReactivePowerType* EVReactivePowerType) {
    EVReactivePowerType->EVMaximumChargeReactivePower_isUsed = 0u;
    EVReactivePowerType->EVMinimumChargeReactivePower_isUsed = 0u;
    EVReactivePowerType->EVMaximumDischargeReactivePower_isUsed = 0u;
    EVReactivePowerType->EVMinimumDischargeReactivePower_isUsed = 0u;
}

void init_iso20_ac_der_EVReactivePowerLimitsType(struct iso20_ac_der_EVReactivePowerLimitsType* EVReactivePowerLimitsType) {
    EVReactivePowerLimitsType->EVMaximumChargeReactivePower_isUsed = 0u;
    EVReactivePowerLimitsType->EVMinimumChargeReactivePower_isUsed = 0u;
    EVReactivePowerLimitsType->EVMaximumDischargeReactivePower_isUsed = 0u;
    EVReactivePowerLimitsType->EVMinimumDischargeReactivePower_isUsed = 0u;
    EVReactivePowerLimitsType->EVReactiveSusceptance_isUsed = 0u;
}

void init_iso20_ac_der_EVSEStatusType(struct iso20_ac_der_EVSEStatusType* EVSEStatusType) {
    (void) EVSEStatusType;
}

void init_iso20_ac_der_EVSetPointsType(struct iso20_ac_der_EVSetPointsType* EVSetPointsType) {
    EVSetPointsType->EVSetNominalVoltage_isUsed = 0u;
    EVSetPointsType->EVSetNominalVoltageOffset_isUsed = 0u;
    EVSetPointsType->EVSetMaximumNominalVoltage_isUsed = 0u;
    EVSetPointsType->EVSetMinimumNominalVoltage_isUsed = 0u;
}

void init_iso20_ac_der_GridLimitsType(struct iso20_ac_der_GridLimitsType* GridLimitsType) {
    GridLimitsType->GridNominalVoltageOffset_isUsed = 0u;
    GridLimitsType->GridMinFrequency_isUsed = 0u;
    GridLimitsType->GridMaxFrequency_isUsed = 0u;
    GridLimitsType->GridMaximumVoltage_isUsed = 0u;
    GridLimitsType->GridMinimumVoltage_isUsed = 0u;
}

void init_iso20_ac_der_MessageHeaderType(struct iso20_ac_der_MessageHeaderType* MessageHeaderType) {
    MessageHeaderType->Signature_isUsed = 0u;
}

void init_iso20_ac_der_KeyInfoType(struct iso20_ac_der_KeyInfoType* KeyInfoType) {
    KeyInfoType->Id_isUsed = 0u;
    KeyInfoType->KeyName_isUsed = 0u;
    KeyInfoType->KeyValue_isUsed = 0u;
    KeyInfoType->RetrievalMethod_isUsed = 0u;
    KeyInfoType->X509Data_isUsed = 0u;
    KeyInfoType->PGPData_isUsed = 0u;
    KeyInfoType->SPKIData_isUsed = 0u;
    KeyInfoType->MgmtData_isUsed = 0u;
    KeyInfoType->ANY_isUsed = 0u;
}

void init_iso20_ac_der_MeterInfoType(struct iso20_ac_der_MeterInfoType* MeterInfoType) {
    MeterInfoType->BPT_DischargedEnergyReadingWh_isUsed = 0u;
    MeterInfoType->CapacitiveEnergyReadingVARh_isUsed = 0u;
    MeterInfoType->BPT_InductiveEnergyReadingVARh_isUsed = 0u;
    MeterInfoType->MeterSignature_isUsed = 0u;
    MeterInfoType->MeterStatus_isUsed = 0u;
    MeterInfoType->MeterTimestamp_isUsed = 0u;
}

void init_iso20_ac_der_ObjectType(struct iso20_ac_der_ObjectType* ObjectType) {
    ObjectType->Encoding_isUsed = 0u;
    ObjectType->Id_isUsed = 0u;
    ObjectType->MimeType_isUsed = 0u;
    ObjectType->ANY_isUsed = 0u;
}

void init_iso20_ac_der_ReceiptType(struct iso20_ac_der_ReceiptType* ReceiptType) {
    ReceiptType->TaxCosts.arrayLen = 0u;
    ReceiptType->EnergyCosts_isUsed = 0u;
    ReceiptType->OccupancyCosts_isUsed = 0u;
    ReceiptType->AdditionalServicesCosts_isUsed = 0u;
    ReceiptType->OverstayCosts_isUsed = 0u;
}

void init_iso20_ac_der_SignaturePropertyType(struct iso20_ac_der_SignaturePropertyType* SignaturePropertyType) {
    SignaturePropertyType->Id_isUsed = 0u;
    SignaturePropertyType->ANY_isUsed = 0u;
}

void init_iso20_ac_der_SignatureValueType(struct iso20_ac_der_SignatureValueType* SignatureValueType) {
    SignatureValueType->Id_isUsed = 0u;
}

void init_iso20_ac_der_SignedInfoType(struct iso20_ac_der_SignedInfoType* SignedInfoType) {
    SignedInfoType->Reference.arrayLen = 0u;
    SignedInfoType->Id_isUsed = 0u;
}

void init_iso20_ac_der_AC_CPDReqEnergyTransferModeType(struct iso20_ac_der_AC_CPDReqEnergyTransferModeType* AC_CPDReqEnergyTransferModeType) {
    AC_CPDReqEnergyTransferModeType->EVMaximumChargePower_L2_isUsed = 0u;
    AC_CPDReqEnergyTransferModeType->EVMaximumChargePower_L3_isUsed = 0u;
    AC_CPDReqEnergyTransferModeType->EVMinimumChargePower_L2_isUsed = 0u;
    AC_CPDReqEnergyTransferModeType->EVMinimumChargePower_L3_isUsed = 0u;
}

void init_iso20_ac_der_AC_CPDResEnergyTransferModeType(struct iso20_ac_der_AC_CPDResEnergyTransferModeType* AC_CPDResEnergyTransferModeType) {
    AC_CPDResEnergyTransferModeType->EVSEMaximumChargePower_L2_isUsed = 0u;
    AC_CPDResEnergyTransferModeType->EVSEMaximumChargePower_L3_isUsed = 0u;
    AC_CPDResEnergyTransferModeType->EVSEMinimumChargePower_L2_isUsed = 0u;
    AC_CPDResEnergyTransferModeType->EVSEMinimumChargePower_L3_isUsed = 0u;
    AC_CPDResEnergyTransferModeType->MaximumPowerAsymmetry_isUsed = 0u;
    AC_CPDResEnergyTransferModeType->EVSEPowerRampLimitation_isUsed = 0u;
    AC_CPDResEnergyTransferModeType->EVSEPresentActivePower_isUsed = 0u;
    AC_CPDResEnergyTransferModeType->EVSEPresentActivePower_L2_isUsed = 0u;
    AC_CPDResEnergyTransferModeType->EVSEPresentActivePower_L3_isUsed = 0u;
}

void init_iso20_ac_der_AC_ChargeLoopReqType(struct iso20_ac_der_AC_ChargeLoopReqType* AC_ChargeLoopReqType) {
    AC_ChargeLoopReqType->DisplayParameters_isUsed = 0u;
    AC_ChargeLoopReqType->BPT_Dynamic_AC_CLReqControlMode_isUsed = 0u;
    AC_ChargeLoopReqType->BPT_Scheduled_AC_CLReqControlMode_isUsed = 0u;
    AC_ChargeLoopReqType->CLReqControlMode_isUsed = 0u;
    AC_ChargeLoopReqType->DER_Dynamic_AC_CLReqControlMode_isUsed = 0u;
    AC_ChargeLoopReqType->DER_Scheduled_AC_CLReqControlMode_isUsed = 0u;
    AC_ChargeLoopReqType->Dynamic_AC_CLReqControlMode_isUsed = 0u;
    AC_ChargeLoopReqType->Scheduled_AC_CLReqControlMode_isUsed = 0u;
}

void init_iso20_ac_der_AC_ChargeLoopResType(struct iso20_ac_der_AC_ChargeLoopResType* AC_ChargeLoopResType) {
    AC_ChargeLoopResType->EVSEStatus_isUsed = 0u;
    AC_ChargeLoopResType->MeterInfo_isUsed = 0u;
    AC_ChargeLoopResType->Receipt_isUsed = 0u;
    AC_ChargeLoopResType->EVSETargetFrequency_isUsed = 0u;
    AC_ChargeLoopResType->BPT_Dynamic_AC_CLResControlMode_isUsed = 0u;
    AC_ChargeLoopResType->BPT_Scheduled_AC_CLResControlMode_isUsed = 0u;
    AC_ChargeLoopResType->CLResControlMode_isUsed = 0u;
    AC_ChargeLoopResType->DER_Dynamic_AC_CLResControlMode_isUsed = 0u;
    AC_ChargeLoopResType->DER_Scheduled_AC_CLResControlMode_isUsed = 0u;
    AC_ChargeLoopResType->Dynamic_AC_CLResControlMode_isUsed = 0u;
    AC_ChargeLoopResType->Scheduled_AC_CLResControlMode_isUsed = 0u;
}

void init_iso20_ac_der_AC_ChargeParameterDiscoveryReqType(struct iso20_ac_der_AC_ChargeParameterDiscoveryReqType* AC_ChargeParameterDiscoveryReqType) {
    AC_ChargeParameterDiscoveryReqType->AC_CPDReqEnergyTransferMode_isUsed = 0u;
    AC_ChargeParameterDiscoveryReqType->BPT_AC_CPDReqEnergyTransferMode_isUsed = 0u;
    AC_ChargeParameterDiscoveryReqType->DER_AC_CPDReqEnergyTransferMode_isUsed = 0u;
}

void init_iso20_ac_der_AC_ChargeParameterDiscoveryResType(struct iso20_ac_der_AC_ChargeParameterDiscoveryResType* AC_ChargeParameterDiscoveryResType) {
    AC_ChargeParameterDiscoveryResType->AC_CPDResEnergyTransferMode_isUsed = 0u;
    AC_ChargeParameterDiscoveryResType->BPT_AC_CPDResEnergyTransferMode_isUsed = 0u;
    AC_ChargeParameterDiscoveryResType->DER_AC_CPDResEnergyTransferMode_isUsed = 0u;
}

void init_iso20_ac_der_BPT_AC_CPDReqEnergyTransferModeType(struct iso20_ac_der_BPT_AC_CPDReqEnergyTransferModeType* BPT_AC_CPDReqEnergyTransferModeType) {
    BPT_AC_CPDReqEnergyTransferModeType->EVMaximumChargePower_L2_isUsed = 0u;
    BPT_AC_CPDReqEnergyTransferModeType->EVMaximumChargePower_L3_isUsed = 0u;
    BPT_AC_CPDReqEnergyTransferModeType->EVMinimumChargePower_L2_isUsed = 0u;
    BPT_AC_CPDReqEnergyTransferModeType->EVMinimumChargePower_L3_isUsed = 0u;
    BPT_AC_CPDReqEnergyTransferModeType->EVMaximumDischargePower_L2_isUsed = 0u;
    BPT_AC_CPDReqEnergyTransferModeType->EVMaximumDischargePower_L3_isUsed = 0u;
    BPT_AC_CPDReqEnergyTransferModeType->EVMinimumDischargePower_L2_isUsed = 0u;
    BPT_AC_CPDReqEnergyTransferModeType->EVMinimumDischargePower_L3_isUsed = 0u;
}

void init_iso20_ac_der_BPT_AC_CPDResEnergyTransferModeType(struct iso20_ac_der_BPT_AC_CPDResEnergyTransferModeType* BPT_AC_CPDResEnergyTransferModeType) {
    BPT_AC_CPDResEnergyTransferModeType->EVSEMaximumChargePower_L2_isUsed = 0u;
    BPT_AC_CPDResEnergyTransferModeType->EVSEMaximumChargePower_L3_isUsed = 0u;
    BPT_AC_CPDResEnergyTransferModeType->EVSEMinimumChargePower_L2_isUsed = 0u;
    BPT_AC_CPDResEnergyTransferModeType->EVSEMinimumChargePower_L3_isUsed = 0u;
    BPT_AC_CPDResEnergyTransferModeType->MaximumPowerAsymmetry_isUsed = 0u;
    BPT_AC_CPDResEnergyTransferModeType->EVSEPowerRampLimitation_isUsed = 0u;
    BPT_AC_CPDResEnergyTransferModeType->EVSEPresentActivePower_isUsed = 0u;
    BPT_AC_CPDResEnergyTransferModeType->EVSEPresentActivePower_L2_isUsed = 0u;
    BPT_AC_CPDResEnergyTransferModeType->EVSEPresentActivePower_L3_isUsed = 0u;
    BPT_AC_CPDResEnergyTransferModeType->EVSEMaximumDischargePower_L2_isUsed = 0u;
    BPT_AC_CPDResEnergyTransferModeType->EVSEMaximumDischargePower_L3_isUsed = 0u;
    BPT_AC_CPDResEnergyTransferModeType->EVSEMinimumDischargePower_L2_isUsed = 0u;
    BPT_AC_CPDResEnergyTransferModeType->EVSEMinimumDischargePower_L3_isUsed = 0u;
}

void init_iso20_ac_der_BPT_Dynamic_AC_CLReqControlModeType(struct iso20_ac_der_BPT_Dynamic_AC_CLReqControlModeType* BPT_Dynamic_AC_CLReqControlModeType) {
    BPT_Dynamic_AC_CLReqControlModeType->DepartureTime_isUsed = 0u;
    BPT_Dynamic_AC_CLReqControlModeType->EVMaximumChargePower_L2_isUsed = 0u;
    BPT_Dynamic_AC_CLReqControlModeType->EVMaximumChargePower_L3_isUsed = 0u;
    BPT_Dynamic_AC_CLReqControlModeType->EVMinimumChargePower_L2_isUsed = 0u;
    BPT_Dynamic_AC_CLReqControlModeType->EVMinimumChargePower_L3_isUsed = 0u;
    BPT_Dynamic_AC_CLReqControlModeType->EVPresentActivePower_L2_isUsed = 0u;
    BPT_Dynamic_AC_CLReqControlModeType->EVPresentActivePower_L3_isUsed = 0u;
    BPT_Dynamic_AC_CLReqControlModeType->EVPresentReactivePower_L2_isUsed = 0u;
    BPT_Dynamic_AC_CLReqControlModeType->EVPresentReactivePower_L3_isUsed = 0u;
    BPT_Dynamic_AC_CLReqControlModeType->EVMaximumDischargePower_L2_isUsed = 0u;
    BPT_Dynamic_AC_CLReqControlModeType->EVMaximumDischargePower_L3_isUsed = 0u;
    BPT_Dynamic_AC_CLReqControlModeType->EVMinimumDischargePower_L2_isUsed = 0u;
    BPT_Dynamic_AC_CLReqControlModeType->EVMinimumDischargePower_L3_isUsed = 0u;
    BPT_Dynamic_AC_CLReqControlModeType->EVMaximumV2XEnergyRequest_isUsed = 0u;
    BPT_Dynamic_AC_CLReqControlModeType->EVMinimumV2XEnergyRequest_isUsed = 0u;
}

void init_iso20_ac_der_BPT_Dynamic_AC_CLResControlModeType(struct iso20_ac_der_BPT_Dynamic_AC_CLResControlModeType* BPT_Dynamic_AC_CLResControlModeType) {
    BPT_Dynamic_AC_CLResControlModeType->DepartureTime_isUsed = 0u;
    BPT_Dynamic_AC_CLResControlModeType->MinimumSOC_isUsed = 0u;
    BPT_Dynamic_AC_CLResControlModeType->TargetSOC_isUsed = 0u;
    BPT_Dynamic_AC_CLResControlModeType->AckMaxDelay_isUsed = 0u;
    BPT_Dynamic_AC_CLResControlModeType->EVSETargetActivePower_L2_isUsed = 0u;
    BPT_Dynamic_AC_CLResControlModeType->EVSETargetActivePower_L3_isUsed = 0u;
    BPT_Dynamic_AC_CLResControlModeType->EVSETargetReactivePower_isUsed = 0u;
    BPT_Dynamic_AC_CLResControlModeType->EVSETargetReactivePower_L2_isUsed = 0u;
    BPT_Dynamic_AC_CLResControlModeType->EVSETargetReactivePower_L3_isUsed = 0u;
    BPT_Dynamic_AC_CLResControlModeType->EVSEPresentActivePower_isUsed = 0u;
    BPT_Dynamic_AC_CLResControlModeType->EVSEPresentActivePower_L2_isUsed = 0u;
    BPT_Dynamic_AC_CLResControlModeType->EVSEPresentActivePower_L3_isUsed = 0u;
}

void init_iso20_ac_der_BPT_Scheduled_AC_CLReqControlModeType(struct iso20_ac_der_BPT_Scheduled_AC_CLReqControlModeType* BPT_Scheduled_AC_CLReqControlModeType) {
    BPT_Scheduled_AC_CLReqControlModeType->EVTargetEnergyRequest_isUsed = 0u;
    BPT_Scheduled_AC_CLReqControlModeType->EVMaximumEnergyRequest_isUsed = 0u;
    BPT_Scheduled_AC_CLReqControlModeType->EVMinimumEnergyRequest_isUsed = 0u;
    BPT_Scheduled_AC_CLReqControlModeType->EVMaximumChargePower_isUsed = 0u;
    BPT_Scheduled_AC_CLReqControlModeType->EVMaximumChargePower_L2_isUsed = 0u;
    BPT_Scheduled_AC_CLReqControlModeType->EVMaximumChargePower_L3_isUsed = 0u;
    BPT_Scheduled_AC_CLReqControlModeType->EVMinimumChargePower_isUsed = 0u;
    BPT_Scheduled_AC_CLReqControlModeType->EVMinimumChargePower_L2_isUsed = 0u;
    BPT_Scheduled_AC_CLReqControlModeType->EVMinimumChargePower_L3_isUsed = 0u;
    BPT_Scheduled_AC_CLReqControlModeType->EVPresentActivePower_L2_isUsed = 0u;
    BPT_Scheduled_AC_CLReqControlModeType->EVPresentActivePower_L3_isUsed = 0u;
    BPT_Scheduled_AC_CLReqControlModeType->EVPresentReactivePower_isUsed = 0u;
    BPT_Scheduled_AC_CLReqControlModeType->EVPresentReactivePower_L2_isUsed = 0u;
    BPT_Scheduled_AC_CLReqControlModeType->EVPresentReactivePower_L3_isUsed = 0u;
    BPT_Scheduled_AC_CLReqControlModeType->EVMaximumDischargePower_isUsed = 0u;
    BPT_Scheduled_AC_CLReqControlModeType->EVMaximumDischargePower_L2_isUsed = 0u;
    BPT_Scheduled_AC_CLReqControlModeType->EVMaximumDischargePower_L3_isUsed = 0u;
    BPT_Scheduled_AC_CLReqControlModeType->EVMinimumDischargePower_isUsed = 0u;
    BPT_Scheduled_AC_CLReqControlModeType->EVMinimumDischargePower_L2_isUsed = 0u;
    BPT_Scheduled_AC_CLReqControlModeType->EVMinimumDischargePower_L3_isUsed = 0u;
}

void init_iso20_ac_der_BPT_Scheduled_AC_CLResControlModeType(struct iso20_ac_der_BPT_Scheduled_AC_CLResControlModeType* BPT_Scheduled_AC_CLResControlModeType) {
    BPT_Scheduled_AC_CLResControlModeType->EVSETargetActivePower_isUsed = 0u;
    BPT_Scheduled_AC_CLResControlModeType->EVSETargetActivePower_L2_isUsed = 0u;
    BPT_Scheduled_AC_CLResControlModeType->EVSETargetActivePower_L3_isUsed = 0u;
    BPT_Scheduled_AC_CLResControlModeType->EVSETargetReactivePower_isUsed = 0u;
    BPT_Scheduled_AC_CLResControlModeType->EVSETargetReactivePower_L2_isUsed = 0u;
    BPT_Scheduled_AC_CLResControlModeType->EVSETargetReactivePower_L3_isUsed = 0u;
    BPT_Scheduled_AC_CLResControlModeType->EVSEPresentActivePower_isUsed = 0u;
    BPT_Scheduled_AC_CLResControlModeType->EVSEPresentActivePower_L2_isUsed = 0u;
    BPT_Scheduled_AC_CLResControlModeType->EVSEPresentActivePower_L3_isUsed = 0u;
}

void init_iso20_ac_der_CLReqControlModeType(struct iso20_ac_der_CLReqControlModeType* CLReqControlModeType) {
    (void) CLReqControlModeType;
}

void init_iso20_ac_der_CLResControlModeType(struct iso20_ac_der_CLResControlModeType* CLResControlModeType) {
    (void) CLResControlModeType;
}

void init_iso20_ac_der_DER_AC_CPDReqEnergyTransferModeType(struct iso20_ac_der_DER_AC_CPDReqEnergyTransferModeType* DER_AC_CPDReqEnergyTransferModeType) {
    DER_AC_CPDReqEnergyTransferModeType->EVMaximumChargePower_L2_isUsed = 0u;
    DER_AC_CPDReqEnergyTransferModeType->EVMaximumChargePower_L3_isUsed = 0u;
    DER_AC_CPDReqEnergyTransferModeType->EVMinimumChargePower_L2_isUsed = 0u;
    DER_AC_CPDReqEnergyTransferModeType->EVMinimumChargePower_L3_isUsed = 0u;
    DER_AC_CPDReqEnergyTransferModeType->EVSessionTotalDischargeEnergyAvailable_isUsed = 0u;
    DER_AC_CPDReqEnergyTransferModeType->EVApparentPowerLimits_isUsed = 0u;
    DER_AC_CPDReqEnergyTransferModeType->EVReactivePowerLimits_isUsed = 0u;
    DER_AC_CPDReqEnergyTransferModeType->EVExcitationLimits_isUsed = 0u;
    DER_AC_CPDReqEnergyTransferModeType->EVInverterDetails_isUsed = 0u;
}

void init_iso20_ac_der_DER_AC_CPDResEnergyTransferModeType(struct iso20_ac_der_DER_AC_CPDResEnergyTransferModeType* DER_AC_CPDResEnergyTransferModeType) {
    DER_AC_CPDResEnergyTransferModeType->EVSEMaximumChargePower_L2_isUsed = 0u;
    DER_AC_CPDResEnergyTransferModeType->EVSEMaximumChargePower_L3_isUsed = 0u;
    DER_AC_CPDResEnergyTransferModeType->EVSEMinimumChargePower_L2_isUsed = 0u;
    DER_AC_CPDResEnergyTransferModeType->EVSEMinimumChargePower_L3_isUsed = 0u;
    DER_AC_CPDResEnergyTransferModeType->MaximumPowerAsymmetry_isUsed = 0u;
    DER_AC_CPDResEnergyTransferModeType->EVSEPowerRampLimitation_isUsed = 0u;
    DER_AC_CPDResEnergyTransferModeType->EVSEPresentActivePower_isUsed = 0u;
    DER_AC_CPDResEnergyTransferModeType->EVSEPresentActivePower_L2_isUsed = 0u;
    DER_AC_CPDResEnergyTransferModeType->EVSEPresentActivePower_L3_isUsed = 0u;
    DER_AC_CPDResEnergyTransferModeType->EVSEStatus_isUsed = 0u;
    DER_AC_CPDResEnergyTransferModeType->EVSEMaximumDischargePower_isUsed = 0u;
    DER_AC_CPDResEnergyTransferModeType->EVSEMaximumChargeReactivePower_isUsed = 0u;
    DER_AC_CPDResEnergyTransferModeType->EVSEMaximumDischargeReactivePower_isUsed = 0u;
}

void init_iso20_ac_der_DER_Dynamic_AC_CLReqControlModeType(struct iso20_ac_der_DER_Dynamic_AC_CLReqControlModeType* DER_Dynamic_AC_CLReqControlModeType) {
    DER_Dynamic_AC_CLReqControlModeType->DepartureTime_isUsed = 0u;
    DER_Dynamic_AC_CLReqControlModeType->EVMaximumChargePower_L2_isUsed = 0u;
    DER_Dynamic_AC_CLReqControlModeType->EVMaximumChargePower_L3_isUsed = 0u;
    DER_Dynamic_AC_CLReqControlModeType->EVMinimumChargePower_L2_isUsed = 0u;
    DER_Dynamic_AC_CLReqControlModeType->EVMinimumChargePower_L3_isUsed = 0u;
    DER_Dynamic_AC_CLReqControlModeType->EVPresentActivePower_L2_isUsed = 0u;
    DER_Dynamic_AC_CLReqControlModeType->EVPresentActivePower_L3_isUsed = 0u;
    DER_Dynamic_AC_CLReqControlModeType->EVPresentReactivePower_L2_isUsed = 0u;
    DER_Dynamic_AC_CLReqControlModeType->EVPresentReactivePower_L3_isUsed = 0u;
    DER_Dynamic_AC_CLReqControlModeType->EVSessionTotalDischargeEnergyAvailable_isUsed = 0u;
    DER_Dynamic_AC_CLReqControlModeType->EVApparentPower_isUsed = 0u;
    DER_Dynamic_AC_CLReqControlModeType->EVReactivePower_isUsed = 0u;
    DER_Dynamic_AC_CLReqControlModeType->EVExcitation_isUsed = 0u;
    DER_Dynamic_AC_CLReqControlModeType->EVSetPoints_isUsed = 0u;
    DER_Dynamic_AC_CLReqControlModeType->EVPresentVoltage_isUsed = 0u;
    DER_Dynamic_AC_CLReqControlModeType->EVPresentFrequency_isUsed = 0u;
    DER_Dynamic_AC_CLReqControlModeType->DERGridSupportActiveInfo_isUsed = 0u;
}

void init_iso20_ac_der_DER_Dynamic_AC_CLResControlModeType(struct iso20_ac_der_DER_Dynamic_AC_CLResControlModeType* DER_Dynamic_AC_CLResControlModeType) {
    DER_Dynamic_AC_CLResControlModeType->DepartureTime_isUsed = 0u;
    DER_Dynamic_AC_CLResControlModeType->MinimumSOC_isUsed = 0u;
    DER_Dynamic_AC_CLResControlModeType->TargetSOC_isUsed = 0u;
    DER_Dynamic_AC_CLResControlModeType->AckMaxDelay_isUsed = 0u;
    DER_Dynamic_AC_CLResControlModeType->EVSETargetActivePower_L2_isUsed = 0u;
    DER_Dynamic_AC_CLResControlModeType->EVSETargetActivePower_L3_isUsed = 0u;
    DER_Dynamic_AC_CLResControlModeType->EVSETargetReactivePower_isUsed = 0u;
    DER_Dynamic_AC_CLResControlModeType->EVSETargetReactivePower_L2_isUsed = 0u;
    DER_Dynamic_AC_CLResControlModeType->EVSETargetReactivePower_L3_isUsed = 0u;
    DER_Dynamic_AC_CLResControlModeType->EVSEPresentActivePower_isUsed = 0u;
    DER_Dynamic_AC_CLResControlModeType->EVSEPresentActivePower_L2_isUsed = 0u;
    DER_Dynamic_AC_CLResControlModeType->EVSEPresentActivePower_L3_isUsed = 0u;
    DER_Dynamic_AC_CLResControlModeType->DERControl_isUsed = 0u;
}

void init_iso20_ac_der_DER_Scheduled_AC_CLReqControlModeType(struct iso20_ac_der_DER_Scheduled_AC_CLReqControlModeType* DER_Scheduled_AC_CLReqControlModeType) {
    DER_Scheduled_AC_CLReqControlModeType->EVTargetEnergyRequest_isUsed = 0u;
    DER_Scheduled_AC_CLReqControlModeType->EVMaximumEnergyRequest_isUsed = 0u;
    DER_Scheduled_AC_CLReqControlModeType->EVMinimumEnergyRequest_isUsed = 0u;
    DER_Scheduled_AC_CLReqControlModeType->EVMaximumChargePower_isUsed = 0u;
    DER_Scheduled_AC_CLReqControlModeType->EVMaximumChargePower_L2_isUsed = 0u;
    DER_Scheduled_AC_CLReqControlModeType->EVMaximumChargePower_L3_isUsed = 0u;
    DER_Scheduled_AC_CLReqControlModeType->EVMinimumChargePower_isUsed = 0u;
    DER_Scheduled_AC_CLReqControlModeType->EVMinimumChargePower_L2_isUsed = 0u;
    DER_Scheduled_AC_CLReqControlModeType->EVMinimumChargePower_L3_isUsed = 0u;
    DER_Scheduled_AC_CLReqControlModeType->EVPresentActivePower_L2_isUsed = 0u;
    DER_Scheduled_AC_CLReqControlModeType->EVPresentActivePower_L3_isUsed = 0u;
    DER_Scheduled_AC_CLReqControlModeType->EVPresentReactivePower_isUsed = 0u;
    DER_Scheduled_AC_CLReqControlModeType->EVPresentReactivePower_L2_isUsed = 0u;
    DER_Scheduled_AC_CLReqControlModeType->EVPresentReactivePower_L3_isUsed = 0u;
    DER_Scheduled_AC_CLReqControlModeType->EVSessionTotalDischargeEnergyAvailable_isUsed = 0u;
    DER_Scheduled_AC_CLReqControlModeType->EVApparentPower_isUsed = 0u;
    DER_Scheduled_AC_CLReqControlModeType->EVReactivePower_isUsed = 0u;
    DER_Scheduled_AC_CLReqControlModeType->EVExcitation_isUsed = 0u;
    DER_Scheduled_AC_CLReqControlModeType->EVSetPoints_isUsed = 0u;
    DER_Scheduled_AC_CLReqControlModeType->EVPresentVoltage_isUsed = 0u;
    DER_Scheduled_AC_CLReqControlModeType->EVPresentFrequency_isUsed = 0u;
    DER_Scheduled_AC_CLReqControlModeType->DERGridSupportActiveInfo_isUsed = 0u;
}

void init_iso20_ac_der_DER_Scheduled_AC_CLResControlModeType(struct iso20_ac_der_DER_Scheduled_AC_CLResControlModeType* DER_Scheduled_AC_CLResControlModeType) {
    DER_Scheduled_AC_CLResControlModeType->EVSETargetActivePower_isUsed = 0u;
    DER_Scheduled_AC_CLResControlModeType->EVSETargetActivePower_L2_isUsed = 0u;
    DER_Scheduled_AC_CLResControlModeType->EVSETargetActivePower_L3_isUsed = 0u;
    DER_Scheduled_AC_CLResControlModeType->EVSETargetReactivePower_isUsed = 0u;
    DER_Scheduled_AC_CLResControlModeType->EVSETargetReactivePower_L2_isUsed = 0u;
    DER_Scheduled_AC_CLResControlModeType->EVSETargetReactivePower_L3_isUsed = 0u;
    DER_Scheduled_AC_CLResControlModeType->EVSEPresentActivePower_isUsed = 0u;
    DER_Scheduled_AC_CLResControlModeType->EVSEPresentActivePower_L2_isUsed = 0u;
    DER_Scheduled_AC_CLResControlModeType->EVSEPresentActivePower_L3_isUsed = 0u;
    DER_Scheduled_AC_CLResControlModeType->DERControl_isUsed = 0u;
}

void init_iso20_ac_der_Dynamic_AC_CLReqControlModeType(struct iso20_ac_der_Dynamic_AC_CLReqControlModeType* Dynamic_AC_CLReqControlModeType) {
    Dynamic_AC_CLReqControlModeType->DepartureTime_isUsed = 0u;
    Dynamic_AC_CLReqControlModeType->EVMaximumChargePower_L2_isUsed = 0u;
    Dynamic_AC_CLReqControlModeType->EVMaximumChargePower_L3_isUsed = 0u;
    Dynamic_AC_CLReqControlModeType->EVMinimumChargePower_L2_isUsed = 0u;
    Dynamic_AC_CLReqControlModeType->EVMinimumChargePower_L3_isUsed = 0u;
    Dynamic_AC_CLReqControlModeType->EVPresentActivePower_L2_isUsed = 0u;
    Dynamic_AC_CLReqControlModeType->EVPresentActivePower_L3_isUsed = 0u;
    Dynamic_AC_CLReqControlModeType->EVPresentReactivePower_L2_isUsed = 0u;
    Dynamic_AC_CLReqControlModeType->EVPresentReactivePower_L3_isUsed = 0u;
}

void init_iso20_ac_der_Dynamic_AC_CLResControlModeType(struct iso20_ac_der_Dynamic_AC_CLResControlModeType* Dynamic_AC_CLResControlModeType) {
    Dynamic_AC_CLResControlModeType->DepartureTime_isUsed = 0u;
    Dynamic_AC_CLResControlModeType->MinimumSOC_isUsed = 0u;
    Dynamic_AC_CLResControlModeType->TargetSOC_isUsed = 0u;
    Dynamic_AC_CLResControlModeType->AckMaxDelay_isUsed = 0u;
    Dynamic_AC_CLResControlModeType->EVSETargetActivePower_L2_isUsed = 0u;
    Dynamic_AC_CLResControlModeType->EVSETargetActivePower_L3_isUsed = 0u;
    Dynamic_AC_CLResControlModeType->EVSETargetReactivePower_isUsed = 0u;
    Dynamic_AC_CLResControlModeType->EVSETargetReactivePower_L2_isUsed = 0u;
    Dynamic_AC_CLResControlModeType->EVSETargetReactivePower_L3_isUsed = 0u;
    Dynamic_AC_CLResControlModeType->EVSEPresentActivePower_isUsed = 0u;
    Dynamic_AC_CLResControlModeType->EVSEPresentActivePower_L2_isUsed = 0u;
    Dynamic_AC_CLResControlModeType->EVSEPresentActivePower_L3_isUsed = 0u;
}

void init_iso20_ac_der_ManifestType(struct iso20_ac_der_ManifestType* ManifestType) {
    ManifestType->Reference.arrayLen = 0u;
    ManifestType->Id_isUsed = 0u;
}

void init_iso20_ac_der_Scheduled_AC_CLReqControlModeType(struct iso20_ac_der_Scheduled_AC_CLReqControlModeType* Scheduled_AC_CLReqControlModeType) {
    Scheduled_AC_CLReqControlModeType->EVTargetEnergyRequest_isUsed = 0u;
    Scheduled_AC_CLReqControlModeType->EVMaximumEnergyRequest_isUsed = 0u;
    Scheduled_AC_CLReqControlModeType->EVMinimumEnergyRequest_isUsed = 0u;
    Scheduled_AC_CLReqControlModeType->EVMaximumChargePower_isUsed = 0u;
    Scheduled_AC_CLReqControlModeType->EVMaximumChargePower_L2_isUsed = 0u;
    Scheduled_AC_CLReqControlModeType->EVMaximumChargePower_L3_isUsed = 0u;
    Scheduled_AC_CLReqControlModeType->EVMinimumChargePower_isUsed = 0u;
    Scheduled_AC_CLReqControlModeType->EVMinimumChargePower_L2_isUsed = 0u;
    Scheduled_AC_CLReqControlModeType->EVMinimumChargePower_L3_isUsed = 0u;
    Scheduled_AC_CLReqControlModeType->EVPresentActivePower_L2_isUsed = 0u;
    Scheduled_AC_CLReqControlModeType->EVPresentActivePower_L3_isUsed = 0u;
    Scheduled_AC_CLReqControlModeType->EVPresentReactivePower_isUsed = 0u;
    Scheduled_AC_CLReqControlModeType->EVPresentReactivePower_L2_isUsed = 0u;
    Scheduled_AC_CLReqControlModeType->EVPresentReactivePower_L3_isUsed = 0u;
}

void init_iso20_ac_der_Scheduled_AC_CLResControlModeType(struct iso20_ac_der_Scheduled_AC_CLResControlModeType* Scheduled_AC_CLResControlModeType) {
    Scheduled_AC_CLResControlModeType->EVSETargetActivePower_isUsed = 0u;
    Scheduled_AC_CLResControlModeType->EVSETargetActivePower_L2_isUsed = 0u;
    Scheduled_AC_CLResControlModeType->EVSETargetActivePower_L3_isUsed = 0u;
    Scheduled_AC_CLResControlModeType->EVSETargetReactivePower_isUsed = 0u;
    Scheduled_AC_CLResControlModeType->EVSETargetReactivePower_L2_isUsed = 0u;
    Scheduled_AC_CLResControlModeType->EVSETargetReactivePower_L3_isUsed = 0u;
    Scheduled_AC_CLResControlModeType->EVSEPresentActivePower_isUsed = 0u;
    Scheduled_AC_CLResControlModeType->EVSEPresentActivePower_L2_isUsed = 0u;
    Scheduled_AC_CLResControlModeType->EVSEPresentActivePower_L3_isUsed = 0u;
}

void init_iso20_ac_der_SignatureType(struct iso20_ac_der_SignatureType* SignatureType) {
    SignatureType->Id_isUsed = 0u;
    SignatureType->KeyInfo_isUsed = 0u;
    SignatureType->Object_isUsed = 0u;
}

void init_iso20_ac_der_SignaturePropertiesType(struct iso20_ac_der_SignaturePropertiesType* SignaturePropertiesType) {
    SignaturePropertiesType->Id_isUsed = 0u;
}

// init for fragment
void init_iso20_ac_der_exiFragment(struct iso20_ac_der_exiFragment* exiFrag) {
    exiFrag->AC_ChargeParameterDiscoveryRes_isUsed = 0u;
    exiFrag->SignedInfo_isUsed = 0u;
}

// init for xmldsig fragment
void init_iso20_ac_der_xmldsigFragment(struct iso20_ac_der_xmldsigFragment* xmldsigFrag) {
    xmldsigFrag->CanonicalizationMethod_isUsed = 0u;
    xmldsigFrag->DSAKeyValue_isUsed = 0u;
    xmldsigFrag->DigestMethod_isUsed = 0u;
    xmldsigFrag->KeyInfo_isUsed = 0u;
    xmldsigFrag->KeyValue_isUsed = 0u;
    xmldsigFrag->Manifest_isUsed = 0u;
    xmldsigFrag->Object_isUsed = 0u;
    xmldsigFrag->PGPData_isUsed = 0u;
    xmldsigFrag->RSAKeyValue_isUsed = 0u;
    xmldsigFrag->Reference_isUsed = 0u;
    xmldsigFrag->RetrievalMethod_isUsed = 0u;
    xmldsigFrag->SPKIData_isUsed = 0u;
    xmldsigFrag->Signature_isUsed = 0u;
    xmldsigFrag->SignatureMethod_isUsed = 0u;
    xmldsigFrag->SignatureProperties_isUsed = 0u;
    xmldsigFrag->SignatureProperty_isUsed = 0u;
    xmldsigFrag->SignatureValue_isUsed = 0u;
    xmldsigFrag->SignedInfo_isUsed = 0u;
    xmldsigFrag->Transform_isUsed = 0u;
    xmldsigFrag->Transforms_isUsed = 0u;
    xmldsigFrag->X509Data_isUsed = 0u;
}


