/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadinc <sdinc763@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 18:23:16 by sadinc            #+#    #+#             */
/*   Updated: 2025/02/23 17:51:28 by sadinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdlib.h>

size_t	ft_strlen(char *str);
size_t	ft_get_strlen(char *str);
int		ft_newline_check(char *str);
char	*get_next_line(int fd);
char	*ft_get_strjoin(char *buffer, char *tmp);

#endif
