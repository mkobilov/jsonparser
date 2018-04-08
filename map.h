//#ifndef __MAP_H__
//#define __MAP_H__

#define HASH_MAP_TYPE 1
#define SIMPLE_MAP_TYPE 2

#ifdef CLEARMAPTYPE
	#undef HASHMAP
	#undef SIMPLEMAP

	#if CLEARMAPTYPE == HASH_MAP_TYPE
		#define HASHMAP
	#endif

	#if CLEARMAPTYPE == SIMPLE_MAP_TYPE
		#define SIMPLEMAP
	#endif
#endif

#ifdef HASHMAP
	#include "hash_map.h"

	#define pMap pHashMap

	#define CreateMap(...) CreateHMap(__VA_ARGS__)
	#define DeleteMap(...) DeleteHMap(__VA_ARGS__)

	#define AddToMap(...) AddToHMap(__VA_ARGS__)
	#define IsInMap(...) IsInHMap(__VA_ARGS__)
	#define GetFromMap(...) GetFromHMap(__VA_ARGS__)
#endif

#ifdef SIMPLEMAP
	#include "list_map.h"

	#define pMap pSimpleMap

	#define CreateMap(...) CreateSMap(__VA_ARGS__)
	#define DeleteMap(...) DeleteSMap(__VA_ARGS__)

	#define AddToMap(...) AddToSMap(__VA_ARGS__)
	#define IsInMap(...) IsInSMap(__VA_ARGS__)
	#define GetFromMap(...) GetFromSMap(__VA_ARGS__)
#endif

//#endif 	//__MAP_H__
