// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: ADKLine.proto

#ifndef PROTOBUF_ADKLine_2eproto__INCLUDED
#define PROTOBUF_ADKLine_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3001000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3001000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/unknown_field_set.h>
#include "EMDPeriodType.pb.h"
#include "ESecurityType.pb.h"
#include "ESecurityIDSource.pb.h"
// @@protoc_insertion_point(includes)

namespace com {
namespace htsc {
namespace mdc {
namespace insight {
namespace model {

// Internal implementation detail -- do not call these.
void protobuf_AddDesc_ADKLine_2eproto();
void protobuf_InitDefaults_ADKLine_2eproto();
void protobuf_AssignDesc_ADKLine_2eproto();
void protobuf_ShutdownFile_ADKLine_2eproto();

class ADKLine;

// ===================================================================

class ADKLine : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:com.htsc.mdc.insight.model.ADKLine) */ {
 public:
  ADKLine();
  virtual ~ADKLine();

  ADKLine(const ADKLine& from);

  inline ADKLine& operator=(const ADKLine& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const ADKLine& default_instance();

  static const ADKLine* internal_default_instance();

  void Swap(ADKLine* other);

  // implements Message ----------------------------------------------

  inline ADKLine* New() const { return New(NULL); }

  ADKLine* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const ADKLine& from);
  void MergeFrom(const ADKLine& from);
  void Clear();
  bool IsInitialized() const;

  size_t ByteSizeLong() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const {
    return InternalSerializeWithCachedSizesToArray(false, output);
  }
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(ADKLine* other);
  void UnsafeMergeFrom(const ADKLine& from);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return _internal_metadata_.arena();
  }
  inline void* MaybeArenaPtr() const {
    return _internal_metadata_.raw_arena_ptr();
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional string HTSCSecurityID = 1;
  void clear_htscsecurityid();
  static const int kHTSCSecurityIDFieldNumber = 1;
  const ::std::string& htscsecurityid() const;
  void set_htscsecurityid(const ::std::string& value);
  void set_htscsecurityid(const char* value);
  void set_htscsecurityid(const char* value, size_t size);
  ::std::string* mutable_htscsecurityid();
  ::std::string* release_htscsecurityid();
  void set_allocated_htscsecurityid(::std::string* htscsecurityid);

  // optional int32 MDDate = 2;
  void clear_mddate();
  static const int kMDDateFieldNumber = 2;
  ::google::protobuf::int32 mddate() const;
  void set_mddate(::google::protobuf::int32 value);

  // optional int32 MDTime = 3;
  void clear_mdtime();
  static const int kMDTimeFieldNumber = 3;
  ::google::protobuf::int32 mdtime() const;
  void set_mdtime(::google::protobuf::int32 value);

  // optional int64 DataTimestamp = 4;
  void clear_datatimestamp();
  static const int kDataTimestampFieldNumber = 4;
  ::google::protobuf::int64 datatimestamp() const;
  void set_datatimestamp(::google::protobuf::int64 value);

  // optional .com.htsc.mdc.model.ESecurityIDSource securityIDSource = 5;
  void clear_securityidsource();
  static const int kSecurityIDSourceFieldNumber = 5;
  ::com::htsc::mdc::model::ESecurityIDSource securityidsource() const;
  void set_securityidsource(::com::htsc::mdc::model::ESecurityIDSource value);

  // optional .com.htsc.mdc.model.ESecurityType securityType = 6;
  void clear_securitytype();
  static const int kSecurityTypeFieldNumber = 6;
  ::com::htsc::mdc::model::ESecurityType securitytype() const;
  void set_securitytype(::com::htsc::mdc::model::ESecurityType value);

  // optional .com.htsc.mdc.model.EMDPeriodType PeriodType = 7;
  void clear_periodtype();
  static const int kPeriodTypeFieldNumber = 7;
  ::com::htsc::mdc::model::EMDPeriodType periodtype() const;
  void set_periodtype(::com::htsc::mdc::model::EMDPeriodType value);

  // optional int64 OpenPx = 8;
  void clear_openpx();
  static const int kOpenPxFieldNumber = 8;
  ::google::protobuf::int64 openpx() const;
  void set_openpx(::google::protobuf::int64 value);

  // optional int64 ClosePx = 9;
  void clear_closepx();
  static const int kClosePxFieldNumber = 9;
  ::google::protobuf::int64 closepx() const;
  void set_closepx(::google::protobuf::int64 value);

  // optional int64 HighPx = 10;
  void clear_highpx();
  static const int kHighPxFieldNumber = 10;
  ::google::protobuf::int64 highpx() const;
  void set_highpx(::google::protobuf::int64 value);

  // optional int64 LowPx = 11;
  void clear_lowpx();
  static const int kLowPxFieldNumber = 11;
  ::google::protobuf::int64 lowpx() const;
  void set_lowpx(::google::protobuf::int64 value);

  // optional int64 NumTrades = 12;
  void clear_numtrades();
  static const int kNumTradesFieldNumber = 12;
  ::google::protobuf::int64 numtrades() const;
  void set_numtrades(::google::protobuf::int64 value);

  // optional int64 TotalVolumeTrade = 13;
  void clear_totalvolumetrade();
  static const int kTotalVolumeTradeFieldNumber = 13;
  ::google::protobuf::int64 totalvolumetrade() const;
  void set_totalvolumetrade(::google::protobuf::int64 value);

  // optional int64 TotalValueTrade = 14;
  void clear_totalvaluetrade();
  static const int kTotalValueTradeFieldNumber = 14;
  ::google::protobuf::int64 totalvaluetrade() const;
  void set_totalvaluetrade(::google::protobuf::int64 value);

  // optional int64 IOPV = 15;
  void clear_iopv();
  static const int kIOPVFieldNumber = 15;
  ::google::protobuf::int64 iopv() const;
  void set_iopv(::google::protobuf::int64 value);

  // optional int64 OpenInterest = 16;
  void clear_openinterest();
  static const int kOpenInterestFieldNumber = 16;
  ::google::protobuf::int64 openinterest() const;
  void set_openinterest(::google::protobuf::int64 value);

  // optional int64 SettlePrice = 17;
  void clear_settleprice();
  static const int kSettlePriceFieldNumber = 17;
  ::google::protobuf::int64 settleprice() const;
  void set_settleprice(::google::protobuf::int64 value);

  // optional int32 ExchangeDate = 18;
  void clear_exchangedate();
  static const int kExchangeDateFieldNumber = 18;
  ::google::protobuf::int32 exchangedate() const;
  void set_exchangedate(::google::protobuf::int32 value);

  // optional int32 ExchangeTime = 19;
  void clear_exchangetime();
  static const int kExchangeTimeFieldNumber = 19;
  ::google::protobuf::int32 exchangetime() const;
  void set_exchangetime(::google::protobuf::int32 value);

  // optional int32 KLineCategory = 20;
  void clear_klinecategory();
  static const int kKLineCategoryFieldNumber = 20;
  ::google::protobuf::int32 klinecategory() const;
  void set_klinecategory(::google::protobuf::int32 value);

  // optional int64 AfterHoursNumTrades = 21;
  void clear_afterhoursnumtrades();
  static const int kAfterHoursNumTradesFieldNumber = 21;
  ::google::protobuf::int64 afterhoursnumtrades() const;
  void set_afterhoursnumtrades(::google::protobuf::int64 value);

  // optional int64 AfterHoursTotalVolumeTrade = 22;
  void clear_afterhourstotalvolumetrade();
  static const int kAfterHoursTotalVolumeTradeFieldNumber = 22;
  ::google::protobuf::int64 afterhourstotalvolumetrade() const;
  void set_afterhourstotalvolumetrade(::google::protobuf::int64 value);

  // optional int64 AfterHoursTotalValueTrade = 23;
  void clear_afterhourstotalvaluetrade();
  static const int kAfterHoursTotalValueTradeFieldNumber = 23;
  ::google::protobuf::int64 afterhourstotalvaluetrade() const;
  void set_afterhourstotalvaluetrade(::google::protobuf::int64 value);

  // optional int64 PreClosePx = 24;
  void clear_preclosepx();
  static const int kPreClosePxFieldNumber = 24;
  ::google::protobuf::int64 preclosepx() const;
  void set_preclosepx(::google::protobuf::int64 value);

  // optional int64 PreCloseYield = 25;
  void clear_precloseyield();
  static const int kPreCloseYieldFieldNumber = 25;
  ::google::protobuf::int64 precloseyield() const;
  void set_precloseyield(::google::protobuf::int64 value);

  // optional int64 PreWeightedAvgPx = 26;
  void clear_preweightedavgpx();
  static const int kPreWeightedAvgPxFieldNumber = 26;
  ::google::protobuf::int64 preweightedavgpx() const;
  void set_preweightedavgpx(::google::protobuf::int64 value);

  // optional int64 PreWeightedAvgYield = 27;
  void clear_preweightedavgyield();
  static const int kPreWeightedAvgYieldFieldNumber = 27;
  ::google::protobuf::int64 preweightedavgyield() const;
  void set_preweightedavgyield(::google::protobuf::int64 value);

  // optional int64 CloseWeightedAvgPx = 28;
  void clear_closeweightedavgpx();
  static const int kCloseWeightedAvgPxFieldNumber = 28;
  ::google::protobuf::int64 closeweightedavgpx() const;
  void set_closeweightedavgpx(::google::protobuf::int64 value);

  // optional int64 CloseWeightedAvgYield = 29;
  void clear_closeweightedavgyield();
  static const int kCloseWeightedAvgYieldFieldNumber = 29;
  ::google::protobuf::int64 closeweightedavgyield() const;
  void set_closeweightedavgyield(::google::protobuf::int64 value);

  // optional int64 OpenYield = 30;
  void clear_openyield();
  static const int kOpenYieldFieldNumber = 30;
  ::google::protobuf::int64 openyield() const;
  void set_openyield(::google::protobuf::int64 value);

  // optional int64 HighYield = 31;
  void clear_highyield();
  static const int kHighYieldFieldNumber = 31;
  ::google::protobuf::int64 highyield() const;
  void set_highyield(::google::protobuf::int64 value);

  // optional int64 LowYield = 32;
  void clear_lowyield();
  static const int kLowYieldFieldNumber = 32;
  ::google::protobuf::int64 lowyield() const;
  void set_lowyield(::google::protobuf::int64 value);

  // optional int64 CloseYield = 33;
  void clear_closeyield();
  static const int kCloseYieldFieldNumber = 33;
  ::google::protobuf::int64 closeyield() const;
  void set_closeyield(::google::protobuf::int64 value);

  // optional int32 DataMultiplePowerOf10 = 34;
  void clear_datamultiplepowerof10();
  static const int kDataMultiplePowerOf10FieldNumber = 34;
  ::google::protobuf::int32 datamultiplepowerof10() const;
  void set_datamultiplepowerof10(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:com.htsc.mdc.insight.model.ADKLine)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr htscsecurityid_;
  ::google::protobuf::int32 mddate_;
  ::google::protobuf::int32 mdtime_;
  ::google::protobuf::int64 datatimestamp_;
  int securityidsource_;
  int securitytype_;
  ::google::protobuf::int64 openpx_;
  ::google::protobuf::int64 closepx_;
  ::google::protobuf::int64 highpx_;
  ::google::protobuf::int64 lowpx_;
  ::google::protobuf::int64 numtrades_;
  int periodtype_;
  ::google::protobuf::int32 exchangedate_;
  ::google::protobuf::int64 totalvolumetrade_;
  ::google::protobuf::int64 totalvaluetrade_;
  ::google::protobuf::int64 iopv_;
  ::google::protobuf::int64 openinterest_;
  ::google::protobuf::int64 settleprice_;
  ::google::protobuf::int32 exchangetime_;
  ::google::protobuf::int32 klinecategory_;
  ::google::protobuf::int64 afterhoursnumtrades_;
  ::google::protobuf::int64 afterhourstotalvolumetrade_;
  ::google::protobuf::int64 afterhourstotalvaluetrade_;
  ::google::protobuf::int64 preclosepx_;
  ::google::protobuf::int64 precloseyield_;
  ::google::protobuf::int64 preweightedavgpx_;
  ::google::protobuf::int64 preweightedavgyield_;
  ::google::protobuf::int64 closeweightedavgpx_;
  ::google::protobuf::int64 closeweightedavgyield_;
  ::google::protobuf::int64 openyield_;
  ::google::protobuf::int64 highyield_;
  ::google::protobuf::int64 lowyield_;
  ::google::protobuf::int64 closeyield_;
  ::google::protobuf::int32 datamultiplepowerof10_;
  mutable int _cached_size_;
  friend void  protobuf_InitDefaults_ADKLine_2eproto_impl();
  friend void  protobuf_AddDesc_ADKLine_2eproto_impl();
  friend void protobuf_AssignDesc_ADKLine_2eproto();
  friend void protobuf_ShutdownFile_ADKLine_2eproto();

  void InitAsDefaultInstance();
};
extern ::google::protobuf::internal::ExplicitlyConstructed<ADKLine> ADKLine_default_instance_;

// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
// ADKLine

// optional string HTSCSecurityID = 1;
inline void ADKLine::clear_htscsecurityid() {
  htscsecurityid_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& ADKLine::htscsecurityid() const {
  // @@protoc_insertion_point(field_get:com.htsc.mdc.insight.model.ADKLine.HTSCSecurityID)
  return htscsecurityid_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void ADKLine::set_htscsecurityid(const ::std::string& value) {
  
  htscsecurityid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:com.htsc.mdc.insight.model.ADKLine.HTSCSecurityID)
}
inline void ADKLine::set_htscsecurityid(const char* value) {
  
  htscsecurityid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:com.htsc.mdc.insight.model.ADKLine.HTSCSecurityID)
}
inline void ADKLine::set_htscsecurityid(const char* value, size_t size) {
  
  htscsecurityid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:com.htsc.mdc.insight.model.ADKLine.HTSCSecurityID)
}
inline ::std::string* ADKLine::mutable_htscsecurityid() {
  
  // @@protoc_insertion_point(field_mutable:com.htsc.mdc.insight.model.ADKLine.HTSCSecurityID)
  return htscsecurityid_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* ADKLine::release_htscsecurityid() {
  // @@protoc_insertion_point(field_release:com.htsc.mdc.insight.model.ADKLine.HTSCSecurityID)
  
  return htscsecurityid_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void ADKLine::set_allocated_htscsecurityid(::std::string* htscsecurityid) {
  if (htscsecurityid != NULL) {
    
  } else {
    
  }
  htscsecurityid_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), htscsecurityid);
  // @@protoc_insertion_point(field_set_allocated:com.htsc.mdc.insight.model.ADKLine.HTSCSecurityID)
}

// optional int32 MDDate = 2;
inline void ADKLine::clear_mddate() {
  mddate_ = 0;
}
inline ::google::protobuf::int32 ADKLine::mddate() const {
  // @@protoc_insertion_point(field_get:com.htsc.mdc.insight.model.ADKLine.MDDate)
  return mddate_;
}
inline void ADKLine::set_mddate(::google::protobuf::int32 value) {
  
  mddate_ = value;
  // @@protoc_insertion_point(field_set:com.htsc.mdc.insight.model.ADKLine.MDDate)
}

// optional int32 MDTime = 3;
inline void ADKLine::clear_mdtime() {
  mdtime_ = 0;
}
inline ::google::protobuf::int32 ADKLine::mdtime() const {
  // @@protoc_insertion_point(field_get:com.htsc.mdc.insight.model.ADKLine.MDTime)
  return mdtime_;
}
inline void ADKLine::set_mdtime(::google::protobuf::int32 value) {
  
  mdtime_ = value;
  // @@protoc_insertion_point(field_set:com.htsc.mdc.insight.model.ADKLine.MDTime)
}

// optional int64 DataTimestamp = 4;
inline void ADKLine::clear_datatimestamp() {
  datatimestamp_ = GOOGLE_LONGLONG(0);
}
inline ::google::protobuf::int64 ADKLine::datatimestamp() const {
  // @@protoc_insertion_point(field_get:com.htsc.mdc.insight.model.ADKLine.DataTimestamp)
  return datatimestamp_;
}
inline void ADKLine::set_datatimestamp(::google::protobuf::int64 value) {
  
  datatimestamp_ = value;
  // @@protoc_insertion_point(field_set:com.htsc.mdc.insight.model.ADKLine.DataTimestamp)
}

// optional .com.htsc.mdc.model.ESecurityIDSource securityIDSource = 5;
inline void ADKLine::clear_securityidsource() {
  securityidsource_ = 0;
}
inline ::com::htsc::mdc::model::ESecurityIDSource ADKLine::securityidsource() const {
  // @@protoc_insertion_point(field_get:com.htsc.mdc.insight.model.ADKLine.securityIDSource)
  return static_cast< ::com::htsc::mdc::model::ESecurityIDSource >(securityidsource_);
}
inline void ADKLine::set_securityidsource(::com::htsc::mdc::model::ESecurityIDSource value) {
  
  securityidsource_ = value;
  // @@protoc_insertion_point(field_set:com.htsc.mdc.insight.model.ADKLine.securityIDSource)
}

// optional .com.htsc.mdc.model.ESecurityType securityType = 6;
inline void ADKLine::clear_securitytype() {
  securitytype_ = 0;
}
inline ::com::htsc::mdc::model::ESecurityType ADKLine::securitytype() const {
  // @@protoc_insertion_point(field_get:com.htsc.mdc.insight.model.ADKLine.securityType)
  return static_cast< ::com::htsc::mdc::model::ESecurityType >(securitytype_);
}
inline void ADKLine::set_securitytype(::com::htsc::mdc::model::ESecurityType value) {
  
  securitytype_ = value;
  // @@protoc_insertion_point(field_set:com.htsc.mdc.insight.model.ADKLine.securityType)
}

// optional .com.htsc.mdc.model.EMDPeriodType PeriodType = 7;
inline void ADKLine::clear_periodtype() {
  periodtype_ = 0;
}
inline ::com::htsc::mdc::model::EMDPeriodType ADKLine::periodtype() const {
  // @@protoc_insertion_point(field_get:com.htsc.mdc.insight.model.ADKLine.PeriodType)
  return static_cast< ::com::htsc::mdc::model::EMDPeriodType >(periodtype_);
}
inline void ADKLine::set_periodtype(::com::htsc::mdc::model::EMDPeriodType value) {
  
  periodtype_ = value;
  // @@protoc_insertion_point(field_set:com.htsc.mdc.insight.model.ADKLine.PeriodType)
}

// optional int64 OpenPx = 8;
inline void ADKLine::clear_openpx() {
  openpx_ = GOOGLE_LONGLONG(0);
}
inline ::google::protobuf::int64 ADKLine::openpx() const {
  // @@protoc_insertion_point(field_get:com.htsc.mdc.insight.model.ADKLine.OpenPx)
  return openpx_;
}
inline void ADKLine::set_openpx(::google::protobuf::int64 value) {
  
  openpx_ = value;
  // @@protoc_insertion_point(field_set:com.htsc.mdc.insight.model.ADKLine.OpenPx)
}

// optional int64 ClosePx = 9;
inline void ADKLine::clear_closepx() {
  closepx_ = GOOGLE_LONGLONG(0);
}
inline ::google::protobuf::int64 ADKLine::closepx() const {
  // @@protoc_insertion_point(field_get:com.htsc.mdc.insight.model.ADKLine.ClosePx)
  return closepx_;
}
inline void ADKLine::set_closepx(::google::protobuf::int64 value) {
  
  closepx_ = value;
  // @@protoc_insertion_point(field_set:com.htsc.mdc.insight.model.ADKLine.ClosePx)
}

// optional int64 HighPx = 10;
inline void ADKLine::clear_highpx() {
  highpx_ = GOOGLE_LONGLONG(0);
}
inline ::google::protobuf::int64 ADKLine::highpx() const {
  // @@protoc_insertion_point(field_get:com.htsc.mdc.insight.model.ADKLine.HighPx)
  return highpx_;
}
inline void ADKLine::set_highpx(::google::protobuf::int64 value) {
  
  highpx_ = value;
  // @@protoc_insertion_point(field_set:com.htsc.mdc.insight.model.ADKLine.HighPx)
}

// optional int64 LowPx = 11;
inline void ADKLine::clear_lowpx() {
  lowpx_ = GOOGLE_LONGLONG(0);
}
inline ::google::protobuf::int64 ADKLine::lowpx() const {
  // @@protoc_insertion_point(field_get:com.htsc.mdc.insight.model.ADKLine.LowPx)
  return lowpx_;
}
inline void ADKLine::set_lowpx(::google::protobuf::int64 value) {
  
  lowpx_ = value;
  // @@protoc_insertion_point(field_set:com.htsc.mdc.insight.model.ADKLine.LowPx)
}

// optional int64 NumTrades = 12;
inline void ADKLine::clear_numtrades() {
  numtrades_ = GOOGLE_LONGLONG(0);
}
inline ::google::protobuf::int64 ADKLine::numtrades() const {
  // @@protoc_insertion_point(field_get:com.htsc.mdc.insight.model.ADKLine.NumTrades)
  return numtrades_;
}
inline void ADKLine::set_numtrades(::google::protobuf::int64 value) {
  
  numtrades_ = value;
  // @@protoc_insertion_point(field_set:com.htsc.mdc.insight.model.ADKLine.NumTrades)
}

// optional int64 TotalVolumeTrade = 13;
inline void ADKLine::clear_totalvolumetrade() {
  totalvolumetrade_ = GOOGLE_LONGLONG(0);
}
inline ::google::protobuf::int64 ADKLine::totalvolumetrade() const {
  // @@protoc_insertion_point(field_get:com.htsc.mdc.insight.model.ADKLine.TotalVolumeTrade)
  return totalvolumetrade_;
}
inline void ADKLine::set_totalvolumetrade(::google::protobuf::int64 value) {
  
  totalvolumetrade_ = value;
  // @@protoc_insertion_point(field_set:com.htsc.mdc.insight.model.ADKLine.TotalVolumeTrade)
}

// optional int64 TotalValueTrade = 14;
inline void ADKLine::clear_totalvaluetrade() {
  totalvaluetrade_ = GOOGLE_LONGLONG(0);
}
inline ::google::protobuf::int64 ADKLine::totalvaluetrade() const {
  // @@protoc_insertion_point(field_get:com.htsc.mdc.insight.model.ADKLine.TotalValueTrade)
  return totalvaluetrade_;
}
inline void ADKLine::set_totalvaluetrade(::google::protobuf::int64 value) {
  
  totalvaluetrade_ = value;
  // @@protoc_insertion_point(field_set:com.htsc.mdc.insight.model.ADKLine.TotalValueTrade)
}

// optional int64 IOPV = 15;
inline void ADKLine::clear_iopv() {
  iopv_ = GOOGLE_LONGLONG(0);
}
inline ::google::protobuf::int64 ADKLine::iopv() const {
  // @@protoc_insertion_point(field_get:com.htsc.mdc.insight.model.ADKLine.IOPV)
  return iopv_;
}
inline void ADKLine::set_iopv(::google::protobuf::int64 value) {
  
  iopv_ = value;
  // @@protoc_insertion_point(field_set:com.htsc.mdc.insight.model.ADKLine.IOPV)
}

// optional int64 OpenInterest = 16;
inline void ADKLine::clear_openinterest() {
  openinterest_ = GOOGLE_LONGLONG(0);
}
inline ::google::protobuf::int64 ADKLine::openinterest() const {
  // @@protoc_insertion_point(field_get:com.htsc.mdc.insight.model.ADKLine.OpenInterest)
  return openinterest_;
}
inline void ADKLine::set_openinterest(::google::protobuf::int64 value) {
  
  openinterest_ = value;
  // @@protoc_insertion_point(field_set:com.htsc.mdc.insight.model.ADKLine.OpenInterest)
}

// optional int64 SettlePrice = 17;
inline void ADKLine::clear_settleprice() {
  settleprice_ = GOOGLE_LONGLONG(0);
}
inline ::google::protobuf::int64 ADKLine::settleprice() const {
  // @@protoc_insertion_point(field_get:com.htsc.mdc.insight.model.ADKLine.SettlePrice)
  return settleprice_;
}
inline void ADKLine::set_settleprice(::google::protobuf::int64 value) {
  
  settleprice_ = value;
  // @@protoc_insertion_point(field_set:com.htsc.mdc.insight.model.ADKLine.SettlePrice)
}

// optional int32 ExchangeDate = 18;
inline void ADKLine::clear_exchangedate() {
  exchangedate_ = 0;
}
inline ::google::protobuf::int32 ADKLine::exchangedate() const {
  // @@protoc_insertion_point(field_get:com.htsc.mdc.insight.model.ADKLine.ExchangeDate)
  return exchangedate_;
}
inline void ADKLine::set_exchangedate(::google::protobuf::int32 value) {
  
  exchangedate_ = value;
  // @@protoc_insertion_point(field_set:com.htsc.mdc.insight.model.ADKLine.ExchangeDate)
}

// optional int32 ExchangeTime = 19;
inline void ADKLine::clear_exchangetime() {
  exchangetime_ = 0;
}
inline ::google::protobuf::int32 ADKLine::exchangetime() const {
  // @@protoc_insertion_point(field_get:com.htsc.mdc.insight.model.ADKLine.ExchangeTime)
  return exchangetime_;
}
inline void ADKLine::set_exchangetime(::google::protobuf::int32 value) {
  
  exchangetime_ = value;
  // @@protoc_insertion_point(field_set:com.htsc.mdc.insight.model.ADKLine.ExchangeTime)
}

// optional int32 KLineCategory = 20;
inline void ADKLine::clear_klinecategory() {
  klinecategory_ = 0;
}
inline ::google::protobuf::int32 ADKLine::klinecategory() const {
  // @@protoc_insertion_point(field_get:com.htsc.mdc.insight.model.ADKLine.KLineCategory)
  return klinecategory_;
}
inline void ADKLine::set_klinecategory(::google::protobuf::int32 value) {
  
  klinecategory_ = value;
  // @@protoc_insertion_point(field_set:com.htsc.mdc.insight.model.ADKLine.KLineCategory)
}

// optional int64 AfterHoursNumTrades = 21;
inline void ADKLine::clear_afterhoursnumtrades() {
  afterhoursnumtrades_ = GOOGLE_LONGLONG(0);
}
inline ::google::protobuf::int64 ADKLine::afterhoursnumtrades() const {
  // @@protoc_insertion_point(field_get:com.htsc.mdc.insight.model.ADKLine.AfterHoursNumTrades)
  return afterhoursnumtrades_;
}
inline void ADKLine::set_afterhoursnumtrades(::google::protobuf::int64 value) {
  
  afterhoursnumtrades_ = value;
  // @@protoc_insertion_point(field_set:com.htsc.mdc.insight.model.ADKLine.AfterHoursNumTrades)
}

// optional int64 AfterHoursTotalVolumeTrade = 22;
inline void ADKLine::clear_afterhourstotalvolumetrade() {
  afterhourstotalvolumetrade_ = GOOGLE_LONGLONG(0);
}
inline ::google::protobuf::int64 ADKLine::afterhourstotalvolumetrade() const {
  // @@protoc_insertion_point(field_get:com.htsc.mdc.insight.model.ADKLine.AfterHoursTotalVolumeTrade)
  return afterhourstotalvolumetrade_;
}
inline void ADKLine::set_afterhourstotalvolumetrade(::google::protobuf::int64 value) {
  
  afterhourstotalvolumetrade_ = value;
  // @@protoc_insertion_point(field_set:com.htsc.mdc.insight.model.ADKLine.AfterHoursTotalVolumeTrade)
}

// optional int64 AfterHoursTotalValueTrade = 23;
inline void ADKLine::clear_afterhourstotalvaluetrade() {
  afterhourstotalvaluetrade_ = GOOGLE_LONGLONG(0);
}
inline ::google::protobuf::int64 ADKLine::afterhourstotalvaluetrade() const {
  // @@protoc_insertion_point(field_get:com.htsc.mdc.insight.model.ADKLine.AfterHoursTotalValueTrade)
  return afterhourstotalvaluetrade_;
}
inline void ADKLine::set_afterhourstotalvaluetrade(::google::protobuf::int64 value) {
  
  afterhourstotalvaluetrade_ = value;
  // @@protoc_insertion_point(field_set:com.htsc.mdc.insight.model.ADKLine.AfterHoursTotalValueTrade)
}

// optional int64 PreClosePx = 24;
inline void ADKLine::clear_preclosepx() {
  preclosepx_ = GOOGLE_LONGLONG(0);
}
inline ::google::protobuf::int64 ADKLine::preclosepx() const {
  // @@protoc_insertion_point(field_get:com.htsc.mdc.insight.model.ADKLine.PreClosePx)
  return preclosepx_;
}
inline void ADKLine::set_preclosepx(::google::protobuf::int64 value) {
  
  preclosepx_ = value;
  // @@protoc_insertion_point(field_set:com.htsc.mdc.insight.model.ADKLine.PreClosePx)
}

// optional int64 PreCloseYield = 25;
inline void ADKLine::clear_precloseyield() {
  precloseyield_ = GOOGLE_LONGLONG(0);
}
inline ::google::protobuf::int64 ADKLine::precloseyield() const {
  // @@protoc_insertion_point(field_get:com.htsc.mdc.insight.model.ADKLine.PreCloseYield)
  return precloseyield_;
}
inline void ADKLine::set_precloseyield(::google::protobuf::int64 value) {
  
  precloseyield_ = value;
  // @@protoc_insertion_point(field_set:com.htsc.mdc.insight.model.ADKLine.PreCloseYield)
}

// optional int64 PreWeightedAvgPx = 26;
inline void ADKLine::clear_preweightedavgpx() {
  preweightedavgpx_ = GOOGLE_LONGLONG(0);
}
inline ::google::protobuf::int64 ADKLine::preweightedavgpx() const {
  // @@protoc_insertion_point(field_get:com.htsc.mdc.insight.model.ADKLine.PreWeightedAvgPx)
  return preweightedavgpx_;
}
inline void ADKLine::set_preweightedavgpx(::google::protobuf::int64 value) {
  
  preweightedavgpx_ = value;
  // @@protoc_insertion_point(field_set:com.htsc.mdc.insight.model.ADKLine.PreWeightedAvgPx)
}

// optional int64 PreWeightedAvgYield = 27;
inline void ADKLine::clear_preweightedavgyield() {
  preweightedavgyield_ = GOOGLE_LONGLONG(0);
}
inline ::google::protobuf::int64 ADKLine::preweightedavgyield() const {
  // @@protoc_insertion_point(field_get:com.htsc.mdc.insight.model.ADKLine.PreWeightedAvgYield)
  return preweightedavgyield_;
}
inline void ADKLine::set_preweightedavgyield(::google::protobuf::int64 value) {
  
  preweightedavgyield_ = value;
  // @@protoc_insertion_point(field_set:com.htsc.mdc.insight.model.ADKLine.PreWeightedAvgYield)
}

// optional int64 CloseWeightedAvgPx = 28;
inline void ADKLine::clear_closeweightedavgpx() {
  closeweightedavgpx_ = GOOGLE_LONGLONG(0);
}
inline ::google::protobuf::int64 ADKLine::closeweightedavgpx() const {
  // @@protoc_insertion_point(field_get:com.htsc.mdc.insight.model.ADKLine.CloseWeightedAvgPx)
  return closeweightedavgpx_;
}
inline void ADKLine::set_closeweightedavgpx(::google::protobuf::int64 value) {
  
  closeweightedavgpx_ = value;
  // @@protoc_insertion_point(field_set:com.htsc.mdc.insight.model.ADKLine.CloseWeightedAvgPx)
}

// optional int64 CloseWeightedAvgYield = 29;
inline void ADKLine::clear_closeweightedavgyield() {
  closeweightedavgyield_ = GOOGLE_LONGLONG(0);
}
inline ::google::protobuf::int64 ADKLine::closeweightedavgyield() const {
  // @@protoc_insertion_point(field_get:com.htsc.mdc.insight.model.ADKLine.CloseWeightedAvgYield)
  return closeweightedavgyield_;
}
inline void ADKLine::set_closeweightedavgyield(::google::protobuf::int64 value) {
  
  closeweightedavgyield_ = value;
  // @@protoc_insertion_point(field_set:com.htsc.mdc.insight.model.ADKLine.CloseWeightedAvgYield)
}

// optional int64 OpenYield = 30;
inline void ADKLine::clear_openyield() {
  openyield_ = GOOGLE_LONGLONG(0);
}
inline ::google::protobuf::int64 ADKLine::openyield() const {
  // @@protoc_insertion_point(field_get:com.htsc.mdc.insight.model.ADKLine.OpenYield)
  return openyield_;
}
inline void ADKLine::set_openyield(::google::protobuf::int64 value) {
  
  openyield_ = value;
  // @@protoc_insertion_point(field_set:com.htsc.mdc.insight.model.ADKLine.OpenYield)
}

// optional int64 HighYield = 31;
inline void ADKLine::clear_highyield() {
  highyield_ = GOOGLE_LONGLONG(0);
}
inline ::google::protobuf::int64 ADKLine::highyield() const {
  // @@protoc_insertion_point(field_get:com.htsc.mdc.insight.model.ADKLine.HighYield)
  return highyield_;
}
inline void ADKLine::set_highyield(::google::protobuf::int64 value) {
  
  highyield_ = value;
  // @@protoc_insertion_point(field_set:com.htsc.mdc.insight.model.ADKLine.HighYield)
}

// optional int64 LowYield = 32;
inline void ADKLine::clear_lowyield() {
  lowyield_ = GOOGLE_LONGLONG(0);
}
inline ::google::protobuf::int64 ADKLine::lowyield() const {
  // @@protoc_insertion_point(field_get:com.htsc.mdc.insight.model.ADKLine.LowYield)
  return lowyield_;
}
inline void ADKLine::set_lowyield(::google::protobuf::int64 value) {
  
  lowyield_ = value;
  // @@protoc_insertion_point(field_set:com.htsc.mdc.insight.model.ADKLine.LowYield)
}

// optional int64 CloseYield = 33;
inline void ADKLine::clear_closeyield() {
  closeyield_ = GOOGLE_LONGLONG(0);
}
inline ::google::protobuf::int64 ADKLine::closeyield() const {
  // @@protoc_insertion_point(field_get:com.htsc.mdc.insight.model.ADKLine.CloseYield)
  return closeyield_;
}
inline void ADKLine::set_closeyield(::google::protobuf::int64 value) {
  
  closeyield_ = value;
  // @@protoc_insertion_point(field_set:com.htsc.mdc.insight.model.ADKLine.CloseYield)
}

// optional int32 DataMultiplePowerOf10 = 34;
inline void ADKLine::clear_datamultiplepowerof10() {
  datamultiplepowerof10_ = 0;
}
inline ::google::protobuf::int32 ADKLine::datamultiplepowerof10() const {
  // @@protoc_insertion_point(field_get:com.htsc.mdc.insight.model.ADKLine.DataMultiplePowerOf10)
  return datamultiplepowerof10_;
}
inline void ADKLine::set_datamultiplepowerof10(::google::protobuf::int32 value) {
  
  datamultiplepowerof10_ = value;
  // @@protoc_insertion_point(field_set:com.htsc.mdc.insight.model.ADKLine.DataMultiplePowerOf10)
}

inline const ADKLine* ADKLine::internal_default_instance() {
  return &ADKLine_default_instance_.get();
}
#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)

}  // namespace model
}  // namespace insight
}  // namespace mdc
}  // namespace htsc
}  // namespace com

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_ADKLine_2eproto__INCLUDED
