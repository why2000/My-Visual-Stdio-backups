'use strict';

function _classCallCheck(instance, Constructor) { if (!(instance instanceof Constructor)) { throw new TypeError("Cannot call a class as a function"); } }

// *********************************
// * Set up
// *********************************

// Select Canvas
var canvas = document.getElementById('canvas');//获取html文件中的canvas元素
// Get Canvas's context
var context = canvas.getContext('2d');//这里只能是2d，表示2d绘图（此函数目前不支持3d）

// Make width and height equal to tha of the browser window
//屏幕宽高获取
var width = canvas.width = window.innerWidth;
var height = canvas.height = window.innerHeight;

// Placeholder for mouse co-ords
var mouseX = undefined;
var mouseY = undefined;

// *********************************
// * Utility Functions
// *********************************

// Get random number between min and max, inclusive
function randomNumber(min, max) {
    return Math.floor(Math.random() * (max - min + 1)) + min;
}

// Generates a specified color
function color(hue, sat, light, alpha) {
    return 'hsla(' + hue + ', ' + sat + '%, ' + light + '%, ' + alpha + ')';
}

// Creates fade effect on canvas
function colorFade(alpha) {
    context.globalCompositeOperation = 'source-over';
    context.fillStyle = color(0, 0, 0, alpha);
    context.fillRect(0, 0, width, height);
    context.globalCompositeOperation = 'lighter';
}

// *********************************
// * Particle Class
// *********************************

var Particle = function () {
    function Particle() {
        _classCallCheck(this, Particle);

        this.reset();
    }

    Particle.prototype.render = function render() {
        // Begin stroke
        context.beginPath();
        // Draw circular particle
        context.arc(this.x, this.y, this.radius, 0, 2 * Math.PI, false);
        // Set fill and stroke colors
        var col = color(this.x / width * 360, 80, 50, 0.5);
        context.fillStyle = col;
        context.strokeStyle = col;
        // Apply fill and stroke colors
        context.fill();
        //context.stroke();
        // reset values if particle outside of screen
        if (this.x > width || this.x < 0 || this.y > height || this.y < 0) {
            this.reset();
        }
    };

    Particle.prototype.update = function update() {
        this.x += this.vx;
        this.y += this.vy;
    };

    // Reset values to original state

    Particle.prototype.reset = function reset() {
        // Position of x axis
        this.x = Math.random() * width;
        // Position on y axis
        this.y = Math.random() * height;
        // stands for velocity of x and velocity of y
        this.vx = 0;
        this.vy = 0;
        // Set radius to random number for varying sized particles
        this.radius = randomNumber(1, 6);
        // Mass for gravity pull
        this.mass = this.radius / 3;
    };

    // Define as static so it can be called without creating an instance of the particle

    Particle.createArray = function createArray(numberOf) {
        // Placeholder for particles
        var array = [];
        // Create as many as given in the argument
        while (numberOf--) {
            // Push new particle to the array
            array.push(new Particle());
        }
        // return the populated array
        return array;
    };

    return Particle;
}();

// Create array of particles
//创建粒子数组
var particleArr = Particle.createArray(70);
//计算粒子在引力作用下的运动参数
function gravitate(partA, partB) {
    //距离
    var dx = partB.x - partA.x;
    var dy = partB.y - partA.y;
    var distSQ = dx * dx + dy * dy;
    var dist = Math.sqrt(distSQ) + 40;
    //拉力
    var force = partA.mass * partB.mass / distSQ;
    //加速度
    var ax = force * dx / dist * 2;
    var ay = force * dy / dist * 2;
    //速度
    partA.vx += ax / partA.mass;
    partA.vy += ay / partA.mass;
    partB.vx -= ax / partB.mass;
    partB.vy -= ay / partB.mass;
}
//计算单位时间下的粒子位置改变
function move(partA, index) {
    //绝对坐标改变
    partA.x += partA.vx + 2;
    partA.y += partA.vy + 2;
    //
    var pullX = mouseX ? mouseX + partA.radius : 0;
    var pullY = mouseY ? mouseY + partA.radius : 0;
    var mass = mouseY ? 9 : 2;

    for (var partB, k = index + 1; k < particleArr.length; k++) {
        partB = {
            x: pullX,
            y: pullY,
            mass: mass
        };
        gravitate(partA, partB);
    }
}

context.fillStyle = '#222';
context.fillRect(0, 0, width, height);

// Self calling function
(function draw() {
    // Continuosly calls itself to create animation frames
    window.requestAnimationFrame(draw);
    // Apply color fade to create nice vis effect
    colorFade(0.07);

    particleArr.forEach(function (_, index) {
        move(_, index);
        // _.update();
        _.render();
    });
})();

//事件监视器
//窗口大小改变事件
window.addEventListener('resize', function () {
    // Update width and height of canvas on resize
    width = canvas.width = window.innerWidth;
    height = canvas.height = window.innerHeight;
    // Reset particle array to update width and height
    context.fillStyle = '#222';
    context.fillRect(0, 0, width, height);

    particleArr = Particle.createArray(50);
});

//鼠标移动事件
window.addEventListener('mousemove', function (e) {
    mouseX = e.pageX;
    mouseY = e.pageY;
});