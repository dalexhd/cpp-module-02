/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 15:46:45 by aborboll          #+#    #+#             */
/*   Updated: 2021/11/13 16:25:38 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Incluimos las librerias esenciales.
*/
#include <iostream>
#include <string.h>

class Fixed
{
	private:
		int number;
		static const int fractional_number;
	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed &num);
		Fixed & operator=(const Fixed & num);
		int getRawBits(void) const;
		void setRawBits(int const raw);
};
