#include "FastNoise2/NoiseGeneration.h"

#include "FastNoise/FastNoise.h"

int UNoiseGeneration::GetRandomSeed()
{
	return FMath::RandRange(INT_MIN, INT_MAX);
}

void UNoiseGeneration::GenPerlin2D(TArray<float>& Out, const int XSize, const int YSize, const float Frequency)
{
	return GenPerlin2D(Out, XSize, YSize, Frequency, GetRandomSeed());
}

void UNoiseGeneration::GenPerlin2D(TArray<float>& Out, const int XSize, const int YSize, const float Frequency, const int Seed)
{
	const FastNoise::SmartNode<FastNoise::Perlin> Noise = FastNoise::New<FastNoise::Perlin>();

	const int ElemCount = XSize * YSize;
	float* Result = new float[ElemCount];
	Noise->GenTileable2D(Result, XSize, YSize, Frequency, Seed);

	Out.Reserve(ElemCount);
	for (int i = 0; i < ElemCount; i++) Out.Add(Result[i]);
}
