#include <gpu_performance_api/gpu_perf_api.h>
#include <gpu_performance_api/gpu_perf_api_counters.h>
#include <gpu_performance_api/gpu_perf_api_interface_loader.h>
#include <gpu_performance_api/gpu_perf_api_vk.h>

#undef NDEBUG
#include <cassert>

// The interface loader requires its function table list to be defined in
// exactly one translation unit.
//
GpaFuncTableInfo* gpa_function_table_info = nullptr;

int main ()
{
  // Function tables.
  //
  {
    GpaFunctionTable t;
    assert (t.major_version == GPA_FUNCTION_TABLE_MAJOR_VERSION_NUMBER);
    assert (t.minor_version == sizeof (GpaFunctionTable));
    assert (t.GpaGetVersion == nullptr && t.GpaInitialize == nullptr);

    GpaCounterLibFuncTable c;
    assert (c.gpa_counter_lib_major_version ==
            GPA_COUNTER_LIB_FUNC_TABLE_MAJOR_VERSION);
    assert (c.gpa_counter_lib_minor_version == sizeof (GpaCounterLibFuncTable));
    assert (!c.IsInit ());
  }

  // Vulkan context open information.
  //
  {
    GpaVkContextOpenInfo i {VK_NULL_HANDLE, VK_NULL_HANDLE, VK_NULL_HANDLE};
    assert (i.instance == VK_NULL_HANDLE && i.device == VK_NULL_HANDLE);

    GpaOpenContextFlags f (kGpaOpenContextVkUseInfoType2);
    assert (f == static_cast<GpaOpenContextFlags> (
                   kGpaOpenContextApiSpecificOptionsStart));
  }

  // Interface loader.
  //
  {
    GpaApiManager* m (GpaApiManager::Instance ());

#ifdef _WIN32
    assert (m->GetLibraryFileName (kGpaApiVulkan) ==
            TFORMAT ("GPUPerfAPIVK-x64.dll"));
    assert (m->GetLibraryFileName (kGpaApiDirectx12) ==
            TFORMAT ("GPUPerfAPIDX12-x64.dll"));
#else
    assert (m->GetLibraryFileName (kGpaApiVulkan) ==
            TFORMAT ("libGPUPerfAPIVK.so"));
#endif

    assert (m->GetLibraryFullPath (kGpaApiOpengl, TFORMAT ("plugins\\gpa")) ==
            TFORMAT ("plugins/gpa/") + m->GetLibraryFileName (kGpaApiOpengl));

    assert (m->LoadApi (kGpaApiNoSupport) == kGpaStatusErrorApiNotSupported);
    assert (m->LoadApi (kGpaApiVulkan, TFORMAT ("no-such-directory")) ==
            kGpaStatusErrorLibLoadFailed);
    assert (m->GetFunctionTable (kGpaApiVulkan) == nullptr);

    GpaApiManager::DeleteInstance ();
    assert (gpa_function_table_info == nullptr);
  }
}
