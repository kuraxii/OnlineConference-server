// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: return_info_room.proto

#include "return_info_room.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>

PROTOBUF_PRAGMA_INIT_SEG

namespace _pb = ::PROTOBUF_NAMESPACE_ID;
namespace _pbi = _pb::internal;

namespace return_info {
PROTOBUF_CONSTEXPR ReturnInfoMultipleRooms::ReturnInfoMultipleRooms(
    ::_pbi::ConstantInitialized): _impl_{
    /*decltype(_impl_.roomnumbers_)*/{}
  , /*decltype(_impl_.ip_)*/{&::_pbi::fixed_address_empty_string, ::_pbi::ConstantInitialized{}}
  , /*decltype(_impl_.port_)*/0u
  , /*decltype(_impl_._cached_size_)*/{}} {}
struct ReturnInfoMultipleRoomsDefaultTypeInternal {
  PROTOBUF_CONSTEXPR ReturnInfoMultipleRoomsDefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~ReturnInfoMultipleRoomsDefaultTypeInternal() {}
  union {
    ReturnInfoMultipleRooms _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 ReturnInfoMultipleRoomsDefaultTypeInternal _ReturnInfoMultipleRooms_default_instance_;
}  // namespace return_info
static ::_pb::Metadata file_level_metadata_return_5finfo_5froom_2eproto[1];
static constexpr ::_pb::EnumDescriptor const** file_level_enum_descriptors_return_5finfo_5froom_2eproto = nullptr;
static constexpr ::_pb::ServiceDescriptor const** file_level_service_descriptors_return_5finfo_5froom_2eproto = nullptr;

const uint32_t TableStruct_return_5finfo_5froom_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::return_info::ReturnInfoMultipleRooms, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::return_info::ReturnInfoMultipleRooms, _impl_.ip_),
  PROTOBUF_FIELD_OFFSET(::return_info::ReturnInfoMultipleRooms, _impl_.port_),
  PROTOBUF_FIELD_OFFSET(::return_info::ReturnInfoMultipleRooms, _impl_.roomnumbers_),
};
static const ::_pbi::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, -1, sizeof(::return_info::ReturnInfoMultipleRooms)},
};

static const ::_pb::Message* const file_default_instances[] = {
  &::return_info::_ReturnInfoMultipleRooms_default_instance_._instance,
};

const char descriptor_table_protodef_return_5finfo_5froom_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\026return_info_room.proto\022\013return_info\"H\n"
  "\027ReturnInfoMultipleRooms\022\n\n\002ip\030\001 \001(\t\022\014\n\004"
  "port\030\002 \001(\r\022\023\n\013roomNumbers\030\003 \003(\tb\006proto3"
  ;
static ::_pbi::once_flag descriptor_table_return_5finfo_5froom_2eproto_once;
const ::_pbi::DescriptorTable descriptor_table_return_5finfo_5froom_2eproto = {
    false, false, 119, descriptor_table_protodef_return_5finfo_5froom_2eproto,
    "return_info_room.proto",
    &descriptor_table_return_5finfo_5froom_2eproto_once, nullptr, 0, 1,
    schemas, file_default_instances, TableStruct_return_5finfo_5froom_2eproto::offsets,
    file_level_metadata_return_5finfo_5froom_2eproto, file_level_enum_descriptors_return_5finfo_5froom_2eproto,
    file_level_service_descriptors_return_5finfo_5froom_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::_pbi::DescriptorTable* descriptor_table_return_5finfo_5froom_2eproto_getter() {
  return &descriptor_table_return_5finfo_5froom_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2 static ::_pbi::AddDescriptorsRunner dynamic_init_dummy_return_5finfo_5froom_2eproto(&descriptor_table_return_5finfo_5froom_2eproto);
namespace return_info {

// ===================================================================

class ReturnInfoMultipleRooms::_Internal {
 public:
};

ReturnInfoMultipleRooms::ReturnInfoMultipleRooms(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor(arena, is_message_owned);
  // @@protoc_insertion_point(arena_constructor:return_info.ReturnInfoMultipleRooms)
}
ReturnInfoMultipleRooms::ReturnInfoMultipleRooms(const ReturnInfoMultipleRooms& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  ReturnInfoMultipleRooms* const _this = this; (void)_this;
  new (&_impl_) Impl_{
      decltype(_impl_.roomnumbers_){from._impl_.roomnumbers_}
    , decltype(_impl_.ip_){}
    , decltype(_impl_.port_){}
    , /*decltype(_impl_._cached_size_)*/{}};

  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  _impl_.ip_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.ip_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_ip().empty()) {
    _this->_impl_.ip_.Set(from._internal_ip(), 
      _this->GetArenaForAllocation());
  }
  _this->_impl_.port_ = from._impl_.port_;
  // @@protoc_insertion_point(copy_constructor:return_info.ReturnInfoMultipleRooms)
}

inline void ReturnInfoMultipleRooms::SharedCtor(
    ::_pb::Arena* arena, bool is_message_owned) {
  (void)arena;
  (void)is_message_owned;
  new (&_impl_) Impl_{
      decltype(_impl_.roomnumbers_){arena}
    , decltype(_impl_.ip_){}
    , decltype(_impl_.port_){0u}
    , /*decltype(_impl_._cached_size_)*/{}
  };
  _impl_.ip_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.ip_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
}

ReturnInfoMultipleRooms::~ReturnInfoMultipleRooms() {
  // @@protoc_insertion_point(destructor:return_info.ReturnInfoMultipleRooms)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void ReturnInfoMultipleRooms::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  _impl_.roomnumbers_.~RepeatedPtrField();
  _impl_.ip_.Destroy();
}

void ReturnInfoMultipleRooms::SetCachedSize(int size) const {
  _impl_._cached_size_.Set(size);
}

void ReturnInfoMultipleRooms::Clear() {
// @@protoc_insertion_point(message_clear_start:return_info.ReturnInfoMultipleRooms)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _impl_.roomnumbers_.Clear();
  _impl_.ip_.ClearToEmpty();
  _impl_.port_ = 0u;
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* ReturnInfoMultipleRooms::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // string ip = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 10)) {
          auto str = _internal_mutable_ip();
          ptr = ::_pbi::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
          CHK_(::_pbi::VerifyUTF8(str, "return_info.ReturnInfoMultipleRooms.ip"));
        } else
          goto handle_unusual;
        continue;
      // uint32 port = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 16)) {
          _impl_.port_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // repeated string roomNumbers = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 26)) {
          ptr -= 1;
          do {
            ptr += 1;
            auto str = _internal_add_roomnumbers();
            ptr = ::_pbi::InlineGreedyStringParser(str, ptr, ctx);
            CHK_(ptr);
            CHK_(::_pbi::VerifyUTF8(str, "return_info.ReturnInfoMultipleRooms.roomNumbers"));
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<26>(ptr));
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

uint8_t* ReturnInfoMultipleRooms::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:return_info.ReturnInfoMultipleRooms)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // string ip = 1;
  if (!this->_internal_ip().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_ip().data(), static_cast<int>(this->_internal_ip().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "return_info.ReturnInfoMultipleRooms.ip");
    target = stream->WriteStringMaybeAliased(
        1, this->_internal_ip(), target);
  }

  // uint32 port = 2;
  if (this->_internal_port() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteUInt32ToArray(2, this->_internal_port(), target);
  }

  // repeated string roomNumbers = 3;
  for (int i = 0, n = this->_internal_roomnumbers_size(); i < n; i++) {
    const auto& s = this->_internal_roomnumbers(i);
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      s.data(), static_cast<int>(s.length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "return_info.ReturnInfoMultipleRooms.roomNumbers");
    target = stream->WriteString(3, s, target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:return_info.ReturnInfoMultipleRooms)
  return target;
}

size_t ReturnInfoMultipleRooms::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:return_info.ReturnInfoMultipleRooms)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated string roomNumbers = 3;
  total_size += 1 *
      ::PROTOBUF_NAMESPACE_ID::internal::FromIntSize(_impl_.roomnumbers_.size());
  for (int i = 0, n = _impl_.roomnumbers_.size(); i < n; i++) {
    total_size += ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
      _impl_.roomnumbers_.Get(i));
  }

  // string ip = 1;
  if (!this->_internal_ip().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_ip());
  }

  // uint32 port = 2;
  if (this->_internal_port() != 0) {
    total_size += ::_pbi::WireFormatLite::UInt32SizePlusOne(this->_internal_port());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData ReturnInfoMultipleRooms::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSourceCheck,
    ReturnInfoMultipleRooms::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*ReturnInfoMultipleRooms::GetClassData() const { return &_class_data_; }


void ReturnInfoMultipleRooms::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg) {
  auto* const _this = static_cast<ReturnInfoMultipleRooms*>(&to_msg);
  auto& from = static_cast<const ReturnInfoMultipleRooms&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:return_info.ReturnInfoMultipleRooms)
  GOOGLE_DCHECK_NE(&from, _this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  _this->_impl_.roomnumbers_.MergeFrom(from._impl_.roomnumbers_);
  if (!from._internal_ip().empty()) {
    _this->_internal_set_ip(from._internal_ip());
  }
  if (from._internal_port() != 0) {
    _this->_internal_set_port(from._internal_port());
  }
  _this->_internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void ReturnInfoMultipleRooms::CopyFrom(const ReturnInfoMultipleRooms& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:return_info.ReturnInfoMultipleRooms)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ReturnInfoMultipleRooms::IsInitialized() const {
  return true;
}

void ReturnInfoMultipleRooms::InternalSwap(ReturnInfoMultipleRooms* other) {
  using std::swap;
  auto* lhs_arena = GetArenaForAllocation();
  auto* rhs_arena = other->GetArenaForAllocation();
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  _impl_.roomnumbers_.InternalSwap(&other->_impl_.roomnumbers_);
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &_impl_.ip_, lhs_arena,
      &other->_impl_.ip_, rhs_arena
  );
  swap(_impl_.port_, other->_impl_.port_);
}

::PROTOBUF_NAMESPACE_ID::Metadata ReturnInfoMultipleRooms::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_return_5finfo_5froom_2eproto_getter, &descriptor_table_return_5finfo_5froom_2eproto_once,
      file_level_metadata_return_5finfo_5froom_2eproto[0]);
}

// @@protoc_insertion_point(namespace_scope)
}  // namespace return_info
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::return_info::ReturnInfoMultipleRooms*
Arena::CreateMaybeMessage< ::return_info::ReturnInfoMultipleRooms >(Arena* arena) {
  return Arena::CreateMessageInternal< ::return_info::ReturnInfoMultipleRooms >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
