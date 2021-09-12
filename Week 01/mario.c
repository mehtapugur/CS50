int main(void)
{
    int n;
    do
    {
        n = get_int("%s", "Height: ");
    } while (n < 1 || n > 8);
    
    printf("%i\n", n);

     for (int i = 0; i < n; i++)
  {
      for (int j = 0 ; j < (n-i-1); j++)
      {
          printf(" ");
      }
      for (int j = (n-i-1); j < n; j++)
      {
          printf("#");
      }
      printf("\n");
  }
}
