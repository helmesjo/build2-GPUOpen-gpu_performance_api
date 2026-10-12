#include <cstring>

// As in upstream, the headers rely on the COM and Direct3D declarations
// (IUnknown, ID3D11DeviceContext, ID3D12GraphicsCommandList, etc).
//
#include <d3d11.h>
#include <d3d12.h>

#include <AmdDxExtApi.h>
#include <AmdDxExtASICInfoApi.h>
#include <AmdDxExtPerfProfileApi.h>
#include <AmdDxCounter.h>
#include <AmdExtD3D.h>
#include <AmdExtD3DDeviceApi.h>
#include <AmdExtD3DCommandListMarkerApi.h>
#include <AmdExtGpaInterfaceApi.h>

#undef NDEBUG
#include <cassert>

int main ()
{
  using namespace std;

  // DX10 and DX11 extension.
  //
  {
    AmdDxExtVersion v;
    memset (&v, 0, sizeof (v));
    assert (v.majorVersion == 0 && v.minorVersion == 0);

    assert (AmdDxExtPrimitiveTopology_TriangleList == 4);
    assert (AmdDxExtPrimitiveTopology_ExtQuadList <
            AmdDxExtPrimitiveTopology_Max);
    assert (AmdDxExtFeature_DeviceCtxSupport == 3);

    // Function pointer types for the entry points exported by the driver.
    //
    PFNAmdDxExtCreate c10 (nullptr);
    PFNAmdDxExtCreate11 c11 (nullptr);
    assert (c10 == nullptr && c11 == nullptr);

    IAmdDxExt* e (nullptr);
    assert (e == nullptr);
  }

  // DX11 ASIC information and performance profiling extensions.
  //
  {
    assert (AmdDxExtASICInfoID != AmdDxExtPerfProfileID);

    AmdDxASICInfo i;
    memset (&i, 0, sizeof (i));
    assert (i.gpuCount == 0);

    AmdDxASICInfoParam p {&i};
    assert (p.pASICInfo->gpuCount == 0);

    assert (PE_OK == 0);
    assert (AmdGpuTime < AmdCounterIdMax);

    IAmdDxExtASICInfo* ai (nullptr);
    IAmdDxExtPerfProfile* pp (nullptr);
    assert (ai == nullptr && pp == nullptr);
  }

  // DX12 extension.
  //
  {
    PFNAmdExtD3DCreateInterface c (nullptr);
    assert (c == nullptr);

    AmdExtD3DPipelineCreateInfo ci;
    memset (&ci, 0, sizeof (ci));
    ci.type = AmdExtD3DStructPipelineState;
    ci.flags.depthBoundsTestEnable = 1;
    assert (ci.pNext == nullptr && ci.flags.reserved == 0);

    IAmdExtD3DFactory* f (nullptr);
    IAmdExtD3DDevice1* d (nullptr);
    IAmdExtD3DCommandListMarker* m (nullptr);
    assert (f == nullptr && d == nullptr && m == nullptr);
  }

  // DX12 GPU Performance API (GPA) extension.
  //
  {
    AmdExtGpaSampleConfig sc;
    memset (&sc, 0, sizeof (sc));
    sc.type = AmdExtGpaSampleType::Timing;
    assert (sc.type == AmdExtGpaSampleType::Timing);

    IAmdExtGpaInterface2* g (nullptr);
    IAmdExtGpaSession* s (nullptr);
    assert (g == nullptr && s == nullptr);
  }
}
