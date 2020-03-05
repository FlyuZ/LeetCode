class FooBar {
    private int n;
    public Semaphore seam_one_second = new Semaphore(0);
    public Semaphore seam_two_second = new Semaphore(0);
    public FooBar(int n) {
        this.n = n;
    }

    public void foo(Runnable printFoo) throws InterruptedException {

        for (int i = 0; i < n; i++) {
            seam_one_second.acquire();

            // printFoo.run() outputs "foo". Do not change or remove this line.
            printFoo.run();
            seam_two_second.release();
        }
    }

    public void bar(Runnable printBar) throws InterruptedException {

        for (int i = 0; i < n; i++) {
            seam_two_second.acquire();
            // printBar.run() outputs "bar". Do not change or remove this line.
            printBar.run();
            seam_one_second.release();
        }
    }
}