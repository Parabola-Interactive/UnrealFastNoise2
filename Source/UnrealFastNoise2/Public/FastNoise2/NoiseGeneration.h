#pragma once

#include "CoreMinimal.h"
#include "NoiseGeneration.generated.h"

UCLASS(Abstract)
class UNREALFASTNOISE2_API UNoiseGeneration : public UObject
{
	GENERATED_BODY()

	static int GetRandomSeed();
	
public:
	static void GenPerlin2D(float* Out, int XSize, int YSize, float Frequency);
	static void GenPerlin2D(float* Out, int XSize, int YSize, float Frequency, int Seed);
};