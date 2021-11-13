/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 15:56:04 by aborboll          #+#    #+#             */
/*   Updated: 2021/11/13 23:48:40 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::fractional_number = 8;

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->setRawBits(0);
}

Fixed::Fixed(const int num)
{
	std::cout << "Int constructor called" << std::endl;
	this->setRawBits(num << this->fractional_number);
}

Fixed::Fixed(const float num)
{
	std::cout << "Float constructor called" << std::endl;
	this->setRawBits((int)roundf(num * (1 << this->fractional_number)));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &num)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = num;
}

int	Fixed::getRawBits(void) const
{
	return (this->number);
}

void	Fixed::setRawBits(int const raw)
{
	this->number = raw;
}

int		Fixed::toInt(void) const
{
	return (this->number >> this->fractional_number);
}

float	Fixed::toFloat(void) const
{
	return (this->number / (float)(1 << this->fractional_number));
}

// Equal operator
Fixed & Fixed::operator=(const Fixed & num)
{
	std::cout << "Assignation operator called" << std::endl;
	this->setRawBits(num.getRawBits());
	return (*this);
}

//Comparison operators
bool Fixed::operator>(const Fixed & num) const
{
	return (this->getRawBits() > num.getRawBits());
}

bool Fixed::operator<(const Fixed & num) const
{
	return (this->getRawBits() < num.getRawBits());
}

bool Fixed::operator>=(const Fixed & num) const
{
	return (this->getRawBits() >= num.getRawBits());

}

bool Fixed::operator<=(const Fixed & num) const
{
	return (this->getRawBits() <= num.getRawBits());
}

bool Fixed::operator==(const Fixed & num) const
{
	return (this->getRawBits() == num.getRawBits());
}

bool Fixed::operator!=(const Fixed & num) const
{
	return (this->getRawBits() != num.getRawBits());
}

//Arithmetic operators
Fixed Fixed::operator+(const Fixed & num)
{
	return (this->toFloat() + num.toFloat());
}

Fixed Fixed::operator-(const Fixed & num)
{
	return (this->toFloat() - num.toFloat());
}

Fixed Fixed::operator*(const Fixed & num)
{
	return (this->toFloat() * num.toFloat());
}

Fixed Fixed::operator/(const Fixed & num)
{
	return (this->toFloat() / num.toFloat());
}

//Pre-increment, post-increment, pre-decrement and post-decrement operators
Fixed Fixed::operator++(int)
{
	Fixed val(*this);

	this->number++;
	return (val);
}

Fixed Fixed::operator--(int)
{
	Fixed val(*this);

	this->number--;
	return (val);
}

Fixed & Fixed::operator++()
{
	this->number++;
	return (*this);
}

Fixed & Fixed::operator--()
{
	this->number--;
	return (*this);
}

Fixed const &Fixed::max(const Fixed &num, const Fixed &num2)
{
	if (num > num2)
		return (num);
	else
		return (num2);
}

Fixed const &Fixed::min(const Fixed &num, const Fixed &num2)
{
	if (num < num2)
		return (num);
	else
		return (num2);
}

// Stream out operator
std::ostream & operator<<(std::ostream & stream , const Fixed & num)
{
	stream << num.toFloat();
	return stream;
}
