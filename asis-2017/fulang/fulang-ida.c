signed int __cdecl fu_interpreter(char a1, char a2)
{
  _BYTE *fu_current; // ebx@13
  char xor_current; // dl@15
  signed int result; // eax@20

  if ( a1 == ':' )
  {
    if ( a2 == '<' )
      --fu;
    if ( a2 == '>' )
      ++fu;
    if ( a2 == '+' )
      ++*(_BYTE *)fu;
    if ( a2 == '-' )
      --*(_BYTE *)fu;
    if ( a2 == ':' )
      putchar(*(_BYTE *)fu);
    if ( a2 == '.' )
    {
      fu_current = (_BYTE *)fu;
      *fu_current = getchar();
    }
    if ( a2 == '_' )
    {
      xor_current = (*(_BYTE *)fu)++;
      *(_BYTE *)fu ^= xor_current;
    }
    if ( a2 == '(' )
      puts("Not implemented yet!");
    if ( a2 == ')' )
      puts("Not implemented yet!");
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}


int __cdecl main(int argc, const char **argv, const char **envp)
{
  int result; // eax@6
  int v4; // edi@6
  signed __int32 i; // [sp+10h] [bp-DCh]@1
  signed __int32 len_buf; // [sp+14h] [bp-D8h]@1
  char buffer[4]; // [sp+18h] [bp-D4h]@1
  char v8; // [sp+1Ch] [bp-D0h]@1
  int v9; // [sp+E0h] [bp-Ch]@1
  int *v10; // [sp+E8h] [bp-4h]@1

  v10 = &argc;
  v9 = *MK_FP(__GS__, 20);
  *(_DWORD *)buffer = 0;
  memset(&v8, 0, 0xC4u);
  fu = (int)&data;
  setvbuf(stdout, 0, 2, 0);
  setvbuf(stdin, 0, 2, 0);
  printf("%s", "[Fulang service]\nEnter your code:");
  fgets(buffer, 150, stdin);
  len_buf = strlen(buffer);
  // read 2 chars on each iteration
  for ( i = 0; i < len_buf; i += 2 )
  {
    if ( !fu_interpreter(buffer[i], buffer[i + 1]) )
    {
      puts("Incorrect syntax, RTFM!");
      break;
    }
  }
  result = 0;
  v4 = *MK_FP(__GS__, 20) ^ v9;
  return result;
}
