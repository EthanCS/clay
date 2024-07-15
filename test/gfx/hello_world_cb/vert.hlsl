#pragma target 6.0

cbuffer MyBuffer : register(b0) {
  float4x4 model;
  float4x4 view;
  float4x4 proj;
};

struct VSInput {
  float2 inPosition : POSITION;
  float3 inColor : COLOR;
};

struct VSOutput {
  float3 fragColor : COLOR;
  float4 outPosition : SV_Position;
};

VSOutput main(VSInput input) {
  VSOutput output;
  output.outPosition =
      mul(mul(mul(float4(input.inPosition, 0.0, 1.0), model), view), proj);
  output.fragColor = input.inColor;
  return output;
}