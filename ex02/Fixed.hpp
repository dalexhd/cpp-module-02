/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 15:46:45 by aborboll          #+#    #+#             */
/*   Updated: 2021/11/13 23:48:06 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Incluimos las librerias esenciales.
*/
#include <iostream>
#include <string.h>
#include <cmath>

class Fixed
{
	private:
		int number;
		static const int fractional_number;
	public:
		Fixed();
		~Fixed();
		Fixed(const int num);
		Fixed(const float num);
		Fixed(const Fixed &num);
		//Comparison operators
		bool operator>(const Fixed & num) const;
		bool operator<(const Fixed & num) const;
		bool operator>=(const Fixed & num) const;
		bool operator<=(const Fixed & num) const;
		bool operator==(const Fixed & num) const;
		bool operator!=(const Fixed & num) const;
		//Arithmetic operators
		Fixed &operator=(const Fixed & num);
		Fixed operator+(const Fixed & num);
		Fixed operator-(const Fixed & num);
		Fixed operator*(const Fixed & num);
		Fixed operator/(const Fixed & num);
		//Pre-increment, post-increment, pre-decrement and post-decrement operators
		Fixed operator++(const int num);
		Fixed operator--(const int num);
		Fixed & operator++();
		Fixed & operator--();
		static const Fixed &max(const Fixed &num, const Fixed &num2);
		static const Fixed &min(const Fixed &num, const Fixed &num2);
		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
};

std::ostream & operator<<(std::ostream & stream , const Fixed & num);
