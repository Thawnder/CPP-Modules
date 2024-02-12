#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("Shrubbery Creation", 145, 137) {
	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;

}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("Shrubbery Creation", 145, 137) {
	std::cout << "ShrubberyCreationForm string constructor called" << std::endl;
	this->_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & base): AForm(base) {
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
	*this = base;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & base) {
	if (this != &base)
		(std::string) this->_target = base.getTarget();
	return *this;
}

std::string ShrubberyCreationForm::getTarget() const {
	return this->_target;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	if (executor.getGrade() > this->getExecGrade())
		throw GradeTooLowException();
	if (this->getState() == false)
		throw NotSignedException();

	std::fstream dest;

	char buf[this->getTarget().length() + 1];

	for (size_t i = 0; i < this->getTarget().length(); i++)
		buf[i] = this->getTarget()[i];
	buf[this->getTarget().length()] = 0;
	
	dest.open(std::strcat(buf, "_shrubbery"), std::fstream::out);
	if (!dest.is_open())
	{
		std::cerr << "dest open: failed" << std::endl;
		return ;
	}

	dest << "                                                 ." << std::endl;
	dest << "                                      .         ; " << std::endl; 
	dest << "         .              .              ;%     ;;   " << std::endl;
	dest << "           ,           ,                :;%  %;   " << std::endl;
	dest << "            :         ;                   :;%;'     .,   " << std::endl;
	dest << "   ,.        %;     %;            ;        %;'    ,;" << std::endl;
	dest << "     ;       ;%;  %%;        ,     %;    ;%;    ,%'" << std::endl;
	dest << "      %;       %;%;      ,  ;       %;  ;%;   ,%;' " << std::endl;
	dest << "       ;%;      %;        ;%;        % ;%;  ,%;'" << std::endl;
	dest << "        `%;.     ;%;     %;'         `;%%;.%;'" << std::endl;
	dest << "         `:;%.    ;%%. %@;        %; ;@%;%'" << std::endl;
	dest << "            `:%;.  :;bd%;          %;@%;'" << std::endl;
	dest << "              `@%:.  :;%.         ;@@%;'   " << std::endl;
	dest << "                `@%.  `;@%.      ;@@%;         " << std::endl;
	dest << "                  `@%%. `@%%    ;@@%;        " << std::endl;
	dest << "                    ;@%. :@%%  %@@%;       " << std::endl;
	dest << "                      %@bd%%%bd%%:;     " << std::endl;
	dest << "                        #@%%%%%:;;" << std::endl;
	dest << "                        %@@%%%::;" << std::endl;
	dest << "                        %@@@%(o);  . '         " << std::endl;
	dest << "                        %@@@o%;:(.,'         " << std::endl;
	dest << "                    `.. %@@@o%::;         " << std::endl;
	dest << "                       `)@@@o%::;         " << std::endl;
	dest << "                        %@@(o)::;        " << std::endl;
	dest << "                       .%@@@@%::;         " << std::endl;
	dest << "                       ;%@@@@%::;.          " << std::endl;
	dest << "                      ;%@@@@%%:;;;. " << std::endl;
	dest << "                  ...;%@@@@@%%:;;;;,..    " << std::endl;

	dest.close();
}