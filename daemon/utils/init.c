/*
This file is part of edda.

edda is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

edda is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with edda.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "../daemon.h"

int main(int argc, char *argv[]) 
{ 
  RSA *rsa  = RSA_new();

  if (argc < 2)
  {
    printf("usage: %s <PEM_Datei>\n",argv[0]);
    return;
  }

  FILE *fp = fopen(argv[1], "r");

  if (!fp)
  {
    printf("\n%s\n","Error beim datei öffnen");
    return;
  }

  if(PEM_read_RSAPrivateKey(fp, &rsa, NULL, NULL) == NULL)
  {
    printf("\n%s\n", "Error Reading private key");
    return;
  }

  fclose(fp);

  writeRSA(rsa);
}
