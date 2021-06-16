#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include<vector>
#include "loadFile.h"

namespace EncryptionNamespace {
	class Encryption {
		private:
			LoadFile loadFile;
		public:
			Encryption();
			void run();
			std::vector<std::string> breakUpString(std::string input);
			int encryptOrDecrypt(int input, int e, int n);
			int recursiveSquaringWithModding(int input, int e, int n);
	};
}