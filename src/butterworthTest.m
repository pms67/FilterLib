% Desired cut-off frequency (Hz)
fc = 1;

% Sample rate (Hz)
fs = 100;

% Calculate sample time (s) and angular cut-off frequency (rad/s)
T = 1 / fs;
wc = 2 * pi * fc;

% Pre-warp cut-off frequency
wcd = (2 / T) * tan(pi * fc / fs);

% First order
wcT = wcd*T;
Ga1 = tf(1, [1/wc, 1]);
Gd1 = tf([wcT, wcT], [wcT+2, wcT-2], T);

% Second order
wcTsq = wcT * wcT;
Ga2 = tf(1, [1/wc^2, 1.4142/wc, 1]);
Gd2 = tf([wcTsq, 2*wcTsq, wcTsq], [4+2.8284*wcT+wcTsq,-8+2*wcTsq,4-2.8284*wcT+wcTsq], T);

% Third order
wcTcu = wcT * wcTsq;
Ga3 = tf(1, [1/wc^3, 2/wc^2, 2/wc, 1]);
Gd3 = tf([wcTcu, 3*wcTcu, 3*wcTcu, wcTcu], [8+8*wcT+4*wcTsq+wcTcu,-24-8*wcT+4*wcTsq+3*wcTcu,24-8*wcT-4*wcTsq+3*wcTcu,-8+8*wcT-4*wcTsq+wcTcu], T);

% Fourth order
wcTfo = wcTsq * wcTsq;
alpha = 2.6132;
beta  = 3.41430612;
Ga4 = tf(wc^4, [1, alpha*wc, beta*wc^2, alpha*wc^3, wc^4]);
Gd4 = tf([wcTfo, 4*wcTfo, 6*wcTfo, 4*wcTfo, wcTfo], [16+8*alpha*wcT+4*beta*wcTsq+2*alpha*wcTcu+wcTfo, ...
                                                     -64-16*alpha*wcT+4*alpha*wcTcu+4*wcTfo, ...
                                                     96-8*beta*wcTsq+6*wcTfo, ...
                                                     -64+16*alpha*wcT-4*alpha*wcTcu+4*wcTfo, ...
                                                     16-8*alpha*wcT+4*beta*wcTsq-2*alpha*wcTcu+wcTfo], T);