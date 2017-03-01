//
// Created by kirill on 27.02.17.
//

#include <queue>
#include <fstream>
#include "fifo.h"
#include "job.h"
#include "event.h"

fifo::fifo(int seconds_per_page) : simulator(seconds_per_page)
{}


void fifo::simulate(string file_name)
{
    // load workload
    //
    loadworkload(file_name);
    queue<event> wait_queue;

    // open file and write first lines
    //
    ofstream out_file(file_name.substr(0, file_name.size() - 4) + ".out");
    out_file << "FIFO Simulation" << endl;
    out_file << endl;

    // init needed variables
    //
    int time = 0, time_buff = 0, agg_latency = 0, total_jobs = 0;

    while (workload.size() > 0 || wait_queue.size() > 0)
    {
        // to ensure we work with one task
        //
        while (time == workload.front().arrival_time())
        {
            event event = workload.front();
            ++total_jobs;
            wait_queue.push(event);
            std::string page_s = "page";
            if (event.getjob().getnumpages() > 1)
                page_s = "pages";


            // print a line
            //
            out_file << "      Arriving: ";
            out_file << event.getjob().getnumpages() << " " << page_s + " from " << event.getjob().getuser() << " at "
                     << event.arrival_time() << " seconds" << endl;
            workload.pop();
        }
        if (wait_queue.size() > 0 && time_buff == 0)
        {
            event event = wait_queue.front();
            std::string page_s = "page";
            if (event.getjob().getnumpages() > 1)
                page_s = "pages";


            // print a line
            //
            out_file << "      Servicing: ";
            out_file << event.getjob().getnumpages() << " " << page_s + " from " << event.getjob().getuser() << " at "
                     << time << " seconds" << endl;

            // init the tine we work
            //
            time_buff = event.getjob().getnumpages() * seconds_per_page;

            // increment aggregate latency
            //
            agg_latency += time - event.arrival_time();
            wait_queue.pop();
        }
        //
        if (time_buff > 0)
            --time_buff;

        ++time;
    }
    out_file << endl << "      Total jobs: " << total_jobs << endl << "      Aggregate latency: " << agg_latency
             << " seconds" << endl <<
             "      Mean latency: " << agg_latency / (double) total_jobs << " seconds" << endl;

    // close file
    out_file.close();
    return;
}
