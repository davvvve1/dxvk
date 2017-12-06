#pragma once

#include <array>

#include "d3d11_buffer.h"
#include "d3d11_shader.h"
#include "d3d11_state.h"
#include "d3d11_view.h"

namespace dxvk {
  
  struct D3D11ComputePipelineBindings {
    std::array<Com<D3D11Buffer>,              D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT> constantBuffers;
//     std::array<Com<D3D11ShaderResourceView>,  D3D11_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT>      shaderResourceViews;
//     std::array<Com<D3D11UnorderedAccessView>, D3D11_1_UAV_SLOT_COUNT>                            uniformAccessViews;
//     std::array<Com<D3D11SamplerState>,        D3D11_COMMONSHADER_SAMPLER_SLOT_COUNT>             samplers;
  };
  
  
  struct D3D11GraphicsPipelineBindings {
    std::array<Com<D3D11Buffer>,              D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT> constantBuffers;
//     std::array<Com<D3D11ShaderResourceView>,  D3D11_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT>      shaderResourceViews;
//     std::array<Com<D3D11SamplerState>,        D3D11_COMMONSHADER_SAMPLER_SLOT_COUNT>             samplers;
  };
  
  
  struct D3D11ContextStateVS {
    Com<D3D11VertexShader>        shader;
    D3D11GraphicsPipelineBindings bindings;
  };
  
  
  struct D3D11ContextStateHS {
    Com<D3D11HullShader>          shader;
    D3D11GraphicsPipelineBindings bindings;
  };
  
  
  struct D3D11ContextStateDS {
    Com<D3D11DomainShader>        shader;
    D3D11GraphicsPipelineBindings bindings;
  };
  
  
  struct D3D11ContextStateGS {
    Com<D3D11GeometryShader>      shader;
    D3D11GraphicsPipelineBindings bindings;
  };
  
  
  struct D3D11ContextStatePS {
    Com<D3D11PixelShader>         shader;
    D3D11GraphicsPipelineBindings bindings;
  };
  
  
  struct D3D11ContextStateCS {
    Com<D3D11ComputeShader>      shader;
    D3D11ComputePipelineBindings bindings;
  };
  
  
  struct D3D11ContextStateIA {
    
  };
  
  
  struct D3D11ContextStateOM {
    std::array<Com<D3D11RenderTargetView>, D3D11_SIMULTANEOUS_RENDER_TARGET_COUNT> renderTargetViews;
    
    Rc<DxvkFramebuffer> framebuffer;
  };
  
  
  struct D3D11ContextStateRS {
    uint32_t numViewports = 0;
    uint32_t numScissors  = 0;
    
    std::array<D3D11_VIEWPORT, D3D11_VIEWPORT_AND_SCISSORRECT_OBJECT_COUNT_PER_PIPELINE> viewports;
    std::array<D3D11_RECT,     D3D11_VIEWPORT_AND_SCISSORRECT_OBJECT_COUNT_PER_PIPELINE> scissors;
    
    Com<D3D11RasterizerState> state;
  };
  
  
  /**
   * \brief Context state
   */
  struct D3D11ContextState {
    D3D11ContextStateCS cs;
    D3D11ContextStateDS ds;
    D3D11ContextStateGS gs;
    D3D11ContextStateHS hs;
    D3D11ContextStatePS ps;
    D3D11ContextStateVS vs;
    
    D3D11ContextStateIA ia;
    D3D11ContextStateOM om;
    D3D11ContextStateRS rs;
  };
  
}