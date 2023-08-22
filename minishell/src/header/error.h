/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalenti <svalenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 14:08:13 by plpelleg          #+#    #+#             */
/*   Updated: 2021/05/05 14:51:57 by svalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
This header file contains all macros for errors to be displayed.
*/

#ifndef ERROR_H
# define ERROR_H

# include <stdio.h>
# include <errno.h>

# define END "THE END"
# define FILE_NOT_FOUND "FILE NOT FOUND\n"
# define DOUBLE_PAR "PARAMETER DEFINED TWICE\n"
# define NEG_NUM "NEGATIVE PARAMETER\n"
# define MALLOC_FAIL "FAILED TO ALLOCATE MEMORY\n"
# define BAD_PAR "BAD PARAMETER\n"

#endif