/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lylrandr <lylrandr@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 16:50:40 by lylrandr          #+#    #+#             */
/*   Updated: 2025/08/20 16:50:41 by lylrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef __APPLE__   // macOS
# define KEY_ESC   53
# define KEY_W     13
# define KEY_A     0
# define KEY_S     1
# define KEY_D     2
# define KEY_LEFT  123
# define KEY_RIGHT 124
# define KEY_UP    126
# define KEY_DOWN  125
#else              // Linux (X11)
# define KEY_ESC   65307
# define KEY_W     119
# define KEY_A     97
# define KEY_S     115
# define KEY_D     100
# define KEY_LEFT  65361
# define KEY_RIGHT 65363
# define KEY_UP    65362
# define KEY_DOWN  65364
#endif
