#pragma once

#include "CoreMinimal.h"
#include "NoiseGeneration.generated.h"

UCLASS(Abstract)
class UNREALFASTNOISE2_API UNoiseGeneration : public UObject
{
	GENERATED_BODY()

	static int GetRandomSeed();
	
public:
	static void GenPerlin2D(TArray<float>& Out, const int XSize, const int YSize, const float Frequency, const float Scale);
	static void GenPerlin2D(TArray<float>& Out, const int XSize, const int YSize, const float Frequency, const float Scale, const int Seed);
};