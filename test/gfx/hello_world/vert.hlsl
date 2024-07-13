#pragma target 5.0

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
  output.outPosition = float4(input.inPosition, 0.0f, 1.0f);
  output.fragColor = input.inColor;
  return output;
}