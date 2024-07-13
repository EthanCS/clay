#pragma target 5.0

struct PSInput {
  float3 fragColor : TEXCOORD0;
};

struct PSOutput {
  float4 outColor : SV_Target0;
};

PSOutput main(PSInput input) {
  PSOutput output;
  output.outColor = float4(input.fragColor, 1.0f);
  return output;
}