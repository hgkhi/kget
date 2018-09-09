# Architecture

<u>Version: 1</u>

## Components

### Overview

#### Manager

Roles:

* Receives URL
* Validates if server supports Content-Range
* Plans the jobs: divide the content range, download resumption...
* Command workers to do the planned jobs
* Receives progress from worker
* Periodically report progress (i.e download percentage)

#### Worker

Roles:

- Receives command from manager
- Executes the job based on the plan: downloads entirely or part of resource, resumes downloading...
- Reports the progress to manager

### Details

#### Worker

Tasks:

- Receives URL and number of workers from constructor
- Validates that URL
- Divides the file into smaller chunks and assigns to workers

## Validation

### URL

- Get metadata only (HEAD request in HTTP)
- Questions:
  - Can we get the response?
  - Does it support partial request?