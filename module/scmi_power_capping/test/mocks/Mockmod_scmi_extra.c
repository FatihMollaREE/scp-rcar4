/* AUTOGENERATED FILE. DO NOT EDIT. */
#include <string.h>
#include <stdlib.h>
#include <setjmp.h>
#include "cmock.h"
#include "Mockmod_scmi_extra.h"

static const char* CMockString_agent_count = "agent_count";
static const char* CMockString_agent_id = "agent_id";
static const char* CMockString_get_agent_count = "get_agent_count";
static const char* CMockString_get_agent_id = "get_agent_id";
static const char* CMockString_payload = "payload";
static const char* CMockString_respond = "respond";
static const char* CMockString_service_id = "service_id";
static const char* CMockString_size = "size";

typedef struct _CMOCK_get_agent_count_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  char ExpectAnyArgsBool;
  int ReturnVal;
  unsigned int* Expected_agent_count;
  int Expected_agent_count_Depth;
  char ReturnThruPtr_agent_count_Used;
  unsigned int* ReturnThruPtr_agent_count_Val;
  size_t ReturnThruPtr_agent_count_Size;
  char IgnoreArg_agent_count;

} CMOCK_get_agent_count_CALL_INSTANCE;

typedef struct _CMOCK_get_agent_id_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  char ExpectAnyArgsBool;
  int ReturnVal;
  fwk_id_t Expected_service_id;
  unsigned int* Expected_agent_id;
  int Expected_agent_id_Depth;
  char ReturnThruPtr_agent_id_Used;
  unsigned int* ReturnThruPtr_agent_id_Val;
  size_t ReturnThruPtr_agent_id_Size;
  char IgnoreArg_service_id;
  char IgnoreArg_agent_id;

} CMOCK_get_agent_id_CALL_INSTANCE;

typedef struct _CMOCK_respond_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  char ExpectAnyArgsBool;
  int ReturnVal;
  fwk_id_t Expected_service_id;
  const void* Expected_payload;
  size_t Expected_size;
  int Expected_payload_Depth;
  char IgnoreArg_service_id;
  char IgnoreArg_payload;
  char IgnoreArg_size;

} CMOCK_respond_CALL_INSTANCE;

static struct Mockmod_scmi_extraInstance
{
  char get_agent_count_IgnoreBool;
  int get_agent_count_FinalReturn;
  char get_agent_count_CallbackBool;
  CMOCK_get_agent_count_CALLBACK get_agent_count_CallbackFunctionPointer;
  int get_agent_count_CallbackCalls;
  CMOCK_MEM_INDEX_TYPE get_agent_count_CallInstance;
  char get_agent_id_IgnoreBool;
  int get_agent_id_FinalReturn;
  char get_agent_id_CallbackBool;
  CMOCK_get_agent_id_CALLBACK get_agent_id_CallbackFunctionPointer;
  int get_agent_id_CallbackCalls;
  CMOCK_MEM_INDEX_TYPE get_agent_id_CallInstance;
  char respond_IgnoreBool;
  int respond_FinalReturn;
  char respond_CallbackBool;
  CMOCK_respond_CALLBACK respond_CallbackFunctionPointer;
  int respond_CallbackCalls;
  CMOCK_MEM_INDEX_TYPE respond_CallInstance;
} Mock;

extern jmp_buf AbortFrame;

void Mockmod_scmi_extra_Verify(void)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_MEM_INDEX_TYPE call_instance;
  call_instance = Mock.get_agent_count_CallInstance;
  if (Mock.get_agent_count_IgnoreBool)
    call_instance = CMOCK_GUTS_NONE;
  if (CMOCK_GUTS_NONE != call_instance)
  {
    UNITY_SET_DETAIL(CMockString_get_agent_count);
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledLess);
  }
  if (Mock.get_agent_count_CallbackFunctionPointer != NULL)
  {
    call_instance = CMOCK_GUTS_NONE;
    (void)call_instance;
  }
  call_instance = Mock.get_agent_id_CallInstance;
  if (Mock.get_agent_id_IgnoreBool)
    call_instance = CMOCK_GUTS_NONE;
  if (CMOCK_GUTS_NONE != call_instance)
  {
    UNITY_SET_DETAIL(CMockString_get_agent_id);
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledLess);
  }
  if (Mock.get_agent_id_CallbackFunctionPointer != NULL)
  {
    call_instance = CMOCK_GUTS_NONE;
    (void)call_instance;
  }
  call_instance = Mock.respond_CallInstance;
  if (Mock.respond_IgnoreBool)
    call_instance = CMOCK_GUTS_NONE;
  if (CMOCK_GUTS_NONE != call_instance)
  {
    UNITY_SET_DETAIL(CMockString_respond);
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledLess);
  }
  if (Mock.respond_CallbackFunctionPointer != NULL)
  {
    call_instance = CMOCK_GUTS_NONE;
    (void)call_instance;
  }
}

void Mockmod_scmi_extra_Init(void)
{
  Mockmod_scmi_extra_Destroy();
}

void Mockmod_scmi_extra_Destroy(void)
{
  CMock_Guts_MemFreeAll();
  memset(&Mock, 0, sizeof(Mock));
}

int get_agent_count(unsigned int* agent_count)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_get_agent_count_CALL_INSTANCE* cmock_call_instance;
  UNITY_SET_DETAIL(CMockString_get_agent_count);
  cmock_call_instance = (CMOCK_get_agent_count_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.get_agent_count_CallInstance);
  Mock.get_agent_count_CallInstance = CMock_Guts_MemNext(Mock.get_agent_count_CallInstance);
  if (Mock.get_agent_count_IgnoreBool)
  {
    UNITY_CLR_DETAILS();
    if (cmock_call_instance == NULL)
      return Mock.get_agent_count_FinalReturn;
    Mock.get_agent_count_FinalReturn = cmock_call_instance->ReturnVal;
    return cmock_call_instance->ReturnVal;
  }
  if (!Mock.get_agent_count_CallbackBool &&
      Mock.get_agent_count_CallbackFunctionPointer != NULL)
  {
    int cmock_cb_ret = Mock.get_agent_count_CallbackFunctionPointer(agent_count, Mock.get_agent_count_CallbackCalls++);
    UNITY_CLR_DETAILS();
    return cmock_cb_ret;
  }
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringCalledMore);
  cmock_line = cmock_call_instance->LineNumber;
  if (!cmock_call_instance->ExpectAnyArgsBool)
  {
  if (!cmock_call_instance->IgnoreArg_agent_count)
  {
    UNITY_SET_DETAILS(CMockString_get_agent_count,CMockString_agent_count);
    if (cmock_call_instance->Expected_agent_count == NULL)
      { UNITY_TEST_ASSERT_NULL(agent_count, cmock_line, CMockStringExpNULL); }
    else
      { UNITY_TEST_ASSERT_EQUAL_HEX32_ARRAY(cmock_call_instance->Expected_agent_count, agent_count, cmock_call_instance->Expected_agent_count_Depth, cmock_line, CMockStringMismatch); }
  }
  }
  if (Mock.get_agent_count_CallbackFunctionPointer != NULL)
  {
    cmock_call_instance->ReturnVal = Mock.get_agent_count_CallbackFunctionPointer(agent_count, Mock.get_agent_count_CallbackCalls++);
  }
  if (cmock_call_instance->ReturnThruPtr_agent_count_Used)
  {
    UNITY_TEST_ASSERT_NOT_NULL(agent_count, cmock_line, CMockStringPtrIsNULL);
    memcpy((void*)agent_count, (void*)cmock_call_instance->ReturnThruPtr_agent_count_Val,
      cmock_call_instance->ReturnThruPtr_agent_count_Size);
  }
  UNITY_CLR_DETAILS();
  return cmock_call_instance->ReturnVal;
}

void CMockExpectParameters_get_agent_count(CMOCK_get_agent_count_CALL_INSTANCE* cmock_call_instance, unsigned int* agent_count, int agent_count_Depth);
void CMockExpectParameters_get_agent_count(CMOCK_get_agent_count_CALL_INSTANCE* cmock_call_instance, unsigned int* agent_count, int agent_count_Depth)
{
  cmock_call_instance->Expected_agent_count = agent_count;
  cmock_call_instance->Expected_agent_count_Depth = agent_count_Depth;
  cmock_call_instance->IgnoreArg_agent_count = 0;
  cmock_call_instance->ReturnThruPtr_agent_count_Used = 0;
}

void get_agent_count_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, int cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_get_agent_count_CALL_INSTANCE));
  CMOCK_get_agent_count_CALL_INSTANCE* cmock_call_instance = (CMOCK_get_agent_count_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.get_agent_count_CallInstance = CMock_Guts_MemChain(Mock.get_agent_count_CallInstance, cmock_guts_index);
  Mock.get_agent_count_IgnoreBool = (char)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->ExpectAnyArgsBool = (char)0;
  cmock_call_instance->ReturnVal = cmock_to_return;
  Mock.get_agent_count_IgnoreBool = (char)1;
}

void get_agent_count_CMockStopIgnore(void)
{
  if(Mock.get_agent_count_IgnoreBool)
    Mock.get_agent_count_CallInstance = CMock_Guts_MemNext(Mock.get_agent_count_CallInstance);
  Mock.get_agent_count_IgnoreBool = (char)0;
}

void get_agent_count_CMockExpectAnyArgsAndReturn(UNITY_LINE_TYPE cmock_line, int cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_get_agent_count_CALL_INSTANCE));
  CMOCK_get_agent_count_CALL_INSTANCE* cmock_call_instance = (CMOCK_get_agent_count_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.get_agent_count_CallInstance = CMock_Guts_MemChain(Mock.get_agent_count_CallInstance, cmock_guts_index);
  Mock.get_agent_count_IgnoreBool = (char)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->ExpectAnyArgsBool = (char)0;
  cmock_call_instance->ReturnVal = cmock_to_return;
  cmock_call_instance->ExpectAnyArgsBool = (char)1;
}

void get_agent_count_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, unsigned int* agent_count, int cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_get_agent_count_CALL_INSTANCE));
  CMOCK_get_agent_count_CALL_INSTANCE* cmock_call_instance = (CMOCK_get_agent_count_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.get_agent_count_CallInstance = CMock_Guts_MemChain(Mock.get_agent_count_CallInstance, cmock_guts_index);
  Mock.get_agent_count_IgnoreBool = (char)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->ExpectAnyArgsBool = (char)0;
  CMockExpectParameters_get_agent_count(cmock_call_instance, agent_count, 1);
  cmock_call_instance->ReturnVal = cmock_to_return;
}

void get_agent_count_AddCallback(CMOCK_get_agent_count_CALLBACK Callback)
{
  Mock.get_agent_count_IgnoreBool = (char)0;
  Mock.get_agent_count_CallbackBool = (char)1;
  Mock.get_agent_count_CallbackFunctionPointer = Callback;
}

void get_agent_count_Stub(CMOCK_get_agent_count_CALLBACK Callback)
{
  Mock.get_agent_count_IgnoreBool = (char)0;
  Mock.get_agent_count_CallbackBool = (char)0;
  Mock.get_agent_count_CallbackFunctionPointer = Callback;
}

void get_agent_count_CMockExpectWithArrayAndReturn(UNITY_LINE_TYPE cmock_line, unsigned int* agent_count, int agent_count_Depth, int cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_get_agent_count_CALL_INSTANCE));
  CMOCK_get_agent_count_CALL_INSTANCE* cmock_call_instance = (CMOCK_get_agent_count_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.get_agent_count_CallInstance = CMock_Guts_MemChain(Mock.get_agent_count_CallInstance, cmock_guts_index);
  Mock.get_agent_count_IgnoreBool = (char)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->ExpectAnyArgsBool = (char)0;
  CMockExpectParameters_get_agent_count(cmock_call_instance, agent_count, agent_count_Depth);
  cmock_call_instance->ReturnVal = cmock_to_return;
}

void get_agent_count_CMockReturnMemThruPtr_agent_count(UNITY_LINE_TYPE cmock_line, unsigned int* agent_count, size_t cmock_size)
{
  CMOCK_get_agent_count_CALL_INSTANCE* cmock_call_instance = (CMOCK_get_agent_count_CALL_INSTANCE*)CMock_Guts_GetAddressFor(CMock_Guts_MemEndOfChain(Mock.get_agent_count_CallInstance));
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringPtrPreExp);
  cmock_call_instance->ReturnThruPtr_agent_count_Used = 1;
  cmock_call_instance->ReturnThruPtr_agent_count_Val = agent_count;
  cmock_call_instance->ReturnThruPtr_agent_count_Size = cmock_size;
}

void get_agent_count_CMockIgnoreArg_agent_count(UNITY_LINE_TYPE cmock_line)
{
  CMOCK_get_agent_count_CALL_INSTANCE* cmock_call_instance = (CMOCK_get_agent_count_CALL_INSTANCE*)CMock_Guts_GetAddressFor(CMock_Guts_MemEndOfChain(Mock.get_agent_count_CallInstance));
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringIgnPreExp);
  cmock_call_instance->IgnoreArg_agent_count = 1;
}

int get_agent_id(fwk_id_t service_id, unsigned int* agent_id)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_get_agent_id_CALL_INSTANCE* cmock_call_instance;
  UNITY_SET_DETAIL(CMockString_get_agent_id);
  cmock_call_instance = (CMOCK_get_agent_id_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.get_agent_id_CallInstance);
  Mock.get_agent_id_CallInstance = CMock_Guts_MemNext(Mock.get_agent_id_CallInstance);
  if (Mock.get_agent_id_IgnoreBool)
  {
    UNITY_CLR_DETAILS();
    if (cmock_call_instance == NULL)
      return Mock.get_agent_id_FinalReturn;
    Mock.get_agent_id_FinalReturn = cmock_call_instance->ReturnVal;
    return cmock_call_instance->ReturnVal;
  }
  if (!Mock.get_agent_id_CallbackBool &&
      Mock.get_agent_id_CallbackFunctionPointer != NULL)
  {
    int cmock_cb_ret = Mock.get_agent_id_CallbackFunctionPointer(service_id, agent_id, Mock.get_agent_id_CallbackCalls++);
    UNITY_CLR_DETAILS();
    return cmock_cb_ret;
  }
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringCalledMore);
  cmock_line = cmock_call_instance->LineNumber;
  if (!cmock_call_instance->ExpectAnyArgsBool)
  {
  if (!cmock_call_instance->IgnoreArg_service_id)
  {
    UNITY_SET_DETAILS(CMockString_get_agent_id,CMockString_service_id);
    UNITY_TEST_ASSERT_EQUAL_MEMORY((void*)(&cmock_call_instance->Expected_service_id), (void*)(&service_id), sizeof(fwk_id_t), cmock_line, CMockStringMismatch);
  }
  if (!cmock_call_instance->IgnoreArg_agent_id)
  {
    UNITY_SET_DETAILS(CMockString_get_agent_id,CMockString_agent_id);
    if (cmock_call_instance->Expected_agent_id == NULL)
      { UNITY_TEST_ASSERT_NULL(agent_id, cmock_line, CMockStringExpNULL); }
    else
      { UNITY_TEST_ASSERT_EQUAL_HEX32_ARRAY(cmock_call_instance->Expected_agent_id, agent_id, cmock_call_instance->Expected_agent_id_Depth, cmock_line, CMockStringMismatch); }
  }
  }
  if (Mock.get_agent_id_CallbackFunctionPointer != NULL)
  {
    cmock_call_instance->ReturnVal = Mock.get_agent_id_CallbackFunctionPointer(service_id, agent_id, Mock.get_agent_id_CallbackCalls++);
  }
  if (cmock_call_instance->ReturnThruPtr_agent_id_Used)
  {
    UNITY_TEST_ASSERT_NOT_NULL(agent_id, cmock_line, CMockStringPtrIsNULL);
    memcpy((void*)agent_id, (void*)cmock_call_instance->ReturnThruPtr_agent_id_Val,
      cmock_call_instance->ReturnThruPtr_agent_id_Size);
  }
  UNITY_CLR_DETAILS();
  return cmock_call_instance->ReturnVal;
}

void CMockExpectParameters_get_agent_id(CMOCK_get_agent_id_CALL_INSTANCE* cmock_call_instance, fwk_id_t service_id, unsigned int* agent_id, int agent_id_Depth);
void CMockExpectParameters_get_agent_id(CMOCK_get_agent_id_CALL_INSTANCE* cmock_call_instance, fwk_id_t service_id, unsigned int* agent_id, int agent_id_Depth)
{
  memcpy((void*)(&cmock_call_instance->Expected_service_id), (void*)(&service_id),
         sizeof(fwk_id_t[sizeof(service_id) == sizeof(fwk_id_t) ? 1 : -1])); /* add fwk_id_t to :treat_as_array if this causes an error */
  cmock_call_instance->IgnoreArg_service_id = 0;
  cmock_call_instance->Expected_agent_id = agent_id;
  cmock_call_instance->Expected_agent_id_Depth = agent_id_Depth;
  cmock_call_instance->IgnoreArg_agent_id = 0;
  cmock_call_instance->ReturnThruPtr_agent_id_Used = 0;
}

void get_agent_id_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, int cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_get_agent_id_CALL_INSTANCE));
  CMOCK_get_agent_id_CALL_INSTANCE* cmock_call_instance = (CMOCK_get_agent_id_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.get_agent_id_CallInstance = CMock_Guts_MemChain(Mock.get_agent_id_CallInstance, cmock_guts_index);
  Mock.get_agent_id_IgnoreBool = (char)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->ExpectAnyArgsBool = (char)0;
  cmock_call_instance->ReturnVal = cmock_to_return;
  Mock.get_agent_id_IgnoreBool = (char)1;
}

void get_agent_id_CMockStopIgnore(void)
{
  if(Mock.get_agent_id_IgnoreBool)
    Mock.get_agent_id_CallInstance = CMock_Guts_MemNext(Mock.get_agent_id_CallInstance);
  Mock.get_agent_id_IgnoreBool = (char)0;
}

void get_agent_id_CMockExpectAnyArgsAndReturn(UNITY_LINE_TYPE cmock_line, int cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_get_agent_id_CALL_INSTANCE));
  CMOCK_get_agent_id_CALL_INSTANCE* cmock_call_instance = (CMOCK_get_agent_id_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.get_agent_id_CallInstance = CMock_Guts_MemChain(Mock.get_agent_id_CallInstance, cmock_guts_index);
  Mock.get_agent_id_IgnoreBool = (char)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->ExpectAnyArgsBool = (char)0;
  cmock_call_instance->ReturnVal = cmock_to_return;
  cmock_call_instance->ExpectAnyArgsBool = (char)1;
}

void get_agent_id_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, fwk_id_t service_id, unsigned int* agent_id, int cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_get_agent_id_CALL_INSTANCE));
  CMOCK_get_agent_id_CALL_INSTANCE* cmock_call_instance = (CMOCK_get_agent_id_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.get_agent_id_CallInstance = CMock_Guts_MemChain(Mock.get_agent_id_CallInstance, cmock_guts_index);
  Mock.get_agent_id_IgnoreBool = (char)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->ExpectAnyArgsBool = (char)0;
  CMockExpectParameters_get_agent_id(cmock_call_instance, service_id, agent_id, 1);
  cmock_call_instance->ReturnVal = cmock_to_return;
}

void get_agent_id_AddCallback(CMOCK_get_agent_id_CALLBACK Callback)
{
  Mock.get_agent_id_IgnoreBool = (char)0;
  Mock.get_agent_id_CallbackBool = (char)1;
  Mock.get_agent_id_CallbackFunctionPointer = Callback;
}

void get_agent_id_Stub(CMOCK_get_agent_id_CALLBACK Callback)
{
  Mock.get_agent_id_IgnoreBool = (char)0;
  Mock.get_agent_id_CallbackBool = (char)0;
  Mock.get_agent_id_CallbackFunctionPointer = Callback;
}

void get_agent_id_CMockExpectWithArrayAndReturn(UNITY_LINE_TYPE cmock_line, fwk_id_t service_id, unsigned int* agent_id, int agent_id_Depth, int cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_get_agent_id_CALL_INSTANCE));
  CMOCK_get_agent_id_CALL_INSTANCE* cmock_call_instance = (CMOCK_get_agent_id_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.get_agent_id_CallInstance = CMock_Guts_MemChain(Mock.get_agent_id_CallInstance, cmock_guts_index);
  Mock.get_agent_id_IgnoreBool = (char)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->ExpectAnyArgsBool = (char)0;
  CMockExpectParameters_get_agent_id(cmock_call_instance, service_id, agent_id, agent_id_Depth);
  cmock_call_instance->ReturnVal = cmock_to_return;
}

void get_agent_id_CMockReturnMemThruPtr_agent_id(UNITY_LINE_TYPE cmock_line, unsigned int* agent_id, size_t cmock_size)
{
  CMOCK_get_agent_id_CALL_INSTANCE* cmock_call_instance = (CMOCK_get_agent_id_CALL_INSTANCE*)CMock_Guts_GetAddressFor(CMock_Guts_MemEndOfChain(Mock.get_agent_id_CallInstance));
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringPtrPreExp);
  cmock_call_instance->ReturnThruPtr_agent_id_Used = 1;
  cmock_call_instance->ReturnThruPtr_agent_id_Val = agent_id;
  cmock_call_instance->ReturnThruPtr_agent_id_Size = cmock_size;
}

void get_agent_id_CMockIgnoreArg_service_id(UNITY_LINE_TYPE cmock_line)
{
  CMOCK_get_agent_id_CALL_INSTANCE* cmock_call_instance = (CMOCK_get_agent_id_CALL_INSTANCE*)CMock_Guts_GetAddressFor(CMock_Guts_MemEndOfChain(Mock.get_agent_id_CallInstance));
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringIgnPreExp);
  cmock_call_instance->IgnoreArg_service_id = 1;
}

void get_agent_id_CMockIgnoreArg_agent_id(UNITY_LINE_TYPE cmock_line)
{
  CMOCK_get_agent_id_CALL_INSTANCE* cmock_call_instance = (CMOCK_get_agent_id_CALL_INSTANCE*)CMock_Guts_GetAddressFor(CMock_Guts_MemEndOfChain(Mock.get_agent_id_CallInstance));
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringIgnPreExp);
  cmock_call_instance->IgnoreArg_agent_id = 1;
}

int respond(fwk_id_t service_id, const void* payload, size_t size)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_respond_CALL_INSTANCE* cmock_call_instance;
  UNITY_SET_DETAIL(CMockString_respond);
  cmock_call_instance = (CMOCK_respond_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.respond_CallInstance);
  Mock.respond_CallInstance = CMock_Guts_MemNext(Mock.respond_CallInstance);
  if (Mock.respond_IgnoreBool)
  {
    UNITY_CLR_DETAILS();
    if (cmock_call_instance == NULL)
      return Mock.respond_FinalReturn;
    Mock.respond_FinalReturn = cmock_call_instance->ReturnVal;
    return cmock_call_instance->ReturnVal;
  }
  if (!Mock.respond_CallbackBool &&
      Mock.respond_CallbackFunctionPointer != NULL)
  {
    int cmock_cb_ret = Mock.respond_CallbackFunctionPointer(service_id, payload, size, Mock.respond_CallbackCalls++);
    UNITY_CLR_DETAILS();
    return cmock_cb_ret;
  }
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringCalledMore);
  cmock_line = cmock_call_instance->LineNumber;
  if (!cmock_call_instance->ExpectAnyArgsBool)
  {
  if (!cmock_call_instance->IgnoreArg_service_id)
  {
    UNITY_SET_DETAILS(CMockString_respond,CMockString_service_id);
    UNITY_TEST_ASSERT_EQUAL_MEMORY((void*)(&cmock_call_instance->Expected_service_id), (void*)(&service_id), sizeof(fwk_id_t), cmock_line, CMockStringMismatch);
  }
  if (!cmock_call_instance->IgnoreArg_payload)
  {
    UNITY_SET_DETAILS(CMockString_respond,CMockString_payload);
    if (cmock_call_instance->Expected_payload == NULL)
      { UNITY_TEST_ASSERT_NULL(payload, cmock_line, CMockStringExpNULL); }
    else
      { UNITY_TEST_ASSERT_EQUAL_HEX8_ARRAY(cmock_call_instance->Expected_payload, payload, cmock_call_instance->Expected_payload_Depth, cmock_line, CMockStringMismatch); }
  }
  if (!cmock_call_instance->IgnoreArg_size)
  {
    UNITY_SET_DETAILS(CMockString_respond,CMockString_size);
    UNITY_TEST_ASSERT_EQUAL_MEMORY((void*)(&cmock_call_instance->Expected_size), (void*)(&size), sizeof(size_t), cmock_line, CMockStringMismatch);
  }
  }
  if (Mock.respond_CallbackFunctionPointer != NULL)
  {
    cmock_call_instance->ReturnVal = Mock.respond_CallbackFunctionPointer(service_id, payload, size, Mock.respond_CallbackCalls++);
  }
  UNITY_CLR_DETAILS();
  return cmock_call_instance->ReturnVal;
}

void CMockExpectParameters_respond(CMOCK_respond_CALL_INSTANCE* cmock_call_instance, fwk_id_t service_id, const void* payload, int payload_Depth, size_t size);
void CMockExpectParameters_respond(CMOCK_respond_CALL_INSTANCE* cmock_call_instance, fwk_id_t service_id, const void* payload, int payload_Depth, size_t size)
{
  memcpy((void*)(&cmock_call_instance->Expected_service_id), (void*)(&service_id),
         sizeof(fwk_id_t[sizeof(service_id) == sizeof(fwk_id_t) ? 1 : -1])); /* add fwk_id_t to :treat_as_array if this causes an error */
  cmock_call_instance->IgnoreArg_service_id = 0;
  cmock_call_instance->Expected_payload = payload;
  cmock_call_instance->Expected_payload_Depth = payload_Depth;
  cmock_call_instance->IgnoreArg_payload = 0;
  memcpy((void*)(&cmock_call_instance->Expected_size), (void*)(&size),
         sizeof(size_t[sizeof(size) == sizeof(size_t) ? 1 : -1])); /* add size_t to :treat_as_array if this causes an error */
  cmock_call_instance->IgnoreArg_size = 0;
}

void respond_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, int cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_respond_CALL_INSTANCE));
  CMOCK_respond_CALL_INSTANCE* cmock_call_instance = (CMOCK_respond_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.respond_CallInstance = CMock_Guts_MemChain(Mock.respond_CallInstance, cmock_guts_index);
  Mock.respond_IgnoreBool = (char)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->ExpectAnyArgsBool = (char)0;
  cmock_call_instance->ReturnVal = cmock_to_return;
  Mock.respond_IgnoreBool = (char)1;
}

void respond_CMockStopIgnore(void)
{
  if(Mock.respond_IgnoreBool)
    Mock.respond_CallInstance = CMock_Guts_MemNext(Mock.respond_CallInstance);
  Mock.respond_IgnoreBool = (char)0;
}

void respond_CMockExpectAnyArgsAndReturn(UNITY_LINE_TYPE cmock_line, int cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_respond_CALL_INSTANCE));
  CMOCK_respond_CALL_INSTANCE* cmock_call_instance = (CMOCK_respond_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.respond_CallInstance = CMock_Guts_MemChain(Mock.respond_CallInstance, cmock_guts_index);
  Mock.respond_IgnoreBool = (char)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->ExpectAnyArgsBool = (char)0;
  cmock_call_instance->ReturnVal = cmock_to_return;
  cmock_call_instance->ExpectAnyArgsBool = (char)1;
}

void respond_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, fwk_id_t service_id, const void* payload, size_t size, int cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_respond_CALL_INSTANCE));
  CMOCK_respond_CALL_INSTANCE* cmock_call_instance = (CMOCK_respond_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.respond_CallInstance = CMock_Guts_MemChain(Mock.respond_CallInstance, cmock_guts_index);
  Mock.respond_IgnoreBool = (char)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->ExpectAnyArgsBool = (char)0;
  CMockExpectParameters_respond(cmock_call_instance, service_id, payload, size, size);
  cmock_call_instance->ReturnVal = cmock_to_return;
}

void respond_AddCallback(CMOCK_respond_CALLBACK Callback)
{
  Mock.respond_IgnoreBool = (char)0;
  Mock.respond_CallbackBool = (char)1;
  Mock.respond_CallbackFunctionPointer = Callback;
}

void respond_Stub(CMOCK_respond_CALLBACK Callback)
{
  Mock.respond_IgnoreBool = (char)0;
  Mock.respond_CallbackBool = (char)0;
  Mock.respond_CallbackFunctionPointer = Callback;
}

void respond_CMockExpectWithArrayAndReturn(UNITY_LINE_TYPE cmock_line, fwk_id_t service_id, const void* payload, int payload_Depth, size_t size, int cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_respond_CALL_INSTANCE));
  CMOCK_respond_CALL_INSTANCE* cmock_call_instance = (CMOCK_respond_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.respond_CallInstance = CMock_Guts_MemChain(Mock.respond_CallInstance, cmock_guts_index);
  Mock.respond_IgnoreBool = (char)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->ExpectAnyArgsBool = (char)0;
  CMockExpectParameters_respond(cmock_call_instance, service_id, payload, payload_Depth, size);
  cmock_call_instance->ReturnVal = cmock_to_return;
}

void respond_CMockIgnoreArg_service_id(UNITY_LINE_TYPE cmock_line)
{
  CMOCK_respond_CALL_INSTANCE* cmock_call_instance = (CMOCK_respond_CALL_INSTANCE*)CMock_Guts_GetAddressFor(CMock_Guts_MemEndOfChain(Mock.respond_CallInstance));
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringIgnPreExp);
  cmock_call_instance->IgnoreArg_service_id = 1;
}

void respond_CMockIgnoreArg_payload(UNITY_LINE_TYPE cmock_line)
{
  CMOCK_respond_CALL_INSTANCE* cmock_call_instance = (CMOCK_respond_CALL_INSTANCE*)CMock_Guts_GetAddressFor(CMock_Guts_MemEndOfChain(Mock.respond_CallInstance));
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringIgnPreExp);
  cmock_call_instance->IgnoreArg_payload = 1;
}

void respond_CMockIgnoreArg_size(UNITY_LINE_TYPE cmock_line)
{
  CMOCK_respond_CALL_INSTANCE* cmock_call_instance = (CMOCK_respond_CALL_INSTANCE*)CMock_Guts_GetAddressFor(CMock_Guts_MemEndOfChain(Mock.respond_CallInstance));
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringIgnPreExp);
  cmock_call_instance->IgnoreArg_size = 1;
}

