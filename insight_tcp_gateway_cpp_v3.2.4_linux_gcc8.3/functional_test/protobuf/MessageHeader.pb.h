// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: MessageHeader.proto

#ifndef PROTOBUF_MessageHeader_2eproto__INCLUDED
#define PROTOBUF_MessageHeader_2eproto__INCLUDED

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
// @@protoc_insertion_point(includes)

namespace com {
namespace htsc {
namespace mdc {
namespace insight {
namespace model {

// Internal implementation detail -- do not call these.
void protobuf_AddDesc_MessageHeader_2eproto();
void protobuf_InitDefaults_MessageHeader_2eproto();
void protobuf_AssignDesc_MessageHeader_2eproto();
void protobuf_ShutdownFile_MessageHeader_2eproto();

class MessageHeader;

// ===================================================================

class MessageHeader : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:com.htsc.mdc.insight.model.MessageHeader) */ {
 public:
  MessageHeader();
  virtual ~MessageHeader();

  MessageHeader(const MessageHeader& from);

  inline MessageHeader& operator=(const MessageHeader& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const MessageHeader& default_instance();

  static const MessageHeader* internal_default_instance();

  void Swap(MessageHeader* other);

  // implements Message ----------------------------------------------

  inline MessageHeader* New() const { return New(NULL); }

  MessageHeader* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const MessageHeader& from);
  void MergeFrom(const MessageHeader& from);
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
  void InternalSwap(MessageHeader* other);
  void UnsafeMergeFrom(const MessageHeader& from);
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

  // optional int32 appType = 1;
  void clear_apptype();
  static const int kAppTypeFieldNumber = 1;
  ::google::protobuf::int32 apptype() const;
  void set_apptype(::google::protobuf::int32 value);

  // optional int32 messageClassification = 2;
  void clear_messageclassification();
  static const int kMessageClassificationFieldNumber = 2;
  ::google::protobuf::int32 messageclassification() const;
  void set_messageclassification(::google::protobuf::int32 value);

  // optional int64 messageId = 3;
  void clear_messageid();
  static const int kMessageIdFieldNumber = 3;
  ::google::protobuf::int64 messageid() const;
  void set_messageid(::google::protobuf::int64 value);

  // optional int64 sendingTime = 4;
  void clear_sendingtime();
  static const int kSendingTimeFieldNumber = 4;
  ::google::protobuf::int64 sendingtime() const;
  void set_sendingtime(::google::protobuf::int64 value);

  // optional string senderId = 5;
  void clear_senderid();
  static const int kSenderIdFieldNumber = 5;
  const ::std::string& senderid() const;
  void set_senderid(const ::std::string& value);
  void set_senderid(const char* value);
  void set_senderid(const char* value, size_t size);
  ::std::string* mutable_senderid();
  ::std::string* release_senderid();
  void set_allocated_senderid(::std::string* senderid);

  // optional string targetId = 6;
  void clear_targetid();
  static const int kTargetIdFieldNumber = 6;
  const ::std::string& targetid() const;
  void set_targetid(const ::std::string& value);
  void set_targetid(const char* value);
  void set_targetid(const char* value, size_t size);
  ::std::string* mutable_targetid();
  ::std::string* release_targetid();
  void set_allocated_targetid(::std::string* targetid);

  // optional string traceId = 7;
  void clear_traceid();
  static const int kTraceIdFieldNumber = 7;
  const ::std::string& traceid() const;
  void set_traceid(const ::std::string& value);
  void set_traceid(const char* value);
  void set_traceid(const char* value, size_t size);
  ::std::string* mutable_traceid();
  ::std::string* release_traceid();
  void set_allocated_traceid(::std::string* traceid);

  // @@protoc_insertion_point(class_scope:com.htsc.mdc.insight.model.MessageHeader)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr senderid_;
  ::google::protobuf::internal::ArenaStringPtr targetid_;
  ::google::protobuf::internal::ArenaStringPtr traceid_;
  ::google::protobuf::int32 apptype_;
  ::google::protobuf::int32 messageclassification_;
  ::google::protobuf::int64 messageid_;
  ::google::protobuf::int64 sendingtime_;
  mutable int _cached_size_;
  friend void  protobuf_InitDefaults_MessageHeader_2eproto_impl();
  friend void  protobuf_AddDesc_MessageHeader_2eproto_impl();
  friend void protobuf_AssignDesc_MessageHeader_2eproto();
  friend void protobuf_ShutdownFile_MessageHeader_2eproto();

  void InitAsDefaultInstance();
};
extern ::google::protobuf::internal::ExplicitlyConstructed<MessageHeader> MessageHeader_default_instance_;

// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
// MessageHeader

// optional int32 appType = 1;
inline void MessageHeader::clear_apptype() {
  apptype_ = 0;
}
inline ::google::protobuf::int32 MessageHeader::apptype() const {
  // @@protoc_insertion_point(field_get:com.htsc.mdc.insight.model.MessageHeader.appType)
  return apptype_;
}
inline void MessageHeader::set_apptype(::google::protobuf::int32 value) {
  
  apptype_ = value;
  // @@protoc_insertion_point(field_set:com.htsc.mdc.insight.model.MessageHeader.appType)
}

// optional int32 messageClassification = 2;
inline void MessageHeader::clear_messageclassification() {
  messageclassification_ = 0;
}
inline ::google::protobuf::int32 MessageHeader::messageclassification() const {
  // @@protoc_insertion_point(field_get:com.htsc.mdc.insight.model.MessageHeader.messageClassification)
  return messageclassification_;
}
inline void MessageHeader::set_messageclassification(::google::protobuf::int32 value) {
  
  messageclassification_ = value;
  // @@protoc_insertion_point(field_set:com.htsc.mdc.insight.model.MessageHeader.messageClassification)
}

// optional int64 messageId = 3;
inline void MessageHeader::clear_messageid() {
  messageid_ = GOOGLE_LONGLONG(0);
}
inline ::google::protobuf::int64 MessageHeader::messageid() const {
  // @@protoc_insertion_point(field_get:com.htsc.mdc.insight.model.MessageHeader.messageId)
  return messageid_;
}
inline void MessageHeader::set_messageid(::google::protobuf::int64 value) {
  
  messageid_ = value;
  // @@protoc_insertion_point(field_set:com.htsc.mdc.insight.model.MessageHeader.messageId)
}

// optional int64 sendingTime = 4;
inline void MessageHeader::clear_sendingtime() {
  sendingtime_ = GOOGLE_LONGLONG(0);
}
inline ::google::protobuf::int64 MessageHeader::sendingtime() const {
  // @@protoc_insertion_point(field_get:com.htsc.mdc.insight.model.MessageHeader.sendingTime)
  return sendingtime_;
}
inline void MessageHeader::set_sendingtime(::google::protobuf::int64 value) {
  
  sendingtime_ = value;
  // @@protoc_insertion_point(field_set:com.htsc.mdc.insight.model.MessageHeader.sendingTime)
}

// optional string senderId = 5;
inline void MessageHeader::clear_senderid() {
  senderid_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& MessageHeader::senderid() const {
  // @@protoc_insertion_point(field_get:com.htsc.mdc.insight.model.MessageHeader.senderId)
  return senderid_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void MessageHeader::set_senderid(const ::std::string& value) {
  
  senderid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:com.htsc.mdc.insight.model.MessageHeader.senderId)
}
inline void MessageHeader::set_senderid(const char* value) {
  
  senderid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:com.htsc.mdc.insight.model.MessageHeader.senderId)
}
inline void MessageHeader::set_senderid(const char* value, size_t size) {
  
  senderid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:com.htsc.mdc.insight.model.MessageHeader.senderId)
}
inline ::std::string* MessageHeader::mutable_senderid() {
  
  // @@protoc_insertion_point(field_mutable:com.htsc.mdc.insight.model.MessageHeader.senderId)
  return senderid_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* MessageHeader::release_senderid() {
  // @@protoc_insertion_point(field_release:com.htsc.mdc.insight.model.MessageHeader.senderId)
  
  return senderid_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void MessageHeader::set_allocated_senderid(::std::string* senderid) {
  if (senderid != NULL) {
    
  } else {
    
  }
  senderid_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), senderid);
  // @@protoc_insertion_point(field_set_allocated:com.htsc.mdc.insight.model.MessageHeader.senderId)
}

// optional string targetId = 6;
inline void MessageHeader::clear_targetid() {
  targetid_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& MessageHeader::targetid() const {
  // @@protoc_insertion_point(field_get:com.htsc.mdc.insight.model.MessageHeader.targetId)
  return targetid_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void MessageHeader::set_targetid(const ::std::string& value) {
  
  targetid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:com.htsc.mdc.insight.model.MessageHeader.targetId)
}
inline void MessageHeader::set_targetid(const char* value) {
  
  targetid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:com.htsc.mdc.insight.model.MessageHeader.targetId)
}
inline void MessageHeader::set_targetid(const char* value, size_t size) {
  
  targetid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:com.htsc.mdc.insight.model.MessageHeader.targetId)
}
inline ::std::string* MessageHeader::mutable_targetid() {
  
  // @@protoc_insertion_point(field_mutable:com.htsc.mdc.insight.model.MessageHeader.targetId)
  return targetid_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* MessageHeader::release_targetid() {
  // @@protoc_insertion_point(field_release:com.htsc.mdc.insight.model.MessageHeader.targetId)
  
  return targetid_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void MessageHeader::set_allocated_targetid(::std::string* targetid) {
  if (targetid != NULL) {
    
  } else {
    
  }
  targetid_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), targetid);
  // @@protoc_insertion_point(field_set_allocated:com.htsc.mdc.insight.model.MessageHeader.targetId)
}

// optional string traceId = 7;
inline void MessageHeader::clear_traceid() {
  traceid_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& MessageHeader::traceid() const {
  // @@protoc_insertion_point(field_get:com.htsc.mdc.insight.model.MessageHeader.traceId)
  return traceid_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void MessageHeader::set_traceid(const ::std::string& value) {
  
  traceid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:com.htsc.mdc.insight.model.MessageHeader.traceId)
}
inline void MessageHeader::set_traceid(const char* value) {
  
  traceid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:com.htsc.mdc.insight.model.MessageHeader.traceId)
}
inline void MessageHeader::set_traceid(const char* value, size_t size) {
  
  traceid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:com.htsc.mdc.insight.model.MessageHeader.traceId)
}
inline ::std::string* MessageHeader::mutable_traceid() {
  
  // @@protoc_insertion_point(field_mutable:com.htsc.mdc.insight.model.MessageHeader.traceId)
  return traceid_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* MessageHeader::release_traceid() {
  // @@protoc_insertion_point(field_release:com.htsc.mdc.insight.model.MessageHeader.traceId)
  
  return traceid_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void MessageHeader::set_allocated_traceid(::std::string* traceid) {
  if (traceid != NULL) {
    
  } else {
    
  }
  traceid_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), traceid);
  // @@protoc_insertion_point(field_set_allocated:com.htsc.mdc.insight.model.MessageHeader.traceId)
}

inline const MessageHeader* MessageHeader::internal_default_instance() {
  return &MessageHeader_default_instance_.get();
}
#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)

}  // namespace model
}  // namespace insight
}  // namespace mdc
}  // namespace htsc
}  // namespace com

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_MessageHeader_2eproto__INCLUDED
