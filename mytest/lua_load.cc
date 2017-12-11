/**
 * Created by suli on 17/12/9.
 */

int __fastcall cocos2d::LuaStack::luaLoadBuffer(int a1, int a2, char *s1, int a4, int a5) {
	int v5; // r5@1
	int v6; // r7@1
	char *v7; // r4@1
	int v8; // r6@1
	int v9; // r8@2
	int result; // r0@4
	int v11; // r0@9
	void *v12; // r5@9
	int v13; // r4@10
	int v14; // [sp+Ch] [bp-1Ch]@9

	v5 = a1;
	v6 = a2;
	v7 = s1;
	v8 = a4;
	if (*(_BYTE * )(a1 + 32)
		&& (v9 = *(_DWORD * )(a1 + 48), !strncmp(s1, *(const char **) (a1 + 44), *(_DWORD * )(a1 + 48)))) {
		v14 = 0;
		v11 = xxtea_decrypt(
			(unsigned
		__int8 *)&v7[v9],
			v8 - v9,
			*(unsigned
		__int8 * *)(v5 + 36),
			*(_DWORD * )(v5 + 40),
			(unsigned int *) &v14);
		v12 = (void *) v11;
		if (*(_BYTE *) v11 == -17 && *(_BYTE * )(v11 + 1) == -69 && *(_BYTE * )(v11 + 2) == -65) {
			v12 = (void *) (v11 + 3);
			v14 -= 3;
		}
		v13 = j_luaL_loadbuffer(v6, v12, v14, a5);
		free(v12);
		result = v13;
	}
	else {
		if (*v7 == -17 && v7[1] == -69 && v7[2] == -65) {
			v7 += 3;
			v8 -= 3;
		}
		result = j_luaL_loadbuffer(v6, v7, v8, a5);
	}
	return result;
}