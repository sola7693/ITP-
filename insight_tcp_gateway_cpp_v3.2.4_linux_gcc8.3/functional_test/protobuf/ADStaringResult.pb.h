// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: ADStaringResult.proto

#ifndef PROTOBUF_ADStaringResult_2eproto__INCLUDED
#define PROTOBUF_ADStaringResult_2eproto__INCLUDED

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
#include "ESecurityType.pb.h"
#include "ESecurityIDSource.pb.h"
// @@protoc_insertion_point(includes)

namespace com {
namespace htsc {
namespace mdc {
namespace insight {
namespace model {

// Internal implementation detail -- do not call these.
void protobuf_AddDesc_ADStaringResult_2eproto();
void protobuf_InitDefaults_ADStaringResult_2eproto();
void protobuf_AssignDesc_ADStaringResult_2eproto();
void protobuf_ShutdownFile_ADStaringResult_2eproto();

class ADStaringResult;

// ===================================================================

class ADStaringResult : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:com.htsc.mdc.insight.model.ADStaringResult) */ {
 public:
  ADStaringResult();
  virtual ~ADStaringResult();

  ADStaringResult(const ADStaringResult& from);

  inline ADStaringResult& operator=(const ADStaringResult& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const ADStaringResult& default_instance();

  static const ADStaringResult* internal_default_instance();

  void Swap(ADStaringResult* other);

  // implements Message ----------------------------------------------

  inline ADStaringResult* New() const { return New(NULL); }

  ADStaringResult* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const ADStaringResult& from);
  void MergeFrom(const ADStaringResult& from);
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
  void InternalSwap(ADStaringResult* other);
  void UnsafeMergeFrom(const ADStaringResult& from);
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

  // optional int32 ExchangeDate = 7;
  void clear_exchangedate();
  static const int kExchangeDateFieldNumber = 7;
  ::google::protobuf::int32 exchangedate() const;
  void set_exchangedate(::google::protobuf::int32 value);

  // optional int32 ExchangeTime = 8;
  void clear_exchangetime();
  static const int kExchangeTimeFieldNumber = 8;
  ::google::protobuf::int32 exchangetime() const;
  void set_exchangetime(::google::protobuf::int32 value);

  // optional string StaringResultID = 9;
  void clear_staringresultid();
  static const int kStaringResultIDFieldNumber = 9;
  const ::std::string& staringresultid() const;
  void set_staringresultid(const ::std::string& value);
  void set_staringresultid(const char* value);
  void set_staringresultid(const char* value, size_t size);
  ::std::string* mutable_staringresultid();
  ::std::string* release_staringresultid();
  void set_allocated_staringresultid(::std::string* staringresultid);

  // optional string StrategyID = 10;
  void clear_strategyid();
  static const int kStrategyIDFieldNumber = 10;
  const ::std::string& strategyid() const;
  void set_strategyid(const ::std::string& value);
  void set_strategyid(const char* value);
  void set_strategyid(const char* value, size_t size);
  ::std::string* mutable_strategyid();
  ::std::string* release_strategyid();
  void set_allocated_strategyid(::std::string* strategyid);

  // optional string AlgorithmID = 11;
  void clear_algorithmid();
  static const int kAlgorithmIDFieldNumber = 11;
  const ::std::string& algorithmid() const;
  void set_algorithmid(const ::std::string& value);
  void set_algorithmid(const char* value);
  void set_algorithmid(const char* value, size_t size);
  ::std::string* mutable_algorithmid();
  ::std::string* release_algorithmid();
  void set_allocated_algorithmid(::std::string* algorithmid);

  // optional string AlgorithmName = 12;
  void clear_algorithmname();
  static const int kAlgorithmNameFieldNumber = 12;
  const ::std::string& algorithmname() const;
  void set_algorithmname(const ::std::string& value);
  void set_algorithmname(const char* value);
  void set_algorithmname(const char* value, size_t size);
  ::std::string* mutable_algorithmname();
  ::std::string* release_algorithmname();
  void set_allocated_algorithmname(::std::string* algorithmname);

  // optional string CustomerID = 13;
  void clear_customerid();
  static const int kCustomerIDFieldNumber = 13;
  const ::std::string& customerid() const;
  void set_customerid(const ::std::string& value);
  void set_customerid(const char* value);
  void set_customerid(const char* value, size_t size);
  ::std::string* mutable_customerid();
  ::std::string* release_customerid();
  void set_allocated_customerid(::std::string* customerid);

  // optional string SystemID = 14;
  void clear_systemid();
  static const int kSystemIDFieldNumber = 14;
  const ::std::string& systemid() const;
  void set_systemid(const ::std::string& value);
  void set_systemid(const char* value);
  void set_systemid(const char* value, size_t size);
  ::std::string* mutable_systemid();
  ::std::string* release_systemid();
  void set_allocated_systemid(::std::string* systemid);

  // optional int64 RmindValue = 15;
  void clear_rmindvalue();
  static const int kRmindValueFieldNumber = 15;
  ::google::protobuf::int64 rmindvalue() const;
  void set_rmindvalue(::google::protobuf::int64 value);

  // optional int64 RealCalValue = 16;
  void clear_realcalvalue();
  static const int kRealCalValueFieldNumber = 16;
  ::google::protobuf::int64 realcalvalue() const;
  void set_realcalvalue(::google::protobuf::int64 value);

  // optional int32 DataMultiplePowerOf10 = 17;
  void clear_datamultiplepowerof10();
  static const int kDataMultiplePowerOf10FieldNumber = 17;
  ::google::protobuf::int32 datamultiplepowerof10() const;
  void set_datamultiplepowerof10(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:com.htsc.mdc.insight.model.ADStaringResult)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr htscsecurityid_;
  ::google::protobuf::internal::ArenaStringPtr staringresultid_;
  ::google::protobuf::internal::ArenaStringPtr strategyid_;
  ::google::protobuf::internal::ArenaStringPtr algorithmid_;
  ::google::protobuf::internal::ArenaStringPtr algorithmname_;
  ::google::protobuf::internal::ArenaStringPtr customerid_;
  ::google::protobuf::internal::ArenaStringPtr systemid_;
  ::google::protobuf::int32 mddate_;
  ::google::protobuf::int32 mdtime_;
  ::google::protobuf::int64 datatimestamp_;
  int securityidsource_;
  int securitytype_;
  ::google::protobuf::int32 exchangedate_;
  ::google::protobuf::int32 exchangetime_;
  ::google::protobuf::int64 rmindvalue_;
  ::google::protobuf::int64 realcalvalue_;
  ::google::protobuf::int32 datamultiplepowerof10_;
  mutable int _cached_size_;
  friend void  protobuf_InitDefaults_ADStaringResult_2eproto_impl();
  friend void  protobuf_AddDesc_ADStaringResult_2eproto_impl();
  friend void protobuf_AssignDesc_ADStaringResult_2eproto();
  friend void protobuf_ShutdownFile_ADStaringResult_2eproto();

  void InitAsDefaultInstance();
};
extern ::google::protobuf::internal::ExplicitlyConstructed<ADStaringResult> ADStaringResult_default_instance_;

// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
// ADStaringResult

// optional string HTSCSecurityID = 1;
inline void ADStaringResult::clear_htscsecurityid() {
  htscsecurityid_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& ADStaringResult::htscsecurityid() const {
  // @@protoc_insertion_point(field_get:com.htsc.mdc.insight.model.ADStaringResult.HTSCSecurityID)
  return htscsecurityid_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void ADStaringResult::set_htscsecurityid(const ::std::string& value) {
  
  htscsecurityid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:com.htsc.mdc.insight.model.ADStaringResult.HTSCSecurityID)
}
inline void ADStaringResult::set_htscsecurityid(const char* value) {
  
  htscsecurityid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:com.htsc.mdc.insight.model.ADStaringResult.HTSCSecurityID)
}
inline void ADStaringResult::set_htscsecurityid(const char* value, size_t size) {
  
  htscsecurityid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:com.htsc.mdc.insight.model.ADStaringResult.HTSCSecurityID)
}
inline ::std::string* ADStaringResult::mutable_htscsecurityid() {
  
  // @@protoc_insertion_point(field_mutable:com.htsc.mdc.insight.model.ADStaringResult.HTSCSecurityID)
  return htscsecurityid_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* ADStaringResult::release_htscsecurityid() {
  // @@protoc_insertion_point(field_release:com.htsc.mdc.insight.model.ADStaringResult.HTSCSecurityID)
  
  return htscsecurityid_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void ADStaringResult::set_allocated_htscsecurityid(::std::string* htscsecurityid) {
  if (htscsecurityid != NULL) {
    
  } else {
    
  }
  htscsecurityid_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), htscsecurityid);
  // @@protoc_insertion_point(field_set_allocated:com.htsc.mdc.insight.model.ADStaringResult.HTSCSecurityID)
}

// optional int32 MDDate = 2;
inline void ADStaringResult::clear_mddate() {
  mddate_ = 0;
}
inline ::google::protobuf::int32 ADStaringResult::mddate() const {
  // @@protoc_insertion_point(field_get:com.htsc.mdc.insight.model.ADStaringResult.MDDate)
  return mddate_;
}
inline void ADStaringResult::set_mddate(::google::protobuf::int32 value) {
  
  mddate_ = value;
  // @@protoc_insertion_point(field_set:com.htsc.mdc.insight.model.ADStaringResult.MDDate)
}

// optional int32 MDTime = 3;
inline void ADStaringResult::clear_mdtime() {
  mdtime_ = 0;
}
inline ::google::protobuf::int32 ADStaringResult::mdtime() const {
  // @@protoc_insertion_point(field_get:com.htsc.mdc.insight.model.ADStaringResult.MDTime)
  return mdtime_;
}
inline void ADStaringResult::set_mdtime(::google::protobuf::int32 value) {
  
  mdtime_ = value;
  // @@protoc_insertion_point(field_set:com.htsc.mdc.insight.model.ADStaringResult.MDTime)
}

// optional int64 DataTimestamp = 4;
inline void ADStaringResult::clear_datatimestamp() {
  datatimestamp_ = GOOGLE_LONGLONG(0);
}
inline ::google::protobuf::int64 ADStaringResult::datatimestamp() const {
  // @@protoc_insertion_point(field_get:com.htsc.mdc.insight.model.ADStaringResult.DataTimestamp)
  return datatimestamp_;
}
inline void ADStaringResult::set_datatimestamp(::google::protobuf::int64 value) {
  
  datatimestamp_ = value;
  // @@protoc_insertion_point(field_set:com.htsc.mdc.insight.model.ADStaringResult.DataTimestamp)
}

// optional .com.htsc.mdc.model.ESecurityIDSource securityIDSource = 5;
inline void ADStaringResult::clear_securityidsource() {
  securityidsource_ = 0;
}
inline ::com::htsc::mdc::model::ESecurityIDSource ADStaringResult::securityidsource() const {
  // @@protoc_insertion_point(field_get:com.htsc.mdc.insight.model.ADStaringResult.securityIDSource)
  return static_cast< ::com::htsc::mdc::model::ESecurityIDSource >(securityidsource_);
}
inline void ADStaringResult::set_securityidsource(::com::htsc::mdc::model::ESecurityIDSource value) {
  
  securityidsource_ = value;
  // @@protoc_insertion_point(field_set:com.htsc.mdc.insight.model.ADStaringResult.securityIDSource)
}

// optional .com.htsc.mdc.model.ESecurityType securityType = 6;
inline void ADStaringResult::clear_securitytype() {
  securitytype_ = 0;
}
inline ::com::htsc::mdc::model::ESecurityType ADStaringResult::securitytype() const {
  // @@protoc_insertion_point(field_get:com.htsc.mdc.insight.model.ADStaringResult.securityType)
  return static_cast< ::com::htsc::mdc::model::ESecurityType >(securitytype_);
}
inline void ADStaringResult::set_securitytype(::com::htsc::mdc::model::ESecurityType value) {
  
  securitytype_ = value;
  // @@protoc_insertion_point(field_set:com.htsc.mdc.insight.model.ADStaringResult.securityType)
}

// optional int32 ExchangeDate = 7;
inline void ADStaringResult::clear_exchangedate() {
  exchangedate_ = 0;
}
inline ::google::protobuf::int32 ADStaringResult::exchangedate() const {
  // @@protoc_insertion_point(field_get:com.htsc.mdc.insight.model.ADStaringResult.ExchangeDate)
  return exchangedate_;
}
inline void ADStaringResult::set_exchangedate(::google::protobuf::int32 value) {
  
  exchangedate_ = value;
  // @@protoc_insertion_point(field_set:com.htsc.mdc.insight.model.ADStaringResult.ExchangeDate)
}

// optional int32 ExchangeTime = 8;
inline void ADStaringResult::clear_exchangetime() {
  exchangetime_ = 0;
}
inline ::google::protobuf::int32 ADStaringResult::exchangetime() const {
  // @@protoc_insertion_point(field_get:com.htsc.mdc.insight.model.ADStaringResult.ExchangeTime)
  return exchangetime_;
}
inline void ADStaringResult::set_exchangetime(::google::protobuf::int32 value) {
  
  exchangetime_ = value;
  // @@protoc_insertion_point(field_set:com.htsc.mdc.insight.model.ADStaringResult.ExchangeTime)
}

// optional string StaringResultID = 9;
inline void ADStaringResult::clear_staringresultid() {
  staringresultid_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& ADStaringResult::staringresultid() const {
  // @@protoc_insertion_point(field_get:com.htsc.mdc.insight.model.ADStaringResult.StaringResultID)
  return staringresultid_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void ADStaringResult::set_staringresultid(const ::std::string& value) {
  
  staringresultid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:com.htsc.mdc.insight.model.ADStaringResult.StaringResultID)
}
inline void ADStaringResult::set_staringresultid(const char* value) {
  
  staringresultid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:com.htsc.mdc.insight.model.ADStaringResult.StaringResultID)
}
inline void ADStaringResult::set_staringresultid(const char* value, size_t size) {
  
  staringresultid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:com.htsc.mdc.insight.model.ADStaringResult.StaringResultID)
}
inline ::std::string* ADStaringResult::mutable_staringresultid() {
  
  // @@protoc_insertion_point(field_mutable:com.htsc.mdc.insight.model.ADStaringResult.StaringResultID)
  return staringresultid_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* ADStaringResult::release_staringresultid() {
  // @@protoc_insertion_point(field_release:com.htsc.mdc.insight.model.ADStaringResult.StaringResultID)
  
  return staringresultid_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void ADStaringResult::set_allocated_staringresultid(::std::string* staringresultid) {
  if (staringresultid != NULL) {
    
  } else {
    
  }
  staringresultid_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), staringresultid);
  // @@protoc_insertion_point(field_set_allocated:com.htsc.mdc.insight.model.ADStaringResult.StaringResultID)
}

// optional string StrategyID = 10;
inline void ADStaringResult::clear_strategyid() {
  strategyid_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& ADStaringResult::strategyid() const {
  // @@protoc_insertion_point(field_get:com.htsc.mdc.insight.model.ADStaringResult.StrategyID)
  return strategyid_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void ADStaringResult::set_strategyid(const ::std::string& value) {
  
  strategyid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:com.htsc.mdc.insight.model.ADStaringResult.StrategyID)
}
inline void ADStaringResult::set_strategyid(const char* value) {
  
  strategyid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:com.htsc.mdc.insight.model.ADStaringResult.StrategyID)
}
inline void ADStaringResult::set_strategyid(const char* value, size_t size) {
  
  strategyid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:com.htsc.mdc.insight.model.ADStaringResult.StrategyID)
}
inline ::std::string* ADStaringResult::mutable_strategyid() {
  
  // @@protoc_insertion_point(field_mutable:com.htsc.mdc.insight.model.ADStaringResult.StrategyID)
  return strategyid_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* ADStaringResult::release_strategyid() {
  // @@protoc_insertion_point(field_release:com.htsc.mdc.insight.model.ADStaringResult.StrategyID)
  
  return strategyid_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void ADStaringResult::set_allocated_strategyid(::std::string* strategyid) {
  if (strategyid != NULL) {
    
  } else {
    
  }
  strategyid_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), strategyid);
  // @@protoc_insertion_point(field_set_allocated:com.htsc.mdc.insight.model.ADStaringResult.StrategyID)
}

// optional string AlgorithmID = 11;
inline void ADStaringResult::clear_algorithmid() {
  algorithmid_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& ADStaringResult::algorithmid() const {
  // @@protoc_insertion_point(field_get:com.htsc.mdc.insight.model.ADStaringResult.AlgorithmID)
  return algorithmid_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void ADStaringResult::set_algorithmid(const ::std::string& value) {
  
  algorithmid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:com.htsc.mdc.insight.model.ADStaringResult.AlgorithmID)
}
inline void ADStaringResult::set_algorithmid(const char* value) {
  
  algorithmid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:com.htsc.mdc.insight.model.ADStaringResult.AlgorithmID)
}
inline void ADStaringResult::set_algorithmid(const char* value, size_t size) {
  
  algorithmid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:com.htsc.mdc.insight.model.ADStaringResult.AlgorithmID)
}
inline ::std::string* ADStaringResult::mutable_algorithmid() {
  
  // @@protoc_insertion_point(field_mutable:com.htsc.mdc.insight.model.ADStaringResult.AlgorithmID)
  return algorithmid_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* ADStaringResult::release_algorithmid() {
  // @@protoc_insertion_point(field_release:com.htsc.mdc.insight.model.ADStaringResult.AlgorithmID)
  
  return algorithmid_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void ADStaringResult::set_allocated_algorithmid(::std::string* algorithmid) {
  if (algorithmid != NULL) {
    
  } else {
    
  }
  algorithmid_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), algorithmid);
  // @@protoc_insertion_point(field_set_allocated:com.htsc.mdc.insight.model.ADStaringResult.AlgorithmID)
}

// optional string AlgorithmName = 12;
inline void ADStaringResult::clear_algorithmname() {
  algorithmname_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& ADStaringResult::algorithmname() const {
  // @@protoc_insertion_point(field_get:com.htsc.mdc.insight.model.ADStaringResult.AlgorithmName)
  return algorithmname_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void ADStaringResult::set_algorithmname(const ::std::string& value) {
  
  algorithmname_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:com.htsc.mdc.insight.model.ADStaringResult.AlgorithmName)
}
inline void ADStaringResult::set_algorithmname(const char* value) {
  
  algorithmname_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:com.htsc.mdc.insight.model.ADStaringResult.AlgorithmName)
}
inline void ADStaringResult::set_algorithmname(const char* value, size_t size) {
  
  algorithmname_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:com.htsc.mdc.insight.model.ADStaringResult.AlgorithmName)
}
inline ::std::string* ADStaringResult::mutable_algorithmname() {
  
  // @@protoc_insertion_point(field_mutable:com.htsc.mdc.insight.model.ADStaringResult.AlgorithmName)
  return algorithmname_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* ADStaringResult::release_algorithmname() {
  // @@protoc_insertion_point(field_release:com.htsc.mdc.insight.model.ADStaringResult.AlgorithmName)
  
  return algorithmname_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void ADStaringResult::set_allocated_algorithmname(::std::string* algorithmname) {
  if (algorithmname != NULL) {
    
  } else {
    
  }
  algorithmname_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), algorithmname);
  // @@protoc_insertion_point(field_set_allocated:com.htsc.mdc.insight.model.ADStaringResult.AlgorithmName)
}

// optional string CustomerID = 13;
inline void ADStaringResult::clear_customerid() {
  customerid_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& ADStaringResult::customerid() const {
  // @@protoc_insertion_point(field_get:com.htsc.mdc.insight.model.ADStaringResult.CustomerID)
  return customerid_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void ADStaringResult::set_customerid(const ::std::string& value) {
  
  customerid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:com.htsc.mdc.insight.model.ADStaringResult.CustomerID)
}
inline void ADStaringResult::set_customerid(const char* value) {
  
  customerid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:com.htsc.mdc.insight.model.ADStaringResult.CustomerID)
}
inline void ADStaringResult::set_customerid(const char* value, size_t size) {
  
  customerid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:com.htsc.mdc.insight.model.ADStaringResult.CustomerID)
}
inline ::std::string* ADStaringResult::mutable_customerid() {
  
  // @@protoc_insertion_point(field_mutable:com.htsc.mdc.insight.model.ADStaringResult.CustomerID)
  return customerid_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* ADStaringResult::release_customerid() {
  // @@protoc_insertion_point(field_release:com.htsc.mdc.insight.model.ADStaringResult.CustomerID)
  
  return customerid_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void ADStaringResult::set_allocated_customerid(::std::string* customerid) {
  if (customerid != NULL) {
    
  } else {
    
  }
  customerid_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), customerid);
  // @@protoc_insertion_point(field_set_allocated:com.htsc.mdc.insight.model.ADStaringResult.CustomerID)
}

// optional string SystemID = 14;
inline void ADStaringResult::clear_systemid() {
  systemid_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& ADStaringResult::systemid() const {
  // @@protoc_insertion_point(field_get:com.htsc.mdc.insight.model.ADStaringResult.SystemID)
  return systemid_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void ADStaringResult::set_systemid(const ::std::string& value) {
  
  systemid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:com.htsc.mdc.insight.model.ADStaringResult.SystemID)
}
inline void ADStaringResult::set_systemid(const char* value) {
  
  systemid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:com.htsc.mdc.insight.model.ADStaringResult.SystemID)
}
inline void ADStaringResult::set_systemid(const char* value, size_t size) {
  
  systemid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:com.htsc.mdc.insight.model.ADStaringResult.SystemID)
}
inline ::std::string* ADStaringResult::mutable_systemid() {
  
  // @@protoc_insertion_point(field_mutable:com.htsc.mdc.insight.model.ADStaringResult.SystemID)
  return systemid_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* ADStaringResult::release_systemid() {
  // @@protoc_insertion_point(field_release:com.htsc.mdc.insight.model.ADStaringResult.SystemID)
  
  return systemid_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void ADStaringResult::set_allocated_systemid(::std::string* systemid) {
  if (systemid != NULL) {
    
  } else {
    
  }
  systemid_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), systemid);
  // @@protoc_insertion_point(field_set_allocated:com.htsc.mdc.insight.model.ADStaringResult.SystemID)
}

// optional int64 RmindValue = 15;
inline void ADStaringResult::clear_rmindvalue() {
  rmindvalue_ = GOOGLE_LONGLONG(0);
}
inline ::google::protobuf::int64 ADStaringResult::rmindvalue() const {
  // @@protoc_insertion_point(field_get:com.htsc.mdc.insight.model.ADStaringResult.RmindValue)
  return rmindvalue_;
}
inline void ADStaringResult::set_rmindvalue(::google::protobuf::int64 value) {
  
  rmindvalue_ = value;
  // @@protoc_insertion_point(field_set:com.htsc.mdc.insight.model.ADStaringResult.RmindValue)
}

// optional int64 RealCalValue = 16;
inline void ADStaringResult::clear_realcalvalue() {
  realcalvalue_ = GOOGLE_LONGLONG(0);
}
inline ::google::protobuf::int64 ADStaringResult::realcalvalue() const {
  // @@protoc_insertion_point(field_get:com.htsc.mdc.insight.model.ADStaringResult.RealCalValue)
  return realcalvalue_;
}
inline void ADStaringResult::set_realcalvalue(::google::protobuf::int64 value) {
  
  realcalvalue_ = value;
  // @@protoc_insertion_point(field_set:com.htsc.mdc.insight.model.ADStaringResult.RealCalValue)
}

// optional int32 DataMultiplePowerOf10 = 17;
inline void ADStaringResult::clear_datamultiplepowerof10() {
  datamultiplepowerof10_ = 0;
}
inline ::google::protobuf::int32 ADStaringResult::datamultiplepowerof10() const {
  // @@protoc_insertion_point(field_get:com.htsc.mdc.insight.model.ADStaringResult.DataMultiplePowerOf10)
  return datamultiplepowerof10_;
}
inline void ADStaringResult::set_datamultiplepowerof10(::google::protobuf::int32 value) {
  
  datamultiplepowerof10_ = value;
  // @@protoc_insertion_point(field_set:com.htsc.mdc.insight.model.ADStaringResult.DataMultiplePowerOf10)
}

inline const ADStaringResult* ADStaringResult::internal_default_instance() {
  return &ADStaringResult_default_instance_.get();
}
#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)

}  // namespace model
}  // namespace insight
}  // namespace mdc
}  // namespace htsc
}  // namespace com

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_ADStaringResult_2eproto__INCLUDED
