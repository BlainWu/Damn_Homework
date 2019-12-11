function varargout = Snack_GUI(varargin)
% SNACK_GUI MATLAB code for Snack_GUI.fig
%      SNACK_GUI, by itself, creates a new SNACK_GUI or raises the existing
%      singleton*.
%
%      H = SNACK_GUI returns the handle to a new SNACK_GUI or the handle to
%      the existing singleton*.
%
%      SNACK_GUI('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in SNACK_GUI.M with the given input arguments.
%
%      SNACK_GUI('Property','Value',...) creates a new SNACK_GUI or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before Snack_GUI_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to Snack_GUI_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help Snack_GUI

% Last Modified by GUIDE v2.5 10-Dec-2019 23:34:58

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @Snack_GUI_OpeningFcn, ...
                   'gui_OutputFcn',  @Snack_GUI_OutputFcn, ...
                   'gui_LayoutFcn',  [] , ...
                   'gui_Callback',   []);
if nargin && ischar(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end
% End initialization code - DO NOT EDIT
end

% --- Executes just before Snack_GUI is made visible.
function Snack_GUI_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to Snack_GUI (see VARARGIN)

% Choose default command line output for Snack_GUI
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);

% UIWAIT makes Snack_GUI wait for user response (see UIRESUME)
% uiwait(handles.figure1);

end
% --- Outputs from this function are returned to the command line.
function varargout = Snack_GUI_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;

end
% --- Executes on button press in pushbutton1.
function pushbutton1_Callback(hObject, eventdata, handles)
    count_time = 0;
    count = 3;
    snake.running = 1;
    snake.collision = 0;
    pause_time = 0;
    rad_bu1=get(handles.radiobutton1,'value');
    rad_bu2=get(handles.radiobutton2,'value');
    rad_bu3=get(handles.radiobutton3,'value');
    if rad_bu1 == 1
        pause_time=0.2;
    end
    if rad_bu2 ==1
        pause_time=0.1;
    end
    if  rad_bu3==1
        pause_time=0.03;
    end
    
    % 参数初始化，地图大小
    snake.xmax = 40;
    snake.ymax = 40;
    
    % 准备一个figure供游戏进行   
    snake.fig_hnd = figure('NumberTitle', 'off', 'Name', 'Matlab贪吃蛇小程序---南京师范大学 吴沛林');
    hold on;
    snake.plot_hnd = plot(0, 0, 'k.', 'MarkerSize', 15);            
    snake.plot_head_hnd = plot(0, 0, 'bo', 'MarkerSize', 8, 'LineWidth', 2);            

    % 初始化蛇的位置和方向，第一行为
    snake.segments = [snake.xmax/2   snake.ymax/2; ...
                      snake.xmax/2-1 snake.ymax/2; ...
                      snake.xmax/2-2 snake.ymax/2];
    snake.dir = 'E';

    % Allow data exchange from callback to GUI
    guidata(snake.fig_hnd, snake);
    % Initial drawing    
    init_figure(snake);    
    draw_snake(snake); 
    snake_loop(snake,pause_time,handles,count_time,count);
end
% hObject    handle to pushbutton1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in pushbutton2.
function pushbutton2_Callback(hObject, eventdata, handles)
close all
end
% hObject    handle to pushbutton2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
function snake_loop(snake,pause_time,handles,count_time,count)
    % The main loop
    while 1
        snake = guidata(snake.fig_hnd);  
        snake = forward(snake);
        draw_snake(snake);        
        
        %
        % Your AI here
        % Use turn_left, turn_right, and forward functions here
        % You can disable key_pressed_fcn callback function
        %
        count_time = count_time+1;
        if mod(count_time,5) ==3
            snake = increase(snake);
            count = count +1;
        end
        
        guidata(snake.fig_hnd, snake);
        pause(pause_time);
        set(handles.text4,"string",count);

        if snake.running == 0
            close;
        end
    end
    close all;
end

%%
function init_figure(snake)
    % 初始化figure
    set (gcf, 'keypressfcn', @(src,eventdata)key_pressed_fcn(src, eventdata));        
    xlim([0, snake.xmax]);
    ylim([0, snake.ymax]);
    title('Matlab贪吃蛇 v1.0')
end

%%
function draw_snake(snake)    
    set(snake.plot_hnd, 'XData', snake.segments(:,1));
    set(snake.plot_hnd, 'YData', snake.segments(:,2));
    
    set(snake.plot_head_hnd, 'XData', snake.segments(1,1));
    set(snake.plot_head_hnd, 'YData', snake.segments(1,2));
    
    if snake.collision == 1

        set(snake.plot_head_hnd, 'Color', 'r');
    else
        set(snake.plot_head_hnd, 'Color', 'g');
    end
end

%%
function snake = turn_left(snake)    
    snake.segments(2:end, :) = snake.segments(1:end-1, :);
    
    if snake.dir == 'E' % horizontal snake, face east
        snake.segments(1, :) = [snake.segments(1, 1) snake.segments(1, 2)+1];
        snake.dir = 'N';
    elseif snake.dir == 'W' % horizontal snake, face west
        snake.segments(1, :) = [snake.segments(1, 1) snake.segments(1, 2)-1];
        snake.dir = 'S';
    elseif snake.dir == 'N' % vertical snake, face north
        snake.segments(1, :) = [snake.segments(1, 1)-1 snake.segments(1, 2)];
        snake.dir = 'W';
    elseif snake.dir == 'S' % vertical snake, face south
        snake.segments(1, :) = [snake.segments(1, 1)+1 snake.segments(1, 2)];
        snake.dir = 'E';
    end        
end

%%
function snake = turn_right(snake)
    snake.segments(2:end, :) = snake.segments(1:end-1, :);
    
    if snake.dir == 'E' % horizontal snake, face east
        snake.segments(1, :) = [snake.segments(1, 1) snake.segments(1, 2)-1];
        snake.dir = 'S';
    elseif snake.dir == 'W' % horizontal snake, face west
        snake.segments(1, :) = [snake.segments(1, 1) snake.segments(1, 2)+1];
        snake.dir = 'N';
    elseif snake.dir == 'S' % vertical snake, face south
        snake.segments(1, :) = [snake.segments(1, 1)-1 snake.segments(1, 2)];
        snake.dir = 'W';
    elseif snake.dir == 'N' % vertical snake, face north
        snake.segments(1, :) = [snake.segments(1, 1)+1 snake.segments(1, 2)];
        snake.dir = 'E';
    end       
end

%%
function snake = forward(snake)
    v = snake.segments(1, :) - snake.segments(2, :);    
    
    % Toroidal grid
    if v(1,1) == -snake.xmax
        v(1,1) = 1;
    elseif v(1,1) == snake.xmax
        v(1,1) = -1;
    end
    
    if v(1,2) == -snake.ymax
        v(1,2) = 1;
    elseif v(1,2) == snake.ymax
        v(1,2) = -1;
    end
    
    % Shift the snake
    snake.segments(2:end, :) = snake.segments(1:end-1, :);
    snake.segments(1, :) = snake.segments(1, :) + v;
    
    % Toroidal grid again
    if snake.segments(1, 1) == snake.xmax + 1
        snake.segments(1, 1) = 0;
    elseif snake.segments(1, 1) == - 1
        snake.segments(1, 1) = snake.xmax;
    end
    
    if snake.segments(1, 2) == snake.ymax + 1
        snake.segments(1, 2) = 0;
    elseif snake.segments(1, 2) == - 1
        snake.segments(1, 2) = snake.ymax;
    end
    
    snake = check_collision(snake);
end

%%
function snake = check_collision(snake)
    snake.collision = 0;
    r = sum(snake.segments(2:end, 1) == snake.segments(1, 1) & snake.segments(2:end, 2) == snake.segments(1, 2));
    if r > 0
        snake.collision = 1;
        errordlg('真不小心，再接再厉！','YOU GO DIE');
        pause(3);
        snake.running = 0;
        
    end
end

%%
function snake = increase(snake)
    v = snake.segments(end, :) - snake.segments(end-1, :);    
    
     % Toroidal grid
    if v(1,1) == -snake.xmax
        v(1,1) = 1;
    elseif v(1,1) == snake.xmax
        v(1,1) = -1;
    end
    
    if v(1,2) == -snake.ymax
        v(1,2) = 1;
    elseif v(1,2) == snake.ymax
        v(1,2) = -1;
    end
    
    % Increase the length by 1 segment
    snake.segments(end+1,:) = snake.segments(end,:) + v;
    
    % Toroidal grid again
    if snake.segments(end,1) == snake.xmax + 1
        snake.segments(end, 1) = 0;
    elseif snake.segments(end, 1) == - 1
        snake.segments(end, 1) = snake.xmax;    
    end
    
    if snake.segments(end, 2) == snake.ymax + 1
        snake.segments(end, 2) = 0;
    elseif snake.segments(end, 2) == - 1
        snake.segments(end, 2) = snake.ymax;    
    end
end

%%
function [] = key_pressed_fcn(H, E)  
    snake = guidata(H);
    % Figure keypressfcn    
    switch E.Key
        case 'rightarrow'
            if (snake.dir == 'N')                
                snake = turn_right(snake);                
            elseif (snake.dir == 'S')                
                snake = turn_left(snake);                
            elseif (snake.dir == 'E')
                snake = forward(snake);
            end                        
            
        case 'leftarrow'
            if (snake.dir == 'N')                
                snake = turn_left(snake);                
            elseif (snake.dir == 'S')                
                snake = turn_right(snake);               
            elseif (snake.dir == 'W')
                snake = forward(snake);
            end            
            
        case 'uparrow'
            if (snake.dir == 'E')                
                snake = turn_left(snake);                
            elseif (snake.dir == 'W')                
                snake = turn_right(snake);                
            elseif (snake.dir == 'N')
                snake = forward(snake);
            end            
            
        case 'downarrow'            
            if (snake.dir == 'E')                
                snake = turn_right(snake);                
            elseif (snake.dir == 'W')                
                snake = turn_left(snake);            
            elseif (snake.dir == 'S')
                snake = forward(snake);
            end            
            
        case 'space'
            snake = increase(snake);            
                        
        case 'escape'        
            snake.running = 0;
            disp('再见！');            
            
        otherwise              
    end
    
    snake = check_collision(snake);
    guidata(snake.fig_hnd, snake);  
    draw_snake(snake); 
end
