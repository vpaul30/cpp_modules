#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("ShrubberyCreationForm", 145, 137), _target("default")
{
	std::cout << "ShrubberyCreationForm default constructor called.\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << "ShrubberyCreationForm constructor called.\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
	: AForm(other), _target(other._target)
{
	std::cout << "ShrubberyCreationForm copy constructor called.\n";
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	std::cout << "ShrubberyCreationForm assignment operator called.\n";
	_target = other._target;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called.\n";
}

void ShrubberyCreationForm::executeAction() const
{
	std::ofstream outfile;

	outfile.open((_target + "_shrubbery").c_str());
	if (!outfile.good())
	{
		std::cout << "Couldn't create or write to new file " << _target << std::endl;
		return;
	}
	outfile <<
    "                                          .         ;\n" <<
    "             .              .              ;%     ;;   \n" <<
    "               ,           ,                :;%  %;   \n" <<
    "                :         ;                   :;%;'     .,   \n" <<
    "       ,.        %;     %;            ;        %;'    ,;\n" <<
    "         ;       ;%;  %%;        ,     %;    ;%;    ,%'\n" <<
    "          %;       %;%;      ,  ;       %;  ;%;   ,%;' \n" <<
    "          ;%;      %;        ;%;        % ;%;  ,%;'\n" <<
    "           `%;.     ;%;     %;'         `;%%;.%;'\n" <<
    "            `:;%.    ;%%. %@;        %; ;@%;%'\n" <<
    "               `:%;.  :;bd%;          %;@%;'\n" <<
    "                 `@%:.  :;%.         ;@@%;'   \n" <<
    "                   `@%.  `;@%.      ;@@%;         \n" <<
    "                      `@%%. `@%%    ;@@%;        \n" <<
    "                        ;@%. :@%%  %@@%;       \n" <<
    "                          %@bd%%%bd%%:;     \n" <<
    "                            #@%%%%%:;;\n" <<
    "                            %@@%%%::;\n" <<
    "                            %@@@%(o);  . '         \n" <<
    "                            %@@@o%;:(.,'         \n" <<
    "                        `.. %@@@o%::;         \n" <<
    "                           `)@@@o%::;         \n" <<
    "                            %@@(o)::;        \n" <<
    "                           .%@@@@%::;         \n" <<
    "                           ;%@@@@%::;.          \n" <<
    "                          ;%@@@@%%:;;;. \n" <<
    "                      ...;%@@@@@%%:;;;;,..\n";

		outfile.close();
}