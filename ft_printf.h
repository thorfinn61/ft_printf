/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsahin <elsahin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 16:36:11 by Elyesa1           #+#    #+#             */
/*   Updated: 2025/11/10 12:20:22 by elsahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

size_t	ft_strlen(const char *s);
int		ft_printf(const char *format, ...);
void	ft_putchar_fd(char c, int fd, int *count);
void	ft_putstr_fd(char *s, int fd, int *count);
void	ft_putnbr_fd(int n, int fd, int *count);
void	ft_putnbr_base_ul(unsigned long n, char *base, int *count);

#endif
