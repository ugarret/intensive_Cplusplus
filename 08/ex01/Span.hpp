#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <algorithm> //need for abs
# include <vector>

class Span
{
	private:
		unsigned int		_size;
		std::vector<int>	_elements;

	public:
		Span(unsigned int N);
		Span(Span const &other);
		Span &operator=(Span const &other);
		~Span();

		unsigned int		get_size() const;
		std::vector<int>	get_elements() const;
		int					operator[](unsigned int index) const;

		void 			addNumber(int n);
		void			addArrNumber(std::vector<int>::iterator start, std::vector<int>::iterator finish);
		int				shortestSpan();
		int				longestSpan();

	class SomethingWentWrong: public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
};

#endif
