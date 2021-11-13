/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 15:56:04 by aborboll          #+#    #+#             */
/*   Updated: 2021/11/13 21:16:46 by aborboll         ###   ########.fr       */
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

Fixed & Fixed::operator=(const Fixed & num)
{
	std::cout << "Assignation operator called" << std::endl;
	this->setRawBits(num.getRawBits());
	return (*this);
}

std::ostream & operator<<(std::ostream & stream , const Fixed & num)
{
	stream << num.toFloat();
	return stream;
}

float	Fixed::getRawBits(void) const
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
