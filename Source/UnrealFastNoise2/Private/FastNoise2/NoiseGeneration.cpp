#include "FastNoise2/NoiseGeneration.h"

#include "FastNoise/FastNoise.h"

int UNoiseGeneration::GetRandomSeed()
{
	constexpr int64 Min = INT_MIN;
	constexpr int64 Max = INT_MAX;
	return FMath::RandRange(Min, Max);
}

void UNoiseGeneration::GenPerlin2D(TArray<float>& Out, const int XStart, const int YStart, const int XSize, const int YSize, const float Frequency, const float Scale)
{
	const int Seed = GetRandomSeed();
	return GenPerlin2D(Out, XStart, YStart, XSize, YSize, Frequency, Scale, Seed);
}

void UNoiseGeneration::GenPerlin2D(TArray<float>& Out, const int XStart, const int YStart, const int XSize, const int YSize, const float Frequency, const float Scale, const int Seed)
{
	const FastNoise::SmartNode<FastNoise::Perlin> Noise = FastNoise::New<FastNoise::Perlin>();

	const int ElemCount = XSize * YSize;
	float* Result = new float[ElemCount];
	Noise->GenUniformGrid2D(Result, XStart, YStart, XSize, YSize, Frequency, Seed);

	Out.Reserve(ElemCount);
	for (int i = 0; i < ElemCount; i++) Out.Add(Result[i] * Scale);
}
