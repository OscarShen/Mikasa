#pragma once

#include "CoreMinimal.h"
/*-----------------------------------------------------------------------------
	Floating point constants.
-----------------------------------------------------------------------------*/

#undef  PI
#define PI 					(3.1415926535897932f)	/* Extra digits if needed: 3.1415926535897932384626433832795f */
#define SMALL_NUMBER		(1.e-8f)
#define KINDA_SMALL_NUMBER	(1.e-4f)
#define BIG_NUMBER			(3.4e+38f)
#define EULERS_NUMBER       (2.71828182845904523536f)
#define UE_GOLDEN_RATIO		(1.6180339887498948482045868343656381f)	/* Also known as divine proportion, golden mean, or golden section - related to the Fibonacci Sequence = (1 + sqrt(5)) / 2 */
#define FLOAT_NON_FRACTIONAL (8388608.f) /* All single-precision floating point numbers greater than or equal to this have no fractional value. */

// Copied from float.h
#define MAX_FLT 3.402823466e+38F

// Aux constants.
#define INV_PI			(0.31830988618f)
#define HALF_PI			(1.57079632679f)

// Common square roots
#define UE_SQRT_2		(1.4142135623730950488016887242097f)
#define UE_SQRT_3		(1.7320508075688772935274463415059f)
#define UE_INV_SQRT_2	(0.70710678118654752440084436210485f)
#define UE_INV_SQRT_3	(0.57735026918962576450914878050196f)
#define UE_HALF_SQRT_2	(0.70710678118654752440084436210485f)
#define UE_HALF_SQRT_3	(0.86602540378443864676372317075294f)


// Magic numbers for numerical precision.
#define DELTA			(0.00001f)

/**
 * Lengths of normalized vectors (These are half their maximum values
 * to assure that dot products with normalized vectors don't overflow).
 */
#define FLOAT_NORMAL_THRESH				(0.0001f)

 //
 // Magic numbers for numerical precision.
 //
#define THRESH_POINT_ON_PLANE			(0.10f)		/* Thickness of plane for front/back/inside test */
#define THRESH_POINT_ON_SIDE			(0.20f)		/* Thickness of polygon side's side-plane for point-inside/outside/on side test */
#define THRESH_POINTS_ARE_SAME			(0.00002f)	/* Two points are same if within this distance */
#define THRESH_POINTS_ARE_NEAR			(0.015f)	/* Two points are near if within this distance and can be combined if imprecise math is ok */
#define THRESH_NORMALS_ARE_SAME			(0.00002f)	/* Two normal points are same if within this distance */
#define THRESH_UVS_ARE_SAME			    (0.0009765625f)/* Two UV are same if within this threshold (1.0f/1024f) */
													/* Making this too large results in incorrect CSG classification and disaster */
#define THRESH_VECTORS_ARE_NEAR			(0.0004f)	/* Two vectors are near if within this distance and can be combined if imprecise math is ok */
													/* Making this too large results in lighting problems due to inaccurate texture coordinates */
#define THRESH_SPLIT_POLY_WITH_PLANE	(0.25f)		/* A plane splits a polygon in half */
#define THRESH_SPLIT_POLY_PRECISELY		(0.01f)		/* A plane exactly splits a polygon */
#define THRESH_ZERO_NORM_SQUARED		(0.0001f)	/* Size of a unit normal that is considered "zero", squared */
#define THRESH_NORMALS_ARE_PARALLEL		(0.999845f)	/* Two unit vectors are parallel if abs(A dot B) is greater than or equal to this. This is roughly cosine(1.0 degrees). */
#define THRESH_NORMALS_ARE_ORTHOGONAL	(0.017455f)	/* Two unit vectors are orthogonal (perpendicular) if abs(A dot B) is less than or equal this. This is roughly cosine(89.0 degrees). */

#define THRESH_VECTOR_NORMALIZED		(0.01f)		/** Allowed error for a normalized vector (against squared magnitude) */
#define THRESH_QUAT_NORMALIZED			(0.01f)		/** Allowed error for a normalized quaternion (against squared magnitude) */

/*-----------------------------------------------------------------------------
	Global functions.
-----------------------------------------------------------------------------*/

/**
 * Structure for all math helper functions
 */
struct CORE_API FMath
{
	/**
	* Converts a float to an integer with truncation towards zero.
	* @param F		Floating point value to convert
	* @return		Truncated integer.
	*/
	static constexpr int32_t TruncToInt(float F)
	{
		return (int32_t)F;
	}

	/**
	 * Converts a float to an integer value with truncation towards zero.
	 * @param F		Floating point value to convert
	 * @return		Truncated integer value.
	 */
	static  float TruncToFloat(float F)
	{
		return truncf(F);
	}

	/**
	 * Converts a double to an integer value with truncation towards zero.
	 * @param F		Floating point value to convert
	 * @return		Truncated integer value.
	 */
	static  double TruncToDouble(double F)
	{
		return trunc(F);
	}

	/**
	 * Converts a float to a nearest less or equal integer.
	 * @param F		Floating point value to convert
	 * @return		An integer less or equal to 'F'.
	 */
	static  int32_t FloorToInt(float F)
	{
		return TruncToInt(floorf(F));
	}

	/**
	* Converts a float to the nearest less or equal integer.
	* @param F		Floating point value to convert
	* @return		An integer less or equal to 'F'.
	*/
	static  float FloorToFloat(float F)
	{
		return floorf(F);
	}

	/**
	* Converts a double to a less or equal integer.
	* @param F		Floating point value to convert
	* @return		The nearest integer value to 'F'.
	*/
	static  double FloorToDouble(double F)
	{
		return floor(F);
	}

	/**
	 * Converts a float to the nearest integer. Rounds up when the fraction is .5
	 * @param F		Floating point value to convert
	 * @return		The nearest integer to 'F'.
	 */
	static  int32_t RoundToInt(float F)
	{
		return FloorToInt(F + 0.5f);
	}

	/**
	* Converts a float to the nearest integer. Rounds up when the fraction is .5
	* @param F		Floating point value to convert
	* @return		The nearest integer to 'F'.
	*/
	static  float RoundToFloat(float F)
	{
		return FloorToFloat(F + 0.5f);
	}

	/**
	* Converts a double to the nearest integer. Rounds up when the fraction is .5
	* @param F		Floating point value to convert
	* @return		The nearest integer to 'F'.
	*/
	static  double RoundToDouble(double F)
	{
		return FloorToDouble(F + 0.5);
	}

	/**
	* Converts a float to the nearest greater or equal integer.
	* @param F		Floating point value to convert
	* @return		An integer greater or equal to 'F'.
	*/
	static  int32_t CeilToInt(float F)
	{
		return TruncToInt(ceilf(F));
	}

	/**
	* Converts a float to the nearest greater or equal integer.
	* @param F		Floating point value to convert
	* @return		An integer greater or equal to 'F'.
	*/
	static  float CeilToFloat(float F)
	{
		return ceilf(F);
	}

	/**
	* Converts a double to the nearest greater or equal integer.
	* @param F		Floating point value to convert
	* @return		An integer greater or equal to 'F'.
	*/
	static  double CeilToDouble(double F)
	{
		return ceil(F);
	}

	/**
	* Returns signed fractional part of a float.
	* @param Value	Floating point value to convert
	* @return		A float between >=0 and < 1 for nonnegative input. A float between >= -1 and < 0 for negative input.
	*/
	static  float Fractional(float Value)
	{
		return Value - TruncToFloat(Value);
	}

	/**
	* Returns the fractional part of a float.
	* @param Value	Floating point value to convert
	* @return		A float between >=0 and < 1.
	*/
	static  float Frac(float Value)
	{
		return Value - FloorToFloat(Value);
	}

	/**
	* Breaks the given value into an integral and a fractional part.
	* @param InValue	Floating point value to convert
	* @param OutIntPart Floating point value that receives the integral part of the number.
	* @return			The fractional part of the number.
	*/
	static  float Modf(const float InValue, float* OutIntPart)
	{
		return modff(InValue, OutIntPart);
	}

	/**
	* Breaks the given value into an integral and a fractional part.
	* @param InValue	Floating point value to convert
	* @param OutIntPart Floating point value that receives the integral part of the number.
	* @return			The fractional part of the number.
	*/
	static  double Modf(const double InValue, double* OutIntPart)
	{
		return modf(InValue, OutIntPart);
	}

	// Returns e^Value
	static  float Exp(float Value) { return expf(Value); }
	// Returns 2^Value
	static  float Exp2(float Value) { return powf(2.f, Value); /*exp2f(Value);*/ }
	static  float Loge(float Value) { return logf(Value); }
	static  float LogX(float Base, float Value) { return Loge(Value) / Loge(Base); }
	// 1.0 / Loge(2) = 1.4426950f
	static  float Log2(float Value) { return Loge(Value) * 1.4426950f; }

	/**
	* Returns the floating-point remainder of X / Y
	* Warning: Always returns remainder toward 0, not toward the smaller multiple of Y.
	*			So for example Fmod(2.8f, 2) gives .8f as you would expect, however, Fmod(-2.8f, 2) gives -.8f, NOT 1.2f
	* Use Floor instead when snapping positions that can be negative to a grid
	*
	* This is forced to *NOT* inline so that divisions by constant Y does not get optimized in to an inverse scalar multiply,
	* which is not consistent with the intent nor with the vectorized version.
	*/
	static  float Fmod(float X, float Y);

	static  float Sin(float Value) { return sinf(Value); }
	static  float Asin(float Value) { return asinf((Value < -1.f) ? -1.f : ((Value < 1.f) ? Value : 1.f)); }
	static  float Sinh(float Value) { return sinhf(Value); }
	static  float Cos(float Value) { return cosf(Value); }
	static  float Acos(float Value) { return acosf((Value < -1.f) ? -1.f : ((Value < 1.f) ? Value : 1.f)); }
	static  float Tan(float Value) { return tanf(Value); }
	static  float Atan(float Value) { return atanf(Value); }
	//static  float Atan2(float Y, float X);
	static  float Sqrt(float Value) { return sqrtf(Value); }
	static  float Pow(float A, float B) { return powf(A, B); }

	/** Computes a fully accurate inverse square root */
	static  float InvSqrt(float F)
	{
		return 1.0f / sqrtf(F);
	}

	/** Computes a faster but less accurate inverse square root */
	static  float InvSqrtEst(float F)
	{
		return InvSqrt(F);
	}

	/** Return true if value is NaN (not a number). */
	static  bool IsNaN(float A)
	{
		return ((*(uint32_t*)&A) & 0x7FFFFFFFU) > 0x7F800000U;
	}
	static  bool IsNaN(double A)
	{
		return ((*(uint64_t*)&A) & 0x7FFFFFFFFFFFFFFFULL) > 0x7FF0000000000000ULL;
	}

	/** Return true if value is finite (not NaN and not Infinity). */
	static  bool IsFinite(float A)
	{
		return ((*(uint32_t*)&A) & 0x7F800000U) != 0x7F800000U;
	}
	static  bool IsFinite(double A)
	{
		return ((*(uint64_t*)&A) & 0x7FF0000000000000ULL) != 0x7FF0000000000000ULL;
	}

	static  bool IsNegativeFloat(float A)
	{
		return ((*(uint32_t*)&A) >= (uint32_t)0x80000000); // Detects sign bit.
	}

	static  bool IsNegativeDouble(double A)
	{
		return ((*(uint64_t*)&A) >= (uint64_t)0x8000000000000000); // Detects sign bit.
	}

	/** Returns a random integer between 0 and RAND_MAX, inclusive */
	static  int32_t Rand() { return rand(); }

	/** Seeds global random number functions Rand() and FRand() */
	static void RandInit(int32_t Seed) { srand(Seed); }

	/** Returns a random float between 0 and 1, inclusive. */
	static float FRand() { return Rand() / (float)RAND_MAX; }

	///** Seeds future calls to SRand() */
	//static void SRandInit(int32_t Seed);

	///** Returns the current seed for SRand(). */
	//static int32_t GetRandSeed();

	///** Returns a seeded random float in the range [0,1), using the seed from SRandInit(). */
	//static float SRand();

	/**
	 * Computes the base 2 logarithm for an integer value that is greater than 0.
	 * The result is rounded down to the nearest integer.
	 *
	 * @param Value		The value to compute the log of
	 * @return			Log2 of Value. 0 if Value is 0.
	 */
	static  uint32_t FloorLog2(uint32_t Value)
	{
		/*		// reference implementation
				// 1500ms on test data
				uint32_t Bit = 32;
				for (; Bit > 0;)
				{
					Bit--;
					if (Value & (1<<Bit))
					{
						break;
					}
				}
				return Bit;
		*/
		// same output as reference

		// see http://codinggorilla.domemtech.com/?p=81 or http://en.wikipedia.org/wiki/Binary_logarithm but modified to return 0 for a input value of 0
		// 686ms on test data
		uint32_t pos = 0;
		if (Value >= 1 << 16) { Value >>= 16; pos += 16; }
		if (Value >= 1 << 8) { Value >>= 8; pos += 8; }
		if (Value >= 1 << 4) { Value >>= 4; pos += 4; }
		if (Value >= 1 << 2) { Value >>= 2; pos += 2; }
		if (Value >= 1 << 1) { pos += 1; }
		return (Value == 0) ? 0 : pos;

		// even faster would be method3 but it can introduce more cache misses and it would need to store the table somewhere
		// 304ms in test data
		/*int LogTable256[256];

		void prep()
		{
			LogTable256[0] = LogTable256[1] = 0;
			for (int i = 2; i < 256; i++)
			{
				LogTable256[i] = 1 + LogTable256[i / 2];
			}
			LogTable256[0] = -1; // if you want log(0) to return -1
		}

		int _ method3(uint32_t v)
		{
			int r;     // r will be lg(v)
			uint32_t tt; // temporaries

			if ((tt = v >> 24) != 0)
			{
				r = (24 + LogTable256[tt]);
			}
			else if ((tt = v >> 16) != 0)
			{
				r = (16 + LogTable256[tt]);
			}
			else if ((tt = v >> 8 ) != 0)
			{
				r = (8 + LogTable256[tt]);
			}
			else
			{
				r = LogTable256[v];
			}
			return r;
		}*/
	}

	/**
	 * Computes the base 2 logarithm for a 64-bit value that is greater than 0.
	 * The result is rounded down to the nearest integer.
	 *
	 * @param Value		The value to compute the log of
	 * @return			Log2 of Value. 0 if Value is 0.
	 */
	static  uint64_t FloorLog2_64(uint64_t Value)
	{
		uint64_t pos = 0;
		if (Value >= 1ull << 32) { Value >>= 32; pos += 32; }
		if (Value >= 1ull << 16) { Value >>= 16; pos += 16; }
		if (Value >= 1ull << 8) { Value >>= 8; pos += 8; }
		if (Value >= 1ull << 4) { Value >>= 4; pos += 4; }
		if (Value >= 1ull << 2) { Value >>= 2; pos += 2; }
		if (Value >= 1ull << 1) { pos += 1; }
		return (Value == 0) ? 0 : pos;
	}

	/**
	 * Counts the number of leading zeros in the bit representation of the value
	 *
	 * @param Value the value to determine the number of leading zeros for
	 *
	 * @return the number of zeros before the first "on" bit
	 */
	static  uint32_t CountLeadingZeros(uint32_t Value)
	{
		if (Value == 0) return 32;
		return 31 - FloorLog2(Value);
	}

	/**
	 * Counts the number of leading zeros in the bit representation of the 64-bit value
	 *
	 * @param Value the value to determine the number of leading zeros for
	 *
	 * @return the number of zeros before the first "on" bit
	 */
	static  uint64_t CountLeadingZeros64(uint64_t Value)
	{
		if (Value == 0) return 64;
		return 63 - FloorLog2_64(Value);
	}

	/**
	 * Counts the number of trailing zeros in the bit representation of the value
	 *
	 * @param Value the value to determine the number of trailing zeros for
	 *
	 * @return the number of zeros after the last "on" bit
	 */
	static  uint32_t CountTrailingZeros(uint32_t Value)
	{
		if (Value == 0)
		{
			return 32;
		}
		uint32_t Result = 0;
		while ((Value & 1) == 0)
		{
			Value >>= 1;
			++Result;
		}
		return Result;
	}

	/**
	 * Counts the number of trailing zeros in the bit representation of the value
	 *
	 * @param Value the value to determine the number of trailing zeros for
	 *
	 * @return the number of zeros after the last "on" bit
	 */
	static  uint64_t CountTrailingZeros64(uint64_t Value)
	{
		if (Value == 0)
		{
			return 64;
		}
		uint64_t Result = 0;
		while ((Value & 1) == 0)
		{
			Value >>= 1;
			++Result;
		}
		return Result;
	}

	/**
	 * Returns smallest N such that (1<<N)>=Arg.
	 * Note: CeilLogTwo(0)=0 because (1<<0)=1 >= 0.
	 */
	static  uint32_t CeilLogTwo(uint32_t Arg)
	{
		int32_t Bitmask = ((int32_t)(CountLeadingZeros(Arg) << 26)) >> 31;
		return (32 - CountLeadingZeros(Arg - 1)) & (~Bitmask);
	}

	static  uint64_t CeilLogTwo64(uint64_t Arg)
	{
		int64_t Bitmask = ((int64_t)(CountLeadingZeros64(Arg) << 57)) >> 63;
		return (64 - CountLeadingZeros64(Arg - 1)) & (~Bitmask);
	}

	/** @return Rounds the given number up to the next highest power of two. */
	static  uint32_t RoundUpToPowerOfTwo(uint32_t Arg)
	{
		return 1 << CeilLogTwo(Arg);
	}

	static  uint64_t RoundUpToPowerOfTwo64(uint64_t V)
	{
		return uint64_t(1) << CeilLogTwo64(V);
	}

	/** Spreads bits to every other. */
	static  uint32_t MortonCode2(uint32_t x)
	{
		x &= 0x0000ffff;
		x = (x ^ (x << 8)) & 0x00ff00ff;
		x = (x ^ (x << 4)) & 0x0f0f0f0f;
		x = (x ^ (x << 2)) & 0x33333333;
		x = (x ^ (x << 1)) & 0x55555555;
		return x;
	}

	/** Reverses MortonCode2. Compacts every other bit to the right. */
	static  uint32_t ReverseMortonCode2(uint32_t x)
	{
		x &= 0x55555555;
		x = (x ^ (x >> 1)) & 0x33333333;
		x = (x ^ (x >> 2)) & 0x0f0f0f0f;
		x = (x ^ (x >> 4)) & 0x00ff00ff;
		x = (x ^ (x >> 8)) & 0x0000ffff;
		return x;
	}

	/** Spreads bits to every 3rd. */
	static  uint32_t MortonCode3(uint32_t x)
	{
		x &= 0x000003ff;
		x = (x ^ (x << 16)) & 0xff0000ff;
		x = (x ^ (x << 8)) & 0x0300f00f;
		x = (x ^ (x << 4)) & 0x030c30c3;
		x = (x ^ (x << 2)) & 0x09249249;
		return x;
	}

	/** Reverses MortonCode3. Compacts every 3rd bit to the right. */
	static  uint32_t ReverseMortonCode3(uint32_t x)
	{
		x &= 0x09249249;
		x = (x ^ (x >> 2)) & 0x030c30c3;
		x = (x ^ (x >> 4)) & 0x0300f00f;
		x = (x ^ (x >> 8)) & 0xff0000ff;
		x = (x ^ (x >> 16)) & 0x000003ff;
		return x;
	}

	/**
	 * Returns value based on comparand. The main purpose of this function is to avoid
	 * branching based on floating point comparison which can be avoided via compiler
	 * intrinsics.
	 *
	 * Please note that we don't define what happens in the case of NaNs as there might
	 * be platform specific differences.
	 *
	 * @param	Comparand		Comparand the results are based on
	 * @param	ValueGEZero		Return value if Comparand >= 0
	 * @param	ValueLTZero		Return value if Comparand < 0
	 *
	 * @return	ValueGEZero if Comparand >= 0, ValueLTZero otherwise
	 */
	static constexpr  float FloatSelect(float Comparand, float ValueGEZero, float ValueLTZero)
	{
		return Comparand >= 0.f ? ValueGEZero : ValueLTZero;
	}

	/**
	 * Returns value based on comparand. The main purpose of this function is to avoid
	 * branching based on floating point comparison which can be avoided via compiler
	 * intrinsics.
	 *
	 * Please note that we don't define what happens in the case of NaNs as there might
	 * be platform specific differences.
	 *
	 * @param	Comparand		Comparand the results are based on
	 * @param	ValueGEZero		Return value if Comparand >= 0
	 * @param	ValueLTZero		Return value if Comparand < 0
	 *
	 * @return	ValueGEZero if Comparand >= 0, ValueLTZero otherwise
	 */
	static constexpr  double FloatSelect(double Comparand, double ValueGEZero, double ValueLTZero)
	{
		return Comparand >= 0.f ? ValueGEZero : ValueLTZero;
	}

	/** Computes absolute value in a generic way */
	template< class T >
	static constexpr  T Abs(const T A)
	{
		return (A >= (T)0) ? A : -A;
	}

	/** Returns 1, 0, or -1 depending on relation of T to 0 */
	template< class T >
	static constexpr  T Sign(const T A)
	{
		return (A > (T)0) ? (T)1 : ((A < (T)0) ? (T)-1 : (T)0);
	}

	/** Returns higher value in a generic way */
	template< class T >
	static constexpr  T Max(const T A, const T B)
	{
		return (A >= B) ? A : B;
	}

	/** Returns lower value in a generic way */
	template< class T >
	static constexpr  T Min(const T A, const T B)
	{
		return (A <= B) ? A : B;
	}

	static  int32_t CountBits(uint64_t Bits)
	{
		// https://en.wikipedia.org/wiki/Hamming_weight
		Bits -= (Bits >> 1) & 0x5555555555555555ull;
		Bits = (Bits & 0x3333333333333333ull) + ((Bits >> 2) & 0x3333333333333333ull);
		Bits = (Bits + (Bits >> 4)) & 0x0f0f0f0f0f0f0f0full;
		return (Bits * 0x0101010101010101) >> 56;
	}

#if WITH_DEV_AUTOMATION_TESTS
	/** Test some of the tricky functions above **/
	static void AutoTest();
#endif

private:

	///** Error reporting for Fmod. Not inlined to avoid compilation issues and avoid all the checks and error reporting at all callsites. */
	//static void FmodReportError(float X, float Y);

	// Random Number Functions

	/** Helper function for rand implementations. Returns a random number in [0..A) */
	static int32_t RandHelper(int32_t A)
	{
		// Note that on some platforms RAND_MAX is a large number so we cannot do ((rand()/(RAND_MAX+1)) * A)
		// or else we may include the upper bound results, which should be excluded.
		return A > 0 ? Min(TruncToInt(FRand() * A), A - 1) : 0;
	}

	static  int64_t RandHelper64(int64_t A)
	{
		// Note that on some platforms RAND_MAX is a large number so we cannot do ((rand()/(RAND_MAX+1)) * A)
		// or else we may include the upper bound results, which should be excluded.
		return A > 0 ? Min<int64_t>(TruncToInt(FRand() * A), A - 1) : 0;
	}

	/** Helper function for rand implementations. Returns a random number >= Min and <= Max */
	static  int32_t RandRange(int32_t Min, int32_t Max)
	{
		const int32_t Range = (Max - Min) + 1;
		return Min + RandHelper(Range);
	}

	static  int64_t RandRange(int64_t Min, int64_t Max)
	{
		const int64_t Range = (Max - Min) + 1;
		return Min + RandHelper64(Range);
	}

	/** Util to generate a random number in a range. Overloaded to distinguish from int32_t version, where passing a float is typically a mistake. */
	static  float RandRange(float InMin, float InMax)
	{
		return FRandRange(InMin, InMax);
	}

	/** Util to generate a random number in a range. */
	static  float FRandRange(float InMin, float InMax)
	{
		return InMin + (InMax - InMin) * FRand();
	}

	/** Util to generate a random boolean. */
	static  bool RandBool()
	{
		return (RandRange(0, 1) == 1) ? true : false;
	}

//	/** Return a uniformly distributed random unit length vector = point on the unit sphere surface. */
//	static MVector VRand();

//	/**
//	 * Returns a random unit vector, uniformly distributed, within the specified cone
//	 * ConeHalfAngleRad is the half-angle of cone, in radians.  Returns a normalized vector.
//	 */
//	static CORE_API MVector VRandCone(MVector const& Dir, float ConeHalfAngleRad);
//
//	/**
//	 * This is a version of VRandCone that handles "squished" cones, i.e. with different angle limits in the Y and Z axes.
//	 * Assumes world Y and Z, although this could be extended to handle arbitrary rotations.
//	 */
//	static CORE_API MVector VRandCone(MVector const& Dir, float HorizontalConeHalfAngleRad, float VerticalConeHalfAngleRad);
//
//	/** Returns a random point, uniformly distributed, within the specified radius */
//	static CORE_API MVector2D RandPointInCircle(float CircleRadius);
//
//	/** Returns a random point within the passed in bounding box */
//	static CORE_API MVector RandPointInBox(const FBox& Box);
//
//	/**
//	 * Given a direction vector and a surface normal, returns the vector reflected across the surface normal.
//	 * Produces a result like shining a laser at a mirror!
//	 *
//	 * @param Direction Direction vector the ray is coming from.
//	 * @param SurfaceNormal A normal of the surface the ray should be reflected on.
//	 *
//	 * @returns Reflected vector.
//	 */
//	static CORE_API MVector GetReflectionVector(const MVector& Direction, const MVector& SurfaceNormal);
//
//	// Predicates
//
//	/** Checks if value is within a range, exclusive on MaxValue) */
//	template< class U >
//	static  bool IsWithin(const U& TestValue, const U& MinValue, const U& MaxValue)
//	{
//		return ((TestValue >= MinValue) && (TestValue < MaxValue));
//	}
//
//	/** Checks if value is within a range, inclusive on MaxValue) */
//	template< class U >
//	static  bool IsWithinInclusive(const U& TestValue, const U& MinValue, const U& MaxValue)
//	{
//		return ((TestValue >= MinValue) && (TestValue <= MaxValue));
//	}
//
//	/**
//	 *	Checks if two floating point numbers are nearly equal.
//	 *	@param A				First number to compare
//	 *	@param B				Second number to compare
//	 *	@param ErrorTolerance	Maximum allowed difference for considering them as 'nearly equal'
//	 *	@return					true if A and B are nearly equal
//	 */
//	static  bool IsNearlyEqual(float A, float B, float ErrorTolerance = SMALL_NUMBER)
//	{
//		return Abs<float>(A - B) <= ErrorTolerance;
//	}
//
//	/**
//	 *	Checks if two floating point numbers are nearly equal.
//	 *	@param A				First number to compare
//	 *	@param B				Second number to compare
//	 *	@param ErrorTolerance	Maximum allowed difference for considering them as 'nearly equal'
//	 *	@return					true if A and B are nearly equal
//	 */
//	static  bool IsNearlyEqual(double A, double B, double ErrorTolerance = SMALL_NUMBER)
//	{
//		return Abs<double>(A - B) <= ErrorTolerance;
//	}
//
//	/**
//	 *	Checks if a floating point number is nearly zero.
//	 *	@param Value			Number to compare
//	 *	@param ErrorTolerance	Maximum allowed difference for considering Value as 'nearly zero'
//	 *	@return					true if Value is nearly zero
//	 */
//	static  bool IsNearlyZero(float Value, float ErrorTolerance = SMALL_NUMBER)
//	{
//		return Abs<float>(Value) <= ErrorTolerance;
//	}
//
//	/**
//	 *	Checks if a floating point number is nearly zero.
//	 *	@param Value			Number to compare
//	 *	@param ErrorTolerance	Maximum allowed difference for considering Value as 'nearly zero'
//	 *	@return					true if Value is nearly zero
//	 */
//	static  bool IsNearlyZero(double Value, double ErrorTolerance = SMALL_NUMBER)
//	{
//		return Abs<double>(Value) <= ErrorTolerance;
//	}
//
//private:
//	template<typename FloatType, typename IntegralType, IntegralType SignedBit>
//	static inline bool TIsNearlyEqualByULP(FloatType A, FloatType B, int32_t MaxUlps)
//	{
//		// Any comparison with NaN always fails.
//		if (FMath::IsNaN(A) || FMath::IsNaN(B))
//		{
//			return false;
//		}
//
//		// If either number is infinite, then ignore ULP and do a simple equality test. 
//		// The rationale being that two infinities, of the same sign, should compare the same 
//		// no matter the ULP, but FLT_MAX and Inf should not, even if they're neighbors in
//		// their bit representation.
//		if (!FMath::IsFinite(A) || !FMath::IsFinite(B))
//		{
//			return A == B;
//		}
//
//		// Convert the integer representation of the float from sign + magnitude to
//		// a signed number representation where 0 is 1 << 31. This allows us to compare
//		// ULP differences around zero values.
//		auto FloatToSignedNumber = [](IntegralType V) {
//			if (V & SignedBit)
//			{
//				return ~V + 1;
//			}
//			else
//			{
//				return SignedBit | V;
//			}
//		};
//
//		union FFloatToInt { FloatType F; IntegralType I; };
//		FFloatToInt FloatA;
//		FFloatToInt FloatB;
//
//		FloatA.F = A;
//		FloatB.F = B;
//
//		IntegralType SNA = FloatToSignedNumber(FloatA.I);
//		IntegralType SNB = FloatToSignedNumber(FloatB.I);
//		IntegralType Distance = (SNA >= SNB) ? (SNA - SNB) : (SNB - SNA);
//		return Distance <= IntegralType(MaxUlps);
//	}
//
//public:
//
//	/**
//	 *	Check if two floating point numbers are nearly equal to within specific number of
//	 *	units of last place (ULP). A single ULP difference between two floating point numbers
//	 *	means that they have an adjacent representation and that no other floating point number
//	 *	can be constructed to fit between them. This enables making consistent comparisons
//	 *	based on representational distance between floating point numbers, regardless of
//	 *	their magnitude.
//	 *
//	 *	Use when the two numbers vary greatly in range. Otherwise, if absolute tolerance is
//	 *	required, use IsNearlyEqual instead.
//	 *
//	 *	Note: Since IEEE 754 floating point operations are guaranteed to be exact to 0.5 ULP,
//	 *	a value of 4 ought to be sufficient for all but the most complex float operations.
//	 *
//	 *	@param A				First number to compare
//	 *	@param B				Second number to compare
//	 *	@param MaxUlps          The maximum ULP distance by which neighboring floating point
//	 *	                        numbers are allowed to differ.
//	 *	@return					true if the two values are nearly equal.
//	 */
//	static  bool IsNearlyEqualByULP(float A, float B, int32_t MaxUlps = 4)
//	{
//		return TIsNearlyEqualByULP<float, uint32_t, uint32_t(1U << 31)>(A, B, MaxUlps);
//	}
//
//	/**
//	 *	Check if two floating point numbers are nearly equal to within specific number of
//	 *	units of last place (ULP). A single ULP difference between two floating point numbers
//	 *	means that they have an adjacent representation and that no other floating point number
//	 *	can be constructed to fit between them. This enables making consistent comparisons
//	 *	based on representational distance between floating point numbers, regardless of
//	 *	their magnitude.
//	 *
//	 *	Note: Since IEEE 754 floating point operations are guaranteed to be exact to 0.5 ULP,
//	 *	a value of 4 ought to be sufficient for all but the most complex float operations.
//	 *
//	 *	@param A				First number to compare
//	 *	@param B				Second number to compare
//	 *	@param MaxUlps          The maximum ULP distance by which neighboring floating point
//	 *	                        numbers are allowed to differ.
//	 *	@return					true if the two values are nearly equal.
//	 */
//	static  bool IsNearlyEqualByULP(double A, double B, int32_t MaxUlps = 4)
//	{
//		return TIsNearlyEqualByULP<double, uint64_t, uint64_t(1ULL << 63)>(A, B, MaxUlps);
//	}
//
//	/**
//	 *	Checks whether a number is a power of two.
//	 *	@param Value	Number to check
//	 *	@return			true if Value is a power of two
//	 */
//	template <typename T>
//	static  bool IsPowerOfTwo(T Value)
//	{
//		return ((Value & (Value - 1)) == (T)0);
//	}
//
//
//	// Math Operations
//
//	/** Returns highest of 3 values */
//	template< class T >
//	static  T Max3(const T A, const T B, const T C)
//	{
//		return Max(Max(A, B), C);
//	}
//
//	/** Returns lowest of 3 values */
//	template< class T >
//	static  T Min3(const T A, const T B, const T C)
//	{
//		return Min(Min(A, B), C);
//	}
//
//	/** Multiples value by itself */
//	template< class T >
//	static  T Square(const T A)
//	{
//		return A * A;
//	}
//
//	/** Clamps X to be between Min and Max, inclusive */
//	template< class T >
//	static  T Clamp(const T X, const T Min, const T Max)
//	{
//		return X < Min ? Min : X < Max ? X : Max;
//	}
//
//	/** Snaps a value to the nearest grid multiple */
//	static  float GridSnap(float Location, float Grid)
//	{
//		if (Grid == 0.f)	return Location;
//		else
//		{
//			return FloorToFloat((Location + 0.5f * Grid) / Grid) * Grid;
//		}
//	}
//
//	/** Snaps a value to the nearest grid multiple */
//	static  double GridSnap(double Location, double Grid)
//	{
//		if (Grid == 0.0)	return Location;
//		else
//		{
//			return FloorToDouble((Location + 0.5 * Grid) / Grid) * Grid;
//		}
//	}
//
//	/** Divides two integers and rounds up */
//	template <class T>
//	static  T DivideAndRoundUp(T Dividend, T Divisor)
//	{
//		return (Dividend + Divisor - 1) / Divisor;
//	}
//
//	/** Divides two integers and rounds down */
//	template <class T>
//	static  T DivideAndRoundDown(T Dividend, T Divisor)
//	{
//		return Dividend / Divisor;
//	}
//
//	/** Divides two integers and rounds to nearest */
//	template <class T>
//	static  T DivideAndRoundNearest(T Dividend, T Divisor)
//	{
//		return (Dividend >= 0)
//			? (Dividend + Divisor / 2) / Divisor
//			: (Dividend - Divisor / 2 + 1) / Divisor;
//	}
//
//	/**
//	 * Computes the base 2 logarithm of the specified value
//	 *
//	 * @param Value the value to perform the log on
//	 *
//	 * @return the base 2 log of the value
//	 */
//	static  float Log2(float Value)
//	{
//		// Cached value for fast conversions
//		static const float LogToLog2 = 1.f / Loge(2.f);
//		// Do the platform specific log and convert using the cached value
//		return Loge(Value) * LogToLog2;
//	}
//
//	/**
//	* Computes the sine and cosine of a scalar value.
//	*
//	* @param ScalarSin	Pointer to where the Sin result should be stored
//	* @param ScalarCos	Pointer to where the Cos result should be stored
//	* @param Value  input angles
//	*/
//	static  void SinCos(float* ScalarSin, float* ScalarCos, float  Value)
//	{
//		// Map Value to y in [-pi,pi], x = 2*pi*quotient + remainder.
//		float quotient = (INV_PI * 0.5f) * Value;
//		if (Value >= 0.0f)
//		{
//			quotient = (float)((int)(quotient + 0.5f));
//		}
//		else
//		{
//			quotient = (float)((int)(quotient - 0.5f));
//		}
//		float y = Value - (2.0f * PI) * quotient;
//
//		// Map y to [-pi/2,pi/2] with sin(y) = sin(Value).
//		float sign;
//		if (y > HALF_PI)
//		{
//			y = PI - y;
//			sign = -1.0f;
//		}
//		else if (y < -HALF_PI)
//		{
//			y = -PI - y;
//			sign = -1.0f;
//		}
//		else
//		{
//			sign = +1.0f;
//		}
//
//		float y2 = y * y;
//
//		// 11-degree minimax approximation
//		*ScalarSin = (((((-2.3889859e-08f * y2 + 2.7525562e-06f) * y2 - 0.00019840874f) * y2 + 0.0083333310f) * y2 - 0.16666667f) * y2 + 1.0f) * y;
//
//		// 10-degree minimax approximation
//		float p = ((((-2.6051615e-07f * y2 + 2.4760495e-05f) * y2 - 0.0013888378f) * y2 + 0.041666638f) * y2 - 0.5f) * y2 + 1.0f;
//		*ScalarCos = sign * p;
//	}
//
//
//	// Note:  We use FASTASIN_HALF_PI instead of HALF_PI inside of FastASin(), since it was the value that accompanied the minimax coefficients below.
//	// It is important to use exactly the same value in all places inside this function to ensure that FastASin(0.0f) == 0.0f.
//	// For comparison:
//	//		HALF_PI				== 1.57079632679f == 0x3fC90FDB
//	//		FASTASIN_HALF_PI	== 1.5707963050f  == 0x3fC90FDA
//#define FASTASIN_HALF_PI (1.5707963050f)
//	/**
//	* Computes the ASin of a scalar value.
//	*
//	* @param Value  input angle
//	* @return ASin of Value
//	*/
//	static  float FastAsin(float Value)
//	{
//		// Clamp input to [-1,1].
//		bool nonnegative = (Value >= 0.0f);
//		float x = FMath::Abs(Value);
//		float omx = 1.0f - x;
//		if (omx < 0.0f)
//		{
//			omx = 0.0f;
//		}
//		float root = FMath::Sqrt(omx);
//		// 7-degree minimax approximation
//		float result = ((((((-0.0012624911f * x + 0.0066700901f) * x - 0.0170881256f) * x + 0.0308918810f) * x - 0.0501743046f) * x + 0.0889789874f) * x - 0.2145988016f) * x + FASTASIN_HALF_PI;
//		result *= root;  // acos(|x|)
//		// acos(x) = pi - acos(-x) when x < 0, asin(x) = pi/2 - acos(x)
//		return (nonnegative ? FASTASIN_HALF_PI - result : result - FASTASIN_HALF_PI);
//	}
//#undef FASTASIN_HALF_PI
//
//
//	// Conversion Functions
//
//	/**
//	 * Converts radians to degrees.
//	 * @param	RadVal			Value in radians.
//	 * @return					Value in degrees.
//	 */
//	template<class T>
//	static  auto RadiansToDegrees(T const& RadVal) -> decltype(RadVal* (180.f / PI))
//	{
//		return RadVal * (180.f / PI);
//	}
//
//	/**
//	 * Converts degrees to radians.
//	 * @param	DegVal			Value in degrees.
//	 * @return					Value in radians.
//	 */
//	template<class T>
//	static  auto DegreesToRadians(T const& DegVal) -> decltype(DegVal* (PI / 180.f))
//	{
//		return DegVal * (PI / 180.f);
//	}
//
//	/**
//	 * Clamps an arbitrary angle to be between the given angles.  Will clamp to nearest boundary.
//	 *
//	 * @param MinAngleDegrees	"from" angle that defines the beginning of the range of valid angles (sweeping clockwise)
//	 * @param MaxAngleDegrees	"to" angle that defines the end of the range of valid angles
//	 * @return Returns clamped angle in the range -180..180.
//	 */
//	static float CORE_API ClampAngle(float AngleDegrees, float MinAngleDegrees, float MaxAngleDegrees);
//
//	/** Find the smallest angle between two headings (in degrees) */
//	static float FindDeltaAngleDegrees(float A1, float A2)
//	{
//		// Find the difference
//		float Delta = A2 - A1;
//
//		// If change is larger than 180
//		if (Delta > 180.0f)
//		{
//			// Flip to negative equivalent
//			Delta = Delta - 360.0f;
//		}
//		else if (Delta < -180.0f)
//		{
//			// Otherwise, if change is smaller than -180
//			// Flip to positive equivalent
//			Delta = Delta + 360.0f;
//		}
//
//		// Return delta in [-180,180] range
//		return Delta;
//	}
//
//	/** Find the smallest angle between two headings (in radians) */
//	static float FindDeltaAngleRadians(float A1, float A2)
//	{
//		// Find the difference
//		float Delta = A2 - A1;
//
//		// If change is larger than PI
//		if (Delta > PI)
//		{
//			// Flip to negative equivalent
//			Delta = Delta - (PI * 2.0f);
//		}
//		else if (Delta < -PI)
//		{
//			// Otherwise, if change is smaller than -PI
//			// Flip to positive equivalent
//			Delta = Delta + (PI * 2.0f);
//		}
//
//		// Return delta in [-PI,PI] range
//		return Delta;
//	}
//
//	UE_DEPRECATED(4.12, "Please use FindDeltaAngleRadians(float A1, float A2) instead of FindDeltaAngle(float A1, float A2).")
//		static float FindDeltaAngle(float A1, float A2)
//	{
//		return FindDeltaAngleRadians(A1, A2);
//	}
//
//	/** Given a heading which may be outside the +/- PI range, 'unwind' it back into that range. */
//	static float UnwindRadians(float A)
//	{
//		while (A > PI)
//		{
//			A -= ((float)PI * 2.0f);
//		}
//
//		while (A < -PI)
//		{
//			A += ((float)PI * 2.0f);
//		}
//
//		return A;
//	}
//
//	/** Utility to ensure angle is between +/- 180 degrees by unwinding. */
//	static float UnwindDegrees(float A)
//	{
//		while (A > 180.f)
//		{
//			A -= 360.f;
//		}
//
//		while (A < -180.f)
//		{
//			A += 360.f;
//		}
//
//		return A;
//	}
//
//	/**
//	 * Given two angles in degrees, 'wind' the rotation in Angle1 so that it avoids >180 degree flips.
//	 * Good for winding rotations previously expressed as quaternions into a euler-angle representation.
//	 * @param	Angle0	The first angle that we wind relative to.
//	 * @param	Angle1	The second angle that we may wind relative to the first.
//	 */
//	static CORE_API void WindRelativeAnglesDegrees(float InAngle0, float& InOutAngle1);
//
//	/** Returns a new rotation component value
//	 *
//	 * @param InCurrent is the current rotation value
//	 * @param InDesired is the desired rotation value
//	 * @param InDeltaRate is the rotation amount to apply
//	 *
//	 * @return a new rotation component value
//	 */
//	static CORE_API float FixedTurn(float InCurrent, float InDesired, float InDeltaRate);
//
//	/** Converts given Cartesian coordinate pair to Polar coordinate system. */
//	static  void CartesianToPolar(const float X, const float Y, float& OutRad, float& OutAng)
//	{
//		OutRad = Sqrt(Square(X) + Square(Y));
//		OutAng = Atan2(Y, X);
//	}
//	/** Converts given Cartesian coordinate pair to Polar coordinate system. */
//	static  void CartesianToPolar(const MVector2D InCart, MVector2D& OutPolar);
//
//	/** Converts given Polar coordinate pair to Cartesian coordinate system. */
//	static  void PolarToCartesian(const float Rad, const float Ang, float& OutX, float& OutY)
//	{
//		OutX = Rad * Cos(Ang);
//		OutY = Rad * Sin(Ang);
//	}
//	/** Converts given Polar coordinate pair to Cartesian coordinate system. */
//	static  void PolarToCartesian(const MVector2D InPolar, MVector2D& OutCart);
//
//	/**
//	 * Calculates the dotted distance of vector 'Direction' to coordinate system O(AxisX,AxisY,AxisZ).
//	 *
//	 * Orientation: (consider 'O' the first person view of the player, and 'Direction' a vector pointing to an enemy)
//	 * - positive azimuth means enemy is on the right of crosshair. (negative means left).
//	 * - positive elevation means enemy is on top of crosshair, negative means below.
//	 *
//	 * @Note: 'Azimuth' (.X) sign is changed to represent left/right and not front/behind. front/behind is the funtion's return value.
//	 *
//	 * @param	OutDotDist	.X = 'Direction' dot AxisX relative to plane (AxisX,AxisZ). (== Cos(Azimuth))
//	 *						.Y = 'Direction' dot AxisX relative to plane (AxisX,AxisY). (== Sin(Elevation))
//	 * @param	Direction	direction of target.
//	 * @param	AxisX		X component of reference system.
//	 * @param	AxisY		Y component of reference system.
//	 * @param	AxisZ		Z component of reference system.
//	 *
//	 * @return	true if 'Direction' is facing AxisX (Direction dot AxisX >= 0.f)
//	 */
//	static CORE_API bool GetDotDistance(MVector2D& OutDotDist, const MVector& Direction, const MVector& AxisX, const MVector& AxisY, const MVector& AxisZ);
//
//	/**
//	 * Returns Azimuth and Elevation of vector 'Direction' in coordinate system O(AxisX,AxisY,AxisZ).
//	 *
//	 * Orientation: (consider 'O' the first person view of the player, and 'Direction' a vector pointing to an enemy)
//	 * - positive azimuth means enemy is on the right of crosshair. (negative means left).
//	 * - positive elevation means enemy is on top of crosshair, negative means below.
//	 *
//	 * @param	Direction		Direction of target.
//	 * @param	AxisX			X component of reference system.
//	 * @param	AxisY			Y component of reference system.
//	 * @param	AxisZ			Z component of reference system.
//	 *
//	 * @return	MVector2D	X = Azimuth angle (in radians) (-PI, +PI)
//	 *						Y = Elevation angle (in radians) (-PI/2, +PI/2)
//	 */
//	static CORE_API MVector2D GetAzimuthAndElevation(const MVector& Direction, const MVector& AxisX, const MVector& AxisY, const MVector& AxisZ);
//
//	// Interpolation Functions
//
//	/** Calculates the percentage along a line from MinValue to MaxValue that Value is. */
//	template<typename T>
//	static  typename TEnableIf<TIsFloatingPoint<T>::Value, T>::Type GetRangePct(T MinValue, T MaxValue, T Value)
//	{
//		// Avoid Divide by Zero.
//		// But also if our range is a point, output whether Value is before or after.
//		const T Divisor = MaxValue - MinValue;
//		if (FMath::IsNearlyZero(Divisor))
//		{
//			return (Value >= MaxValue) ? (T)1 : (T)0;
//		}
//
//		return (Value - MinValue) / Divisor;
//	}
//
//	/** Same as above, but taking a 2d vector as the range. */
//	static float GetRangePct(MVector2D const& Range, float Value);
//
//	/** Basically a Vector2d version of Lerp. */
//	static float GetRangeValue(MVector2D const& Range, float Pct);
//
//	/** For the given Value clamped to the [Input:Range] inclusive, returns the corresponding percentage in [Output:Range] Inclusive. */
//	static  float GetMappedRangeValueClamped(const MVector2D& InputRange, const MVector2D& OutputRange, const float Value)
//	{
//		const float ClampedPct = Clamp<float>(GetRangePct(InputRange, Value), 0.f, 1.f);
//		return GetRangeValue(OutputRange, ClampedPct);
//	}
//
//	/** Transform the given Value relative to the input range to the Output Range. */
//	static  float GetMappedRangeValueUnclamped(const MVector2D& InputRange, const MVector2D& OutputRange, const float Value)
//	{
//		return GetRangeValue(OutputRange, GetRangePct(InputRange, Value));
//	}
//
//	template<class T>
//	static  double GetRangePct(TRange<T> const& Range, T Value)
//	{
//		return GetRangePct(Range.GetLowerBoundValue(), Range.GetUpperBoundValue(), Value);
//	}
//
//	template<class T>
//	static  T GetRangeValue(TRange<T> const& Range, T Pct)
//	{
//		return FMath::Lerp<T>(Range.GetLowerBoundValue(), Range.GetUpperBoundValue(), Pct);
//	}
//
//	template<class T>
//	static  T GetMappedRangeValueClamped(const TRange<T>& InputRange, const TRange<T>& OutputRange, const T Value)
//	{
//		const T ClampedPct = FMath::Clamp<T>(GetRangePct(InputRange, Value), 0, 1);
//		return GetRangeValue(OutputRange, ClampedPct);
//	}
//
//	/** Performs a linear interpolation between two values, Alpha ranges from 0-1 */
//	template< class T, class U >
//	static _DEBUGGABLE T Lerp(const T& A, const T& B, const U& Alpha)
//	{
//		return (T)(A + Alpha * (B - A));
//	}
//
//	/** Performs a linear interpolation between two values, Alpha ranges from 0-1. Handles full numeric range of T */
//	template< class T >
//	static _DEBUGGABLE T LerpStable(const T& A, const T& B, double Alpha)
//	{
//		return (T)((A * (1.0 - Alpha)) + (B * Alpha));
//	}
//
//	/** Performs a linear interpolation between two values, Alpha ranges from 0-1. Handles full numeric range of T */
//	template< class T >
//	static _DEBUGGABLE T LerpStable(const T& A, const T& B, float Alpha)
//	{
//		return (T)((A * (1.0f - Alpha)) + (B * Alpha));
//	}
//
//	/** Performs a 2D linear interpolation between four values values, FracX, FracY ranges from 0-1 */
//	template< class T, class U >
//	static _DEBUGGABLE T BiLerp(const T& P00, const T& P10, const T& P01, const T& P11, const U& FracX, const U& FracY)
//	{
//		return Lerp(
//			Lerp(P00, P10, FracX),
//			Lerp(P01, P11, FracX),
//			FracY
//		);
//	}
//
//	/**
//	 * Performs a cubic interpolation
//	 *
//	 * @param  P - end points
//	 * @param  T - tangent directions at end points
//	 * @param  Alpha - distance along spline
//	 *
//	 * @return  Interpolated value
//	 */
//	template< class T, class U >
//	static _DEBUGGABLE T CubicInterp(const T& P0, const T& T0, const T& P1, const T& T1, const U& A)
//	{
//		const float A2 = A * A;
//		const float A3 = A2 * A;
//
//		return (T)(((2 * A3) - (3 * A2) + 1) * P0) + ((A3 - (2 * A2) + A) * T0) + ((A3 - A2) * T1) + (((-2 * A3) + (3 * A2)) * P1);
//	}
//
//	/**
//	 * Performs a first derivative cubic interpolation
//	 *
//	 * @param  P - end points
//	 * @param  T - tangent directions at end points
//	 * @param  Alpha - distance along spline
//	 *
//	 * @return  Interpolated value
//	 */
//	template< class T, class U >
//	static _DEBUGGABLE T CubicInterpDerivative(const T& P0, const T& T0, const T& P1, const T& T1, const U& A)
//	{
//		T a = 6.f * P0 + 3.f * T0 + 3.f * T1 - 6.f * P1;
//		T b = -6.f * P0 - 4.f * T0 - 2.f * T1 + 6.f * P1;
//		T c = T0;
//
//		const float A2 = A * A;
//
//		return (a * A2) + (b * A) + c;
//	}
//
//	/**
//	 * Performs a second derivative cubic interpolation
//	 *
//	 * @param  P - end points
//	 * @param  T - tangent directions at end points
//	 * @param  Alpha - distance along spline
//	 *
//	 * @return  Interpolated value
//	 */
//	template< class T, class U >
//	static _DEBUGGABLE T CubicInterpSecondDerivative(const T& P0, const T& T0, const T& P1, const T& T1, const U& A)
//	{
//		T a = 12.f * P0 + 6.f * T0 + 6.f * T1 - 12.f * P1;
//		T b = -6.f * P0 - 4.f * T0 - 2.f * T1 + 6.f * P1;
//
//		return (a * A) + b;
//	}
//
//	/** Interpolate between A and B, applying an ease in function.  Exp controls the degree of the curve. */
//	template< class T >
//	static _DEBUGGABLE T InterpEaseIn(const T& A, const T& B, float Alpha, float Exp)
//	{
//		float const ModifiedAlpha = Pow(Alpha, Exp);
//		return Lerp<T>(A, B, ModifiedAlpha);
//	}
//
//	/** Interpolate between A and B, applying an ease out function.  Exp controls the degree of the curve. */
//	template< class T >
//	static _DEBUGGABLE T InterpEaseOut(const T& A, const T& B, float Alpha, float Exp)
//	{
//		float const ModifiedAlpha = 1.f - Pow(1.f - Alpha, Exp);
//		return Lerp<T>(A, B, ModifiedAlpha);
//	}
//
//	/** Interpolate between A and B, applying an ease in/out function.  Exp controls the degree of the curve. */
//	template< class T >
//	static _DEBUGGABLE T InterpEaseInOut(const T& A, const T& B, float Alpha, float Exp)
//	{
//		return Lerp<T>(A, B, (Alpha < 0.5f) ?
//			InterpEaseIn(0.f, 1.f, Alpha * 2.f, Exp) * 0.5f :
//			InterpEaseOut(0.f, 1.f, Alpha * 2.f - 1.f, Exp) * 0.5f + 0.5f);
//	}
//
//	/** Interpolation between A and B, applying a step function. */
//	template< class T >
//	static _DEBUGGABLE T InterpStep(const T& A, const T& B, float Alpha, int32_t Steps)
//	{
//		if (Steps <= 1 || Alpha <= 0)
//		{
//			return A;
//		}
//		else if (Alpha >= 1)
//		{
//			return B;
//		}
//
//		const float StepsAsFloat = static_cast<float>(Steps);
//		const float NumIntervals = StepsAsFloat - 1.f;
//		float const ModifiedAlpha = FloorToFloat(Alpha * StepsAsFloat) / NumIntervals;
//		return Lerp<T>(A, B, ModifiedAlpha);
//	}
//
//	/** Interpolation between A and B, applying a sinusoidal in function. */
//	template< class T >
//	static _DEBUGGABLE T InterpSinIn(const T& A, const T& B, float Alpha)
//	{
//		float const ModifiedAlpha = -1.f * Cos(Alpha * HALF_PI) + 1.f;
//		return Lerp<T>(A, B, ModifiedAlpha);
//	}
//
//	/** Interpolation between A and B, applying a sinusoidal out function. */
//	template< class T >
//	static _DEBUGGABLE T InterpSinOut(const T& A, const T& B, float Alpha)
//	{
//		float const ModifiedAlpha = Sin(Alpha * HALF_PI);
//		return Lerp<T>(A, B, ModifiedAlpha);
//	}
//
//	/** Interpolation between A and B, applying a sinusoidal in/out function. */
//	template< class T >
//	static _DEBUGGABLE T InterpSinInOut(const T& A, const T& B, float Alpha)
//	{
//		return Lerp<T>(A, B, (Alpha < 0.5f) ?
//			InterpSinIn(0.f, 1.f, Alpha * 2.f) * 0.5f :
//			InterpSinOut(0.f, 1.f, Alpha * 2.f - 1.f) * 0.5f + 0.5f);
//	}
//
//	/** Interpolation between A and B, applying an exponential in function. */
//	template< class T >
//	static _DEBUGGABLE T InterpExpoIn(const T& A, const T& B, float Alpha)
//	{
//		float const ModifiedAlpha = (Alpha == 0.f) ? 0.f : Pow(2.f, 10.f * (Alpha - 1.f));
//		return Lerp<T>(A, B, ModifiedAlpha);
//	}
//
//	/** Interpolation between A and B, applying an exponential out function. */
//	template< class T >
//	static _DEBUGGABLE T InterpExpoOut(const T& A, const T& B, float Alpha)
//	{
//		float const ModifiedAlpha = (Alpha == 1.f) ? 1.f : -Pow(2.f, -10.f * Alpha) + 1.f;
//		return Lerp<T>(A, B, ModifiedAlpha);
//	}
//
//	/** Interpolation between A and B, applying an exponential in/out function. */
//	template< class T >
//	static _DEBUGGABLE T InterpExpoInOut(const T& A, const T& B, float Alpha)
//	{
//		return Lerp<T>(A, B, (Alpha < 0.5f) ?
//			InterpExpoIn(0.f, 1.f, Alpha * 2.f) * 0.5f :
//			InterpExpoOut(0.f, 1.f, Alpha * 2.f - 1.f) * 0.5f + 0.5f);
//	}
//
//	/** Interpolation between A and B, applying a circular in function. */
//	template< class T >
//	static _DEBUGGABLE T InterpCircularIn(const T& A, const T& B, float Alpha)
//	{
//		float const ModifiedAlpha = -1.f * (Sqrt(1.f - Alpha * Alpha) - 1.f);
//		return Lerp<T>(A, B, ModifiedAlpha);
//	}
//
//	/** Interpolation between A and B, applying a circular out function. */
//	template< class T >
//	static _DEBUGGABLE T InterpCircularOut(const T& A, const T& B, float Alpha)
//	{
//		Alpha -= 1.f;
//		float const ModifiedAlpha = Sqrt(1.f - Alpha * Alpha);
//		return Lerp<T>(A, B, ModifiedAlpha);
//	}
//
//	/** Interpolation between A and B, applying a circular in/out function. */
//	template< class T >
//	static _DEBUGGABLE T InterpCircularInOut(const T& A, const T& B, float Alpha)
//	{
//		return Lerp<T>(A, B, (Alpha < 0.5f) ?
//			InterpCircularIn(0.f, 1.f, Alpha * 2.f) * 0.5f :
//			InterpCircularOut(0.f, 1.f, Alpha * 2.f - 1.f) * 0.5f + 0.5f);
//	}
//
//	// Rotator specific interpolation
//	template< class U > static FRotator Lerp(const FRotator& A, const FRotator& B, const U& Alpha);
//	template< class U > static FRotator LerpRange(const FRotator& A, const FRotator& B, const U& Alpha);
//
//	// Quat-specific interpolation
//
//	template< class U > static FQuat Lerp(const FQuat& A, const FQuat& B, const U& Alpha);
//	template< class U > static FQuat BiLerp(const FQuat& P00, const FQuat& P10, const FQuat& P01, const FQuat& P11, float FracX, float FracY);
//
//	/**
//	 * In the case of quaternions, we use a bezier like approach.
//	 * T - Actual 'control' orientations.
//	 */
//	template< class U > static FQuat CubicInterp(const FQuat& P0, const FQuat& T0, const FQuat& P1, const FQuat& T1, const U& A);
//
//	/*
//	 *	Cubic Catmull-Rom Spline interpolation. Based on http://www.cemyuksel.com/research/catmullrom_param/catmullrom.pdf
//	 *	Curves are guaranteed to pass through the control points and are easily chained together.
//	 *	Equation supports abitrary parameterization. eg. Uniform=0,1,2,3 ; chordal= |Pn - Pn-1| ; centripetal = |Pn - Pn-1|^0.5
//	 *	P0 - The control point preceding the interpolation range.
//	 *	P1 - The control point starting the interpolation range.
//	 *	P2 - The control point ending the interpolation range.
//	 *	P3 - The control point following the interpolation range.
//	 *	T0-3 - The interpolation parameters for the corresponding control points.
//	 *	T - The interpolation factor in the range 0 to 1. 0 returns P1. 1 returns P2.
//	 */
//	template< class U >
//	static _DEBUGGABLE U CubicCRSplineInterp(const U& P0, const U& P1, const U& P2, const U& P3, const float T0, const float T1, const float T2, const float T3, const float T)
//	{
//		//Based on http://www.cemyuksel.com/research/catmullrom_param/catmullrom.pdf 
//		float InvT1MinusT0 = 1.0f / (T1 - T0);
//		U L01 = (P0 * ((T1 - T) * InvT1MinusT0)) + (P1 * ((T - T0) * InvT1MinusT0));
//		float InvT2MinusT1 = 1.0f / (T2 - T1);
//		U L12 = (P1 * ((T2 - T) * InvT2MinusT1)) + (P2 * ((T - T1) * InvT2MinusT1));
//		float InvT3MinusT2 = 1.0f / (T3 - T2);
//		U L23 = (P2 * ((T3 - T) * InvT3MinusT2)) + (P3 * ((T - T2) * InvT3MinusT2));
//
//		float InvT2MinusT0 = 1.0f / (T2 - T0);
//		U L012 = (L01 * ((T2 - T) * InvT2MinusT0)) + (L12 * ((T - T0) * InvT2MinusT0));
//		float InvT3MinusT1 = 1.0f / (T3 - T1);
//		U L123 = (L12 * ((T3 - T) * InvT3MinusT1)) + (L23 * ((T - T1) * InvT3MinusT1));
//
//		return  ((L012 * ((T2 - T) * InvT2MinusT1)) + (L123 * ((T - T1) * InvT2MinusT1)));
//	}
//
//	/* Same as CubicCRSplineInterp but with additional saftey checks. If the checks fail P1 is returned. **/
//	template< class U >
//	static _DEBUGGABLE U CubicCRSplineInterpSafe(const U& P0, const U& P1, const U& P2, const U& P3, const float T0, const float T1, const float T2, const float T3, const float T)
//	{
//		//Based on http://www.cemyuksel.com/research/catmullrom_param/catmullrom.pdf 
//		float T1MinusT0 = (T1 - T0);
//		float T2MinusT1 = (T2 - T1);
//		float T3MinusT2 = (T3 - T2);
//		float T2MinusT0 = (T2 - T0);
//		float T3MinusT1 = (T3 - T1);
//		if (FMath::IsNearlyZero(T1MinusT0) || FMath::IsNearlyZero(T2MinusT1) || FMath::IsNearlyZero(T3MinusT2) || FMath::IsNearlyZero(T2MinusT0) || FMath::IsNearlyZero(T3MinusT1))
//		{
//			//There's going to be a divide by zero here so just bail out and return P1
//			return P1;
//		}
//
//		float InvT1MinusT0 = 1.0f / T1MinusT0;
//		U L01 = (P0 * ((T1 - T) * InvT1MinusT0)) + (P1 * ((T - T0) * InvT1MinusT0));
//		float InvT2MinusT1 = 1.0f / T2MinusT1;
//		U L12 = (P1 * ((T2 - T) * InvT2MinusT1)) + (P2 * ((T - T1) * InvT2MinusT1));
//		float InvT3MinusT2 = 1.0f / T3MinusT2;
//		U L23 = (P2 * ((T3 - T) * InvT3MinusT2)) + (P3 * ((T - T2) * InvT3MinusT2));
//
//		float InvT2MinusT0 = 1.0f / T2MinusT0;
//		U L012 = (L01 * ((T2 - T) * InvT2MinusT0)) + (L12 * ((T - T0) * InvT2MinusT0));
//		float InvT3MinusT1 = 1.0f / T3MinusT1;
//		U L123 = (L12 * ((T3 - T) * InvT3MinusT1)) + (L23 * ((T - T1) * InvT3MinusT1));
//
//		return  ((L012 * ((T2 - T) * InvT2MinusT1)) + (L123 * ((T - T1) * InvT2MinusT1)));
//	}
//
//
//	// Special-case interpolation
//
//	/** Interpolate a normal vector Current to Target, by interpolating the angle between those vectors with constant step. */
//	static CORE_API MVector VInterpNormalRotationTo(const MVector& Current, const MVector& Target, float DeltaTime, float RotationSpeedDegrees);
//
//	/** Interpolate vector from Current to Target with constant step */
//	static CORE_API MVector VInterpConstantTo(const MVector& Current, const MVector& Target, float DeltaTime, float InterpSpeed);
//
//	/** Interpolate vector from Current to Target. Scaled by distance to Target, so it has a strong start speed and ease out. */
//	static CORE_API MVector VInterpTo(const MVector& Current, const MVector& Target, float DeltaTime, float InterpSpeed);
//
//	/** Interpolate vector2D from Current to Target with constant step */
//	static CORE_API MVector2D Vector2DInterpConstantTo(const MVector2D& Current, const MVector2D& Target, float DeltaTime, float InterpSpeed);
//
//	/** Interpolate vector2D from Current to Target. Scaled by distance to Target, so it has a strong start speed and ease out. */
//	static CORE_API MVector2D Vector2DInterpTo(const MVector2D& Current, const MVector2D& Target, float DeltaTime, float InterpSpeed);
//
//	/** Interpolate rotator from Current to Target with constant step */
//	static CORE_API FRotator RInterpConstantTo(const FRotator& Current, const FRotator& Target, float DeltaTime, float InterpSpeed);
//
//	/** Interpolate rotator from Current to Target. Scaled by distance to Target, so it has a strong start speed and ease out. */
//	static CORE_API FRotator RInterpTo(const FRotator& Current, const FRotator& Target, float DeltaTime, float InterpSpeed);
//
//	/** Interpolate float from Current to Target with constant step */
//	static CORE_API float FInterpConstantTo(float Current, float Target, float DeltaTime, float InterpSpeed);
//
//	/** Interpolate float from Current to Target. Scaled by distance to Target, so it has a strong start speed and ease out. */
//	static CORE_API float FInterpTo(float Current, float Target, float DeltaTime, float InterpSpeed);
//
//	/** Interpolate Linear Color from Current to Target. Scaled by distance to Target, so it has a strong start speed and ease out. */
//	static CORE_API FLinearColor CInterpTo(const FLinearColor& Current, const FLinearColor& Target, float DeltaTime, float InterpSpeed);
//
//	/** Interpolate quaternion from Current to Target with constant step (in radians) */
//	static CORE_API FQuat QInterpConstantTo(const FQuat& Current, const FQuat& Target, float DeltaTime, float InterpSpeed);
//
//	/** Interpolate quaternion from Current to Target. Scaled by angle to Target, so it has a strong start speed and ease out. */
//	static CORE_API FQuat QInterpTo(const FQuat& Current, const FQuat& Target, float DeltaTime, float InterpSpeed);
//
//	/**
//	 * Simple function to create a pulsating scalar value
//	 *
//	 * @param  InCurrentTime  Current absolute time
//	 * @param  InPulsesPerSecond  How many full pulses per second?
//	 * @param  InPhase  Optional phase amount, between 0.0 and 1.0 (to synchronize pulses)
//	 *
//	 * @return  Pulsating value (0.0-1.0)
//	 */
//	static float MakePulsatingValue(const double InCurrentTime, const float InPulsesPerSecond, const float InPhase = 0.0f)
//	{
//		return 0.5f + 0.5f * FMath::Sin(((0.25f + InPhase) * (float)PI * 2.0f) + ((float)InCurrentTime * (float)PI * 2.0f) * InPulsesPerSecond);
//	}
//
//	// Geometry intersection 
//
//	/**
//	 * Find the intersection of a ray and a plane.  The ray has a start point with an infinite length.  Assumes that the
//	 * line and plane do indeed intersect; you must make sure they're not parallel before calling.
//	 *
//	 * @param RayOrigin	The start point of the ray
//	 * @param RayDirection	The direction the ray is pointing (normalized vector)
//	 * @param Plane	The plane to intersect with
//	 *
//	 * @return The point of intersection between the ray and the plane.
//	 */
//	static MVector RayPlaneIntersection(const MVector& RayOrigin, const MVector& RayDirection, const FPlane& Plane);
//
//	/**
//	 * Find the intersection of a line and an offset plane. Assumes that the
//	 * line and plane do indeed intersect; you must make sure they're not
//	 * parallel before calling.
//	 *
//	 * @param Point1 the first point defining the line
//	 * @param Point2 the second point defining the line
//	 * @param PlaneOrigin the origin of the plane
//	 * @param PlaneNormal the normal of the plane
//	 *
//	 * @return The point of intersection between the line and the plane.
//	 */
//	static MVector LinePlaneIntersection(const MVector& Point1, const MVector& Point2, const MVector& PlaneOrigin, const MVector& PlaneNormal);
//
//	/**
//	 * Find the intersection of a line and a plane. Assumes that the line and
//	 * plane do indeed intersect; you must make sure they're not parallel before
//	 * calling.
//	 *
//	 * @param Point1 the first point defining the line
//	 * @param Point2 the second point defining the line
//	 * @param Plane the plane
//	 *
//	 * @return The point of intersection between the line and the plane.
//	 */
//	static MVector LinePlaneIntersection(const MVector& Point1, const MVector& Point2, const FPlane& Plane);
//
//
//	// @parma InOutScissorRect should be set to View.ViewRect before the call
//	// @return 0: light is not visible, 1:use scissor rect, 2: no scissor rect needed
//	static CORE_API uint32_t ComputeProjectedSphereScissorRect(struct FIntRect& InOutScissorRect, MVector SphereOrigin, float Radius, MVector ViewOrigin, const FMatrix& ViewMatrix, const FMatrix& ProjMatrix);
//
//	// @param ConeOrigin Cone origin
//	// @param ConeDirection Cone direction
//	// @param ConeRadius Cone Radius
//	// @param CosConeAngle Cos of the cone angle
//	// @param SinConeAngle Sin of the cone angle
//	// @return Minimal bounding sphere encompassing given cone
//	static FSphere ComputeBoundingSphereForCone(MVector const& ConeOrigin, MVector const& ConeDirection, float ConeRadius, float CosConeAngle, float SinConeAngle);
//
//	/**
//	 * Determine if a plane and an AABB intersect
//	 * @param P - the plane to test
//	 * @param AABB - the axis aligned bounding box to test
//	 * @return if collision occurs
//	 */
//	static CORE_API bool PlaneAABBIntersection(const FPlane& P, const FBox& AABB);
//
//	/**
//	 * Determine the position of an AABB relative to a plane:
//	 * completely above (in the direction of the normal of the plane), completely below or intersects it
//	 * @param P - the plane to test
//	 * @param AABB - the axis aligned bounding box to test
//	 * @return -1 if below, 1 if above, 0 if intersects
//	 */
//	static CORE_API int32_t PlaneAABBRelativePosition(const FPlane& P, const FBox& AABB);
//
//	/**
//	 * Performs a sphere vs box intersection test using Arvo's algorithm:
//	 *
//	 *	for each i in (x, y, z)
//	 *		if (SphereCenter(i) < BoxMin(i)) d2 += (SphereCenter(i) - BoxMin(i)) ^ 2
//	 *		else if (SphereCenter(i) > BoxMax(i)) d2 += (SphereCenter(i) - BoxMax(i)) ^ 2
//	 *
//	 * @param Sphere the center of the sphere being tested against the AABB
//	 * @param RadiusSquared the size of the sphere being tested
//	 * @param AABB the box being tested against
//	 *
//	 * @return Whether the sphere/box intersect or not.
//	 */
//	static bool SphereAABBIntersection(const MVector& SphereCenter, const float RadiusSquared, const FBox& AABB);
//
//	/**
//	 * Converts a sphere into a point plus radius squared for the test above
//	 */
//	static bool SphereAABBIntersection(const FSphere& Sphere, const FBox& AABB);
//
//	/** Determines whether a point is inside a box. */
//	static bool PointBoxIntersection(const MVector& Point, const FBox& Box);
//
//	/** Determines whether a line intersects a box. */
//	static bool LineBoxIntersection(const FBox& Box, const MVector& Start, const MVector& End, const MVector& Direction);
//
//	/** Determines whether a line intersects a box. This overload avoids the need to do the reciprocal every time. */
//	static bool LineBoxIntersection(const FBox& Box, const MVector& Start, const MVector& End, const MVector& Direction, const MVector& OneOverDirection);
//
//	/* Swept-Box vs Box test */
//	static CORE_API bool LineExtentBoxIntersection(const FBox& inBox, const MVector& Start, const MVector& End, const MVector& Extent, MVector& HitLocation, MVector& HitNormal, float& HitTime);
//
//	/** Determines whether a line intersects a sphere. */
//	static bool LineSphereIntersection(const MVector& Start, const MVector& Dir, float Length, const MVector& Origin, float Radius);
//
//	/**
//	 * Assumes the cone tip is at 0,0,0 (means the SphereCenter is relative to the cone tip)
//	 * @return true: cone and sphere do intersect, false otherwise
//	 */
//	static CORE_API bool SphereConeIntersection(const MVector& SphereCenter, float SphereRadius, const MVector& ConeAxis, float ConeAngleSin, float ConeAngleCos);
//
//	/** Find the point on the line segment from LineStart to LineEnd which is closest to Point */
//	static CORE_API MVector ClosestPointOnLine(const MVector& LineStart, const MVector& LineEnd, const MVector& Point);
//
//	/** Find the point on the infinite line between two points (LineStart, LineEnd) which is closest to Point */
//	static CORE_API MVector ClosestPointOnInfiniteLine(const MVector& LineStart, const MVector& LineEnd, const MVector& Point);
//
//	/** Compute intersection point of three planes. Return 1 if valid, 0 if infinite. */
//	static bool IntersectPlanes3(MVector& I, const FPlane& P1, const FPlane& P2, const FPlane& P3);
//
//	/**
//	 * Compute intersection point and direction of line joining two planes.
//	 * Return 1 if valid, 0 if infinite.
//	 */
//	static bool IntersectPlanes2(MVector& I, MVector& D, const FPlane& P1, const FPlane& P2);
//
//	/**
//	 * Calculates the distance of a given Point in world space to a given line,
//	 * defined by the vector couple (Origin, Direction).
//	 *
//	 * @param	Point				Point to check distance to line
//	 * @param	Direction			Vector indicating the direction of the line. Not required to be normalized.
//	 * @param	Origin				Point of reference used to calculate distance
//	 * @param	OutClosestPoint	optional point that represents the closest point projected onto Axis
//	 *
//	 * @return	distance of Point from line defined by (Origin, Direction)
//	 */
//	static CORE_API float PointDistToLine(const MVector& Point, const MVector& Direction, const MVector& Origin, MVector& OutClosestPoint);
//	static CORE_API float PointDistToLine(const MVector& Point, const MVector& Direction, const MVector& Origin);
//
//	/**
//	 * Returns closest point on a segment to a given point.
//	 * The idea is to project point on line formed by segment.
//	 * Then we see if the closest point on the line is outside of segment or inside.
//	 *
//	 * @param	Point			point for which we find the closest point on the segment
//	 * @param	StartPoint		StartPoint of segment
//	 * @param	EndPoint		EndPoint of segment
//	 *
//	 * @return	point on the segment defined by (StartPoint, EndPoint) that is closest to Point.
//	 */
//	static CORE_API MVector ClosestPointOnSegment(const MVector& Point, const MVector& StartPoint, const MVector& EndPoint);
//
//	/**
//	* MVector2D version of ClosestPointOnSegment.
//	* Returns closest point on a segment to a given 2D point.
//	* The idea is to project point on line formed by segment.
//	* Then we see if the closest point on the line is outside of segment or inside.
//	*
//	* @param	Point			point for which we find the closest point on the segment
//	* @param	StartPoint		StartPoint of segment
//	* @param	EndPoint		EndPoint of segment
//	*
//	* @return	point on the segment defined by (StartPoint, EndPoint) that is closest to Point.
//	*/
//	static CORE_API MVector2D ClosestPointOnSegment2D(const MVector2D& Point, const MVector2D& StartPoint, const MVector2D& EndPoint);
//
//	/**
//	 * Returns distance from a point to the closest point on a segment.
//	 *
//	 * @param	Point			point to check distance for
//	 * @param	StartPoint		StartPoint of segment
//	 * @param	EndPoint		EndPoint of segment
//	 *
//	 * @return	closest distance from Point to segment defined by (StartPoint, EndPoint).
//	 */
//	static CORE_API float PointDistToSegment(const MVector& Point, const MVector& StartPoint, const MVector& EndPoint);
//
//	/**
//	 * Returns square of the distance from a point to the closest point on a segment.
//	 *
//	 * @param	Point			point to check distance for
//	 * @param	StartPoint		StartPoint of segment
//	 * @param	EndPoint		EndPoint of segment
//	 *
//	 * @return	square of the closest distance from Point to segment defined by (StartPoint, EndPoint).
//	 */
//	static CORE_API float PointDistToSegmentSquared(const MVector& Point, const MVector& StartPoint, const MVector& EndPoint);
//
//	/**
//	 * Find closest points between 2 segments.
//	 *
//	 * If either segment may have a length of 0, use SegmentDistToSegmentSafe instance.
//	 *
//	 * @param	(A1, B1)	defines the first segment.
//	 * @param	(A2, B2)	defines the second segment.
//	 * @param	OutP1		Closest point on segment 1 to segment 2.
//	 * @param	OutP2		Closest point on segment 2 to segment 1.
//	 */
//	static CORE_API void SegmentDistToSegment(MVector A1, MVector B1, MVector A2, MVector B2, MVector& OutP1, MVector& OutP2);
//
//	/**
//	 * Find closest points between 2 segments.
//	 *
//	 * This is the safe version, and will check both segments' lengths.
//	 * Use this if either (or both) of the segments lengths may be 0.
//	 *
//	 * @param	(A1, B1)	defines the first segment.
//	 * @param	(A2, B2)	defines the second segment.
//	 * @param	OutP1		Closest point on segment 1 to segment 2.
//	 * @param	OutP2		Closest point on segment 2 to segment 1.
//	 */
//	static CORE_API void SegmentDistToSegmentSafe(MVector A1, MVector B1, MVector A2, MVector B2, MVector& OutP1, MVector& OutP2);
//
//	/**
//	 * returns the time (t) of the intersection of the passed segment and a plane (could be <0 or >1)
//	 * @param StartPoint - start point of segment
//	 * @param EndPoint   - end point of segment
//	 * @param Plane		- plane to intersect with
//	 * @return time(T) of intersection
//	 */
//	static CORE_API float GetTForSegmentPlaneIntersect(const MVector& StartPoint, const MVector& EndPoint, const FPlane& Plane);
//
//	/**
//	 * Returns true if there is an intersection between the segment specified by StartPoint and Endpoint, and
//	 * the plane on which polygon Plane lies. If there is an intersection, the point is placed in out_IntersectionPoint
//	 * @param StartPoint - start point of segment
//	 * @param EndPoint   - end point of segment
//	 * @param Plane		- plane to intersect with
//	 * @param out_IntersectionPoint - out var for the point on the segment that intersects the mesh (if any)
//	 * @return true if intersection occurred
//	 */
//	static CORE_API bool SegmentPlaneIntersection(const MVector& StartPoint, const MVector& EndPoint, const FPlane& Plane, MVector& out_IntersectionPoint);
//
//
//	/**
//	* Returns true if there is an intersection between the segment specified by StartPoint and Endpoint, and
//	* the Triangle defined by A, B and C. If there is an intersection, the point is placed in out_IntersectionPoint
//	* @param StartPoint - start point of segment
//	* @param EndPoint   - end point of segment
//	* @param A, B, C	- points defining the triangle
//	* @param OutIntersectPoint - out var for the point on the segment that intersects the triangle (if any)
//	* @param OutNormal - out var for the triangle normal
//	* @return true if intersection occurred
//	*/
//	static CORE_API bool SegmentTriangleIntersection(const MVector& StartPoint, const MVector& EndPoint, const MVector& A, const MVector& B, const MVector& C, MVector& OutIntersectPoint, MVector& OutTriangleNormal);
//
//	/**
//	 * Returns true if there is an intersection between the segment specified by SegmentStartA and SegmentEndA, and
//	 * the segment specified by SegmentStartB and SegmentEndB, in 2D space. If there is an intersection, the point is placed in out_IntersectionPoint
//	 * @param SegmentStartA - start point of first segment
//	 * @param SegmentEndA   - end point of first segment
//	 * @param SegmentStartB - start point of second segment
//	 * @param SegmentEndB   - end point of second segment
//	 * @param out_IntersectionPoint - out var for the intersection point (if any)
//	 * @return true if intersection occurred
//	 */
//	static CORE_API bool SegmentIntersection2D(const MVector& SegmentStartA, const MVector& SegmentEndA, const MVector& SegmentStartB, const MVector& SegmentEndB, MVector& out_IntersectionPoint);
//
//
//	/**
//	 * Returns closest point on a triangle to a point.
//	 * The idea is to identify the halfplanes that the point is
//	 * in relative to each triangle segment "plane"
//	 *
//	 * @param	Point			point to check distance for
//	 * @param	A,B,C			counter clockwise ordering of points defining a triangle
//	 *
//	 * @return	Point on triangle ABC closest to given point
//	 */
//	static CORE_API MVector ClosestPointOnTriangleToPoint(const MVector& Point, const MVector& A, const MVector& B, const MVector& C);
//
//	/**
//	 * Returns closest point on a tetrahedron to a point.
//	 * The idea is to identify the halfplanes that the point is
//	 * in relative to each face of the tetrahedron
//	 *
//	 * @param	Point			point to check distance for
//	 * @param	A,B,C,D			four points defining a tetrahedron
//	 *
//	 * @return	Point on tetrahedron ABCD closest to given point
//	 */
//	static CORE_API MVector ClosestPointOnTetrahedronToPoint(const MVector& Point, const MVector& A, const MVector& B, const MVector& C, const MVector& D);
//
//	/**
//	 * Find closest point on a Sphere to a Line.
//	 * When line intersects		Sphere, then closest point to LineOrigin is returned.
//	 * @param SphereOrigin		Origin of Sphere
//	 * @param SphereRadius		Radius of Sphere
//	 * @param LineOrigin		Origin of line
//	 * @param LineDir			Direction of line. Needs to be normalized!!
//	 * @param OutClosestPoint	Closest point on sphere to given line.
//	 */
//	static CORE_API void SphereDistToLine(MVector SphereOrigin, float SphereRadius, MVector LineOrigin, MVector LineDir, MVector& OutClosestPoint);
//
//	/**
//	 * Calculates whether a Point is within a cone segment, and also what percentage within the cone (100% is along the center line, whereas 0% is along the edge)
//	 *
//	 * @param Point - The Point in question
//	 * @param ConeStartPoint - the beginning of the cone (with the smallest radius)
//	 * @param ConeLine - the line out from the start point that ends at the largest radius point of the cone
//	 * @param radiusAtStart - the radius at the ConeStartPoint (0 for a 'proper' cone)
//	 * @param radiusAtEnd - the largest radius of the cone
//	 * @param percentageOut - output variable the holds how much within the cone the point is (1 = on center line, 0 = on exact edge or outside cone).
//	 *
//	 * @return true if the point is within the cone, false otherwise.
//	 */
//	static CORE_API bool GetDistanceWithinConeSegment(MVector Point, MVector ConeStartPoint, MVector ConeLine, float RadiusAtStart, float RadiusAtEnd, float& PercentageOut);
//
//	/**
//	 * Determines whether a given set of points are coplanar, with a tolerance. Any three points or less are always coplanar.
//	 *
//	 * @param Points - The set of points to determine coplanarity for.
//	 * @param Tolerance - Larger numbers means more variance is allowed.
//	 *
//	 * @return Whether the points are relatively coplanar, based on the tolerance
//	 */
//	static CORE_API bool PointsAreCoplanar(const TArray<MVector>& Points, const float Tolerance = 0.1f);
//
//	/**
//	 * Truncates a floating point number to half if closer than the given tolerance.
//	 * @param Value				Floating point number to truncate
//	 * @param Tolerance			Maximum allowed difference to 0.5 in order to truncate
//	 * @return					The truncated value
//	 */
//	static CORE_API float TruncateToHalfIfClose(float F, float Tolerance = SMALL_NUMBER);
//	static CORE_API double TruncateToHalfIfClose(double F, double Tolerance = SMALL_NUMBER);
//
//	/**
//	* Converts a floating point number to the nearest integer, equidistant ties go to the value which is closest to an even value: 1.5 becomes 2, 0.5 becomes 0
//	* @param F		Floating point value to convert
//	* @return		The rounded integer
//	*/
//	static CORE_API float RoundHalfToEven(float F);
//	static CORE_API double RoundHalfToEven(double F);
//
//	/**
//	* Converts a floating point number to the nearest integer, equidistant ties go to the value which is further from zero: -0.5 becomes -1.0, 0.5 becomes 1.0
//	* @param F		Floating point value to convert
//	* @return		The rounded integer
//	*/
//	static CORE_API float RoundHalfFromZero(float F);
//	static CORE_API double RoundHalfFromZero(double F);
//
//	/**
//	* Converts a floating point number to the nearest integer, equidistant ties go to the value which is closer to zero: -0.5 becomes 0, 0.5 becomes 0
//	* @param F		Floating point value to convert
//	* @return		The rounded integer
//	*/
//	static CORE_API float RoundHalfToZero(float F);
//	static CORE_API double RoundHalfToZero(double F);
//
//	/**
//	* Converts a floating point number to an integer which is further from zero, "larger" in absolute value: 0.1 becomes 1, -0.1 becomes -1
//	* @param F		Floating point value to convert
//	* @return		The rounded integer
//	*/
//	static  float RoundFromZero(float F)
//	{
//		return (F < 0.0f) ? FloorToFloat(F) : CeilToFloat(F);
//	}
//
//	static  double RoundFromZero(double F)
//	{
//		return (F < 0.0) ? FloorToDouble(F) : CeilToDouble(F);
//	}
//
//	/**
//	* Converts a floating point number to an integer which is closer to zero, "smaller" in absolute value: 0.1 becomes 0, -0.1 becomes 0
//	* @param F		Floating point value to convert
//	* @return		The rounded integer
//	*/
//	static  float RoundToZero(float F)
//	{
//		return (F < 0.0f) ? CeilToFloat(F) : FloorToFloat(F);
//	}
//
//	static  double RoundToZero(double F)
//	{
//		return (F < 0.0) ? CeilToDouble(F) : FloorToDouble(F);
//	}
//
//	/**
//	* Converts a floating point number to an integer which is more negative: 0.1 becomes 0, -0.1 becomes -1
//	* @param F		Floating point value to convert
//	* @return		The rounded integer
//	*/
//	static  float RoundToNegativeInfinity(float F)
//	{
//		return FloorToFloat(F);
//	}
//
//	static  double RoundToNegativeInfinity(double F)
//	{
//		return FloorToDouble(F);
//	}
//
//	/**
//	* Converts a floating point number to an integer which is more positive: 0.1 becomes 1, -0.1 becomes 0
//	* @param F		Floating point value to convert
//	* @return		The rounded integer
//	*/
//	static  float RoundToPositiveInfinity(float F)
//	{
//		return CeilToFloat(F);
//	}
//
//	static  double RoundToPositiveInfinity(double F)
//	{
//		return CeilToDouble(F);
//	}
//
//
//	// Formatting functions
//
//	/**
//	 * Formats an integer value into a human readable string (i.e. 12345 becomes "12,345")
//	 *
//	 * @param	Val		The value to use
//	 * @return	std::string	The human readable string
//	 */
//	static CORE_API std::string FormatIntToHumanReadable(int32_t Val);
//
//
//	// Utilities
//
//	/**
//	 * Tests a memory region to see that it's working properly.
//	 *
//	 * @param BaseAddress	Starting address
//	 * @param NumBytes		Number of bytes to test (will be rounded down to a multiple of 4)
//	 * @return				true if the memory region passed the test
//	 */
//	static CORE_API bool MemoryTest(void* BaseAddress, uint32_t NumBytes);
//
//	/**
//	 * Evaluates a numerical equation.
//	 *
//	 * Operators and precedence: 1:+- 2:/% 3:* 4:^ 5:&|
//	 * Unary: -
//	 * Types: Numbers (0-9.), Hex ($0-$f)
//	 * Grouping: ( )
//	 *
//	 * @param	Str			String containing the equation.
//	 * @param	OutValue		Pointer to storage for the result.
//	 * @return				1 if successful, 0 if equation fails.
//	 */
//	static CORE_API bool Eval(std::string Str, float& OutValue);
//
//	/**
//	 * Computes the barycentric coordinates for a given point in a triangle - simpler version
//	 *
//	 * @param	Point			point to convert to barycentric coordinates (in plane of ABC)
//	 * @param	A,B,C			three non-colinear points defining a triangle in CCW
//	 *
//	 * @return Vector containing the three weights a,b,c such that Point = a*A + b*B + c*C
//	 *							                                or Point = A + b*(B-A) + c*(C-A) = (1-b-c)*A + b*B + c*C
//	 */
//	static CORE_API MVector GetBaryCentric2D(const MVector& Point, const MVector& A, const MVector& B, const MVector& C);
//
//	/**
//	 * Computes the barycentric coordinates for a given point in a triangle
//	 *
//	 * @param	Point			point to convert to barycentric coordinates (in plane of ABC)
//	 * @param	A,B,C			three non-collinear points defining a triangle in CCW
//	 *
//	 * @return Vector containing the three weights a,b,c such that Point = a*A + b*B + c*C
//	 *							                               or Point = A + b*(B-A) + c*(C-A) = (1-b-c)*A + b*B + c*C
//	 */
//	static CORE_API MVector ComputeBaryCentric2D(const MVector& Point, const MVector& A, const MVector& B, const MVector& C);
//
//	/**
//	 * Computes the barycentric coordinates for a given point on a tetrahedron (3D)
//	 *
//	 * @param	Point			point to convert to barycentric coordinates
//	 * @param	A,B,C,D			four points defining a tetrahedron
//	 *
//	 * @return Vector containing the four weights a,b,c,d such that Point = a*A + b*B + c*C + d*D
//	 */
//	static CORE_API MVector4 ComputeBaryCentric3D(const MVector& Point, const MVector& A, const MVector& B, const MVector& C, const MVector& D);
//
//	/** 32 bit values where BitFlag[x] == (1<<x) */
//	static CORE_API const uint32_t BitFlag[32];
//
//	/**
//	 * Returns a smooth Hermite interpolation between 0 and 1 for the value X (where X ranges between A and B)
//	 * Clamped to 0 for X <= A and 1 for X >= B.
//	 *
//	 * @param A Minimum value of X
//	 * @param B Maximum value of X
//	 * @param X Parameter
//	 *
//	 * @return Smoothed value between 0 and 1
//	 */
//	static float SmoothStep(float A, float B, float X)
//	{
//		if (X < A)
//		{
//			return 0.0f;
//		}
//		else if (X >= B)
//		{
//			return 1.0f;
//		}
//		const float InterpFraction = (X - A) / (B - A);
//		return InterpFraction * InterpFraction * (3.0f - 2.0f * InterpFraction);
//	}
//
//	/**
//	 * Get a bit in memory created from bitflags (uint32_t Value:1), used for EngineShowFlags,
//	 * TestBitFieldFunctions() tests the implementation
//	 */
//	static inline bool ExtractBoolFromBitfield(uint8* Ptr, uint32_t Index)
//	{
//		uint8* BytePtr = Ptr + Index / 8;
//		uint8 Mask = (uint8)(1 << (Index & 0x7));
//
//		return (*BytePtr & Mask) != 0;
//	}
//
//	/**
//	 * Set a bit in memory created from bitflags (uint32_t Value:1), used for EngineShowFlags,
//	 * TestBitFieldFunctions() tests the implementation
//	 */
//	static inline void SetBoolInBitField(uint8* Ptr, uint32_t Index, bool bSet)
//	{
//		uint8* BytePtr = Ptr + Index / 8;
//		uint8 Mask = (uint8)(1 << (Index & 0x7));
//
//		if (bSet)
//		{
//			*BytePtr |= Mask;
//		}
//		else
//		{
//			*BytePtr &= ~Mask;
//		}
//	}
//
//	/**
//	 * Handy to apply scaling in the editor
//	 * @param Dst in and out
//	 */
//	static CORE_API void ApplyScaleToFloat(float& Dst, const MVector& DeltaScale, float Magnitude = 1.0f);
//
//	// @param x assumed to be in this range: 0..1
//	// @return 0..255
//	static uint8 Quantize8UnsignedByte(float x)
//	{
//		// 0..1 -> 0..255
//		int32_t Ret = (int32_t)(x * 255.999f);
//
//		check(Ret >= 0);
//		check(Ret <= 255);
//
//		return (uint8)Ret;
//	}
//
//	// @param x assumed to be in this range: -1..1
//	// @return 0..255
//	static uint8 Quantize8SignedByte(float x)
//	{
//		// -1..1 -> 0..1
//		float y = x * 0.5f + 0.5f;
//
//		return Quantize8UnsignedByte(y);
//	}
//
//	// Use the Euclidean method to find the GCD
//	static int32_t GreatestCommonDivisor(int32_t a, int32_t b)
//	{
//		while (b != 0)
//		{
//			int32_t t = b;
//			b = a % b;
//			a = t;
//		}
//		return a;
//	}
//
//	// LCM = a/gcd * b
//	// a and b are the number we want to find the lcm
//	static int32_t LeastCommonMultiplier(int32_t a, int32_t b)
//	{
//		int32_t CurrentGcd = GreatestCommonDivisor(a, b);
//		return CurrentGcd == 0 ? 0 : (a / CurrentGcd) * b;
//	}
//
//	/**
//	 * Generates a 1D Perlin noise from the given value.  Returns a continuous random value between -1.0 and 1.0.
//	 *
//	 * @param	Value	The input value that Perlin noise will be generated from.  This is usually a steadily incrementing time value.
//	 *
//	 * @return	Perlin noise in the range of -1.0 to 1.0
//	 */
//	static CORE_API float PerlinNoise1D(float Value);
//
//	/**
//	* Generates a 1D Perlin noise sample at the given location.  Returns a continuous random value between -1.0 and 1.0.
//	*
//	* @param	Location	Where to sample
//	*
//	* @return	Perlin noise in the range of -1.0 to 1.0
//	*/
//	static CORE_API float PerlinNoise2D(const MVector2D& Location);
//
//
//	/**
//	* Generates a 3D Perlin noise sample at the given location.  Returns a continuous random value between -1.0 and 1.0.
//	*
//	* @param	Location	Where to sample
//	*
//	* @return	Perlin noise in the range of -1.0 to 1.0
//	*/
//	static CORE_API float PerlinNoise3D(const MVector& Location);
//
//	/**
//	 * Calculates the new value in a weighted moving average series using the previous value and the weight
//	 *
//	 * @param CurrentSample - The value to blend with the previous sample to get a new weighted value
//	 * @param PreviousSample - The last value from the series
//	 * @param Weight - The weight to blend with
//	 *
//	 * @return the next value in the series
//	 */
//	static CORE_API inline float WeightedMovingAverage(float CurrentSample, float PreviousSample, float Weight)
//	{
//		Weight = Clamp<float>(Weight, 0.f, 1.f);
//		float WAvg = (CurrentSample * Weight) + (PreviousSample * (1.f - Weight));
//		return WAvg;
//	}
//
//	/**
//	 * Calculates the new value in a weighted moving average series using the previous value and a weight range.
//	 * The weight range is used to dynamically adjust based upon distance between the samples
//	 * This allows you to smooth a value more aggressively for small noise and let large movements be smoothed less (or vice versa)
//	 *
//	 * @param CurrentSample - The value to blend with the previous sample to get a new weighted value
//	 * @param PreviousSample - The last value from the series
//	 * @param MaxDistance - Distance to use as the blend between min weight or max weight
//	 * @param MinWeight - The weight use when the distance is small
//	 * @param MaxWeight - The weight use when the distance is large
//	 *
//	 * @return the next value in the series
//	 */
//	static CORE_API inline float DynamicWeightedMovingAverage(float CurrentSample, float PreviousSample, float MaxDistance, float MinWeight, float MaxWeight)
//	{
//		// We need the distance between samples to determine how much of each weight to use
//		const float Distance = Abs<float>(CurrentSample - PreviousSample);
//		float Weight = MinWeight;
//		if (MaxDistance > 0)
//		{
//			// Figure out the lerp value to use between the min/max weights
//			const float LerpAlpha = Clamp<float>(Distance / MaxDistance, 0.f, 1.f);
//			Weight = Lerp<float>(MinWeight, MaxWeight, LerpAlpha);
//		}
//		return WeightedMovingAverage(CurrentSample, PreviousSample, Weight);
//	}
};

/** Float specialization */
template<>
float FMath::Abs(const float A)
{
	return fabsf(A);
}


