#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat;

class AForm 
{
private:
	const std::string _name;
	bool _isSigned;
	const int _signGrade;
	const int _execGrade;

public:
	AForm(const std::string& name, int signGrade, int execGrade);
	AForm(const AForm& other);
	AForm& operator=(const AForm& other);
	virtual ~AForm();

	const std::string& getName() const;
	bool isSigned() const;
	int getSignGrade() const;
	int getExecGrade() const;

	void beSigned(const Bureaucrat& b);
	void checkExecution(const Bureaucrat& executor) const;

	virtual void execute(const Bureaucrat& executor) const = 0;

	class GradeTooHighException : public std::exception {
	public:
		const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		const char* what() const throw();
	};

	class NotSignedException : public std::exception {
	public:
		const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif

