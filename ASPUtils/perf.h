/* This file was auto-generated from perf.man by ctrpp.exe */

#pragma once


#define CacheEntries (1)
#define CacheHits (2)
#define CacheMisses (3)

EXTERN_C DECLSPEC_SELECTANY GUID ASPUtilsGuid = { 0x7f664769, 0x598, 0x4af2, 0xbf, 0x8a, 0x2, 0x59, 0x4a, 0x3f, 0x38, 0x1 };

EXTERN_C DECLSPEC_SELECTANY GUID ASPUtilsCacheCountersGuid = { 0x4fde97aa, 0x2412, 0x420d, 0x91, 0x6c, 0xd1, 0x14, 0x76, 0x92, 0xa7, 0xe7 };


EXTERN_C DECLSPEC_SELECTANY HANDLE ASPUtils = NULL;

EXTERN_C DECLSPEC_SELECTANY struct {
    PERF_COUNTERSET_INFO CounterSet;
    PERF_COUNTER_INFO Counter0;
    PERF_COUNTER_INFO Counter1;
    PERF_COUNTER_INFO Counter2;
} ASPUtilsCacheCountersInfo = {
    { { 0x4fde97aa, 0x2412, 0x420d, 0x91, 0x6c, 0xd1, 0x14, 0x76, 0x92, 0xa7, 0xe7 }, { 0x7f664769, 0x598, 0x4af2, 0xbf, 0x8a, 0x2, 0x59, 0x4a, 0x3f, 0x38, 0x1 }, 3, PERF_COUNTERSET_MULTI_INSTANCES },
    { 1, PERF_COUNTER_RAWCOUNT, PERF_ATTRIB_BY_REFERENCE, sizeof(ULONG), PERF_DETAIL_NOVICE, 0, 0 },
    { 2, PERF_COUNTER_COUNTER, PERF_ATTRIB_BY_REFERENCE, sizeof(ULONG), PERF_DETAIL_NOVICE, 0, 0 },
    { 3, PERF_COUNTER_COUNTER, PERF_ATTRIB_BY_REFERENCE, sizeof(ULONG), PERF_DETAIL_NOVICE, 0, 0 },
};

EXTERN_C FORCEINLINE
VOID
CounterCleanup(
    VOID
    )
{
    if (ASPUtils != NULL) {
        PerfStopProvider(ASPUtils);
        ASPUtils = NULL;
    }
}

EXTERN_C FORCEINLINE
ULONG
CounterInitialize(
    VOID
    )
{
    ULONG Status;
    PERF_PROVIDER_CONTEXT ProviderContext;

    ZeroMemory(&ProviderContext, sizeof(PERF_PROVIDER_CONTEXT));
    ProviderContext.ContextSize = sizeof(PERF_PROVIDER_CONTEXT);

    Status = PerfStartProviderEx(&ASPUtilsGuid,
                                 &ProviderContext,
                                 &ASPUtils);
    if (Status != ERROR_SUCCESS) {
        ASPUtils = NULL;
        return Status;
    }

    Status = PerfSetCounterSetInfo(ASPUtils,
                                   &ASPUtilsCacheCountersInfo.CounterSet,
                                   sizeof ASPUtilsCacheCountersInfo);
    if (Status != ERROR_SUCCESS) {
        CounterCleanup();
        return Status;
    }
    return ERROR_SUCCESS;
}
