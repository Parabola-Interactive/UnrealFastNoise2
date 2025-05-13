#pragma once

#include "CoreMinimal.h"
#include "NoiseGeneration.generated.h"

UCLASS(Abstract)
class UNREALFASTNOISE2_API UNoiseGeneration : public UObject
{
	GENERATED_BODY()
	
public:
	static void GenPerlin2D(TArray<float>& Out, const int XStart, const int YStart, const int XSize, const int YSize, const float Frequency, const float Scale);
	static void GenPerlin2D(TArray<float>& Out, const int XStart, const int YStart, const int XSize, const int YSize, const float Frequency, const float Scale, const int Seed);
	static int GetRandomSeed();
};