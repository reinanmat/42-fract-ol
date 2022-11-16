/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 18:35:44 by revieira          #+#    #+#             */
/*   Updated: 2022/11/16 14:17:12 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractal.h"

int handle_no_event(void *data)
{
    (void)data;
    return (0);
}

int handle_input(int key, t_data *data)
{
    if (key == 65307)
        mlx_destroy_window(data->mlx_ptr, data->win_ptr);
    printf("%d\n", key);
    return (0);
}

int main(void)
{
    t_data  data;

    data.mlx_ptr = mlx_init();
    if (!data.mlx_ptr)
        return (-1);
    data.win_ptr = mlx_new_window(data.mlx_ptr, 800, 800, "fract-ol");
    if (!data.win_ptr)
    {
        free(data.win_ptr);
        return (-1);
    }
    mlx_loop_hook(data.mlx_ptr, &handle_no_event, &data);
    mlx_key_hook(data.win_ptr, &handle_input, &data);
    mlx_loop(data.mlx_ptr);
    mlx_destroy_display(data.mlx_ptr);
    free(data.mlx_ptr);
    return (0);
}
