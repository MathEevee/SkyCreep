#ifndef FILE_HPP
# define FILE_HPP

# include "item.hpp"
# include <vector>
# include <iostream>

class File
{
	private:
		std::vector<std::string> _all_line;
	public:
		File(std::string all_file);
		File(const File &obj);
		~File();

		File& operator=(const File& obj);

		std::string					getLine(void);
		std::vector<std::string>&	getAllLine(void);

		void	setAllLine(std::string file);
};



#endif